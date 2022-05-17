#include <iostream>
#include <map>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
#include <cmath>
#include <list>

using namespace std;
// Para simplificar la declaración de iteradores
typedef map<unsigned char,double> Mapa;
typedef map<double, unsigned char> MapaS;
typedef map<string, unsigned char> MapaCod;
typedef multimap<double, unsigned char> MultiMapS;

struct simbolos{
  unsigned char sim;
  double prob;
  string cod;
  simbolos *next;
  simbolos *prev;
};
typedef struct simbolos nodo;

void printList(nodo *L){
	nodo *p = L;
	while(p != nullptr){
		cout << p->sim <<" : "<< p->prob<<'\n';
		p = p->next;
	}
	cout << "NULL" << endl;
}

MultiMapS Mapeo(string frase){
  Mapa contador;
  MultiMapS final;
  double largoFrase = frase.length();

  for( size_t i=0; i<frase.size(); ++i){
    contador[frase[i]]++;
  }

  for(Mapa::const_iterator it=contador.begin();it!=contador.end();++it){
    double probLetra = it->second/largoFrase;
    final.insert(pair<double, unsigned char>(probLetra *-1, it->first));
  }
  return final;
}

int partition(nodo *L, int part, double sumaA, double sumaB, int largo){
  double dif = sumaA - sumaB;
  if (sumaA >= sumaB){
    //Empieza la suma
    nodo *p = L;
    sumaA = 0;
    sumaB = 0;
    for(int i = 0; i < part; i++){ //Suma la primera parte
      sumaA += p->prob;
      //cout << "A" << abs(it->first) << " - "<< it->second << endl;
      p = p->next;
    }
    for (int i = part+1; i < largo; i++){ //suma la segunda parte
      sumaB += p->prob;
     //cout << "B" << abs(it->first) << " - "<< it->second << endl;
      p = p->next;
    }
    //cout << "SumaA = " << sumaA << " " << "SumaB = " << sumaB << endl;
    if (sumaA == sumaB || sumaA < sumaB) {
      cout << "Minma diferencia : " << dif << "En la posicion p : " << part << endl;
      return part;
    }
    return partition(L, part-1, sumaA, sumaB, largo);
  } 
  return part;
}

void shannonFanon(int in, int f, nodo *L){
  if ((in+1) == f || in == f || in > f){
    if (in == f || in > f) return;
    nodo *p = L;
    p->cod = "1";
    p = p->next;
    p->cod = "0";
    return;
  }
  else{
    int part = partition(L, (f+1)/2, 0, 0, f+1);
    nodo *p = L;
    for (int i = in; i <= part; i++){
      p->cod = p->cod +"1";
      p = p->next;
    }
    for (int i = part +1; i <= f; i++){
      p->cod = p->cod +"0";
      p = p->next;
    }
    shannonFanon(in, part, L);
    shannonFanon(part +1, f, L);
  }
  printList(L);
}

void appendToList(nodo **L,unsigned char sim,double prob){
  nodo *nuevo = new nodo;
	nuevo->prob = prob;
	nuevo->sim = sim;
  nuevo->next = NULL;
  nuevo->prev=NULL;

	if(*L == nullptr)
		*L = nuevo;
	else{
		nodo *q=*L;
		while(q->next != nullptr)
			q=q->next;
		q->next=nuevo;
    nuevo->prev=q;
	}
}



nodo* MapToList(MultiMapS m){
  nodo *L =NULL;

  for(MultiMapS::const_iterator it=m.begin();it!=m.end();++it){
    appendToList(&L,it->second,abs(it->first));
  }
  //printList(L);
  return L;
}



int main(int argc, char **argv){
	/*
  if(argc != 2){
		cout << "Error. Debe ejecutarse como ./Caracteres n" << endl;
		exit(EXIT_FAILURE);
	} 
	string x= argv[1];
  cout<< x <<"/n";
  */
  string nombreArchivo = "dna.100MB";
  ifstream archivo(nombreArchivo.c_str());

  string linea;
  string frasexd;
  int largoFrase = 0;

  while (getline(archivo, linea)){
    frasexd+=linea;
  } 
  MultiMapS simbolos=Mapeo(frasexd);
  nodo *L = MapToList(simbolos);
  shannonFanon(0, simbolos.size() -1, L);
  //int p = partition(L, simbolos.size()/2, 0, 0, simbolos.size());
  printList(L);
  return 0;
}