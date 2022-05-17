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

int partition(MultiMapS simbolos, int p, double sumaA, double sumaB){
  double dif = sumaA - sumaB;
  if (sumaA >= sumaB){
    //Empieza la suma
    MapaS::const_iterator it=simbolos.begin();
    sumaA = 0;
    sumaB = 0;
    for(int i = 0; i < p; i++){ //Suma la primera parte
      sumaA += abs(it->first);
      //cout << "A" << abs(it->first) << " - "<< it->second << endl;
      ++it;
    }
    for (int i = p+1; i < simbolos.size(); i++){ //suma la segunda parte
      sumaB += abs(it->first);
     //cout << "B" << abs(it->first) << " - "<< it->second << endl;
      ++it;
    }
    //cout << "SumaA = " << sumaA << " " << "SumaB = " << sumaB << endl;
    if (sumaA = sumaB || sumaA < sumaB) {
      cout << "Minma diferencia : " << dif << "En la posicion p : " << p << endl;
      return p;
    }
    return partition(simbolos, p-1, sumaA, sumaB);
  } 
  return p;
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

void printList(nodo *L){
	nodo *p = L;
	while(p != nullptr){
		cout << p->sim <<" : "<< p->prob<<'\n';
		p = p->next;
	}
	cout << "NULL" << endl;
}

void MapToList(MultiMapS m){
  nodo *L =NULL;

  for(MultiMapS::const_iterator it=m.begin();it!=m.end();++it){
    appendToList(&L,it->second,abs(it->first));
  }
  printList(L);
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

  while (getline(archivo, linea)){
    frasexd+=linea;
  } 
  MultiMapS simbolos=Mapeo(frasexd);
  MapToList(simbolos);
  //int p = partition(simbolos, simbolos.size()/2, 0, 0);
  return 0;
}