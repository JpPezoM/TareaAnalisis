#include <iostream>
#include <map>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cmath>
#include <list>

using namespace std;
// Para simplificar la declaración de iteradores
typedef map<unsigned char,double> Mapa;
typedef map<double, unsigned char> MapaS;
typedef map<string, unsigned char> MapaCod;
typedef multimap<double, unsigned char> MultiMapS;

struct node{
  unsigned char simbolo;
  string code;
  double prob;
};
typedef struct node node;


/*void PrintMap(Map& m)
{
    cout << "[ ";
    for (auto &item : m) {
        cout << item.first << ":" << item.second << " " << '\n';
    }
    cout << "]\n";
}*/


MultiMapS Mapeo(string frase){
  Mapa contador;
  MultiMapS final;

  double largoFrase = frase.length();

  for( size_t i=0; i<frase.size(); ++i)
    contador[frase[i]]++;

  int cont = 0;
  for(Mapa::const_iterator it=contador.begin();it!=contador.end();++it){
    double probLetra = it->second/largoFrase;
    final.insert(pair<double, unsigned char>(probLetra *-1, it->first));
  }
  //PrintMap(final);
  //cout << contador.size() << endl;
  //cout << final.size() << endl;
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
void MapToList(MapaS m){
  list<node*> ListaSimbolos;
  node* aux;
  aux->code="";
  aux->prob=0;
  aux->simbolo=NULL;

  for(MapaS::const_iterator it=m.begin();it!=m.end();++it){
    aux->prob=it->first;
    aux->simbolo=it->second;
    ListaSimbolos.push_back(aux);
  }

}
/*void shannonfanon(MapaS simbolos, MapaCod mapaCodificado1, MapaCod mapaCodificado2){
  if (simbolos.empty()) return; //Retorna si no hay ningun valor en el mapa

  if (mapaCodificado1.size() == 1 || mapaCodificado2.size() == 1){
    return;
  }
  else{
      int p = partition(simbolos, simbolos.size()/2, 0, 0); //Se lama a la funcion que calcula la minima diferencia
      for (int i = 0; i = p; i++){

      }
      for (int i = p; i < mapaCodificado1.size(); i++){
        
      }
      
  }
}*/
int main(int argc, char **argv){
	/*
  if(argc != 2){
		cout << "Error. Debe ejecutarse como ./Caracteres n" << endl;
		exit(EXIT_FAILURE);
	} 
	string x= argv[1];
  cout<< x <<"/n";
  */
  string nombreArchivo = "english.100MB";
  ifstream archivo(nombreArchivo.c_str());

  string linea;
  string frasexd;

  // Obtener línea de archivo, y almacenar contenido en "linea"
  while (getline(archivo, linea)){
    frasexd+=linea;
  } 

  MultiMapS simbolos=Mapeo(frasexd);
  //Mapa1 simCodificados;
  //PrintMap(simbolos);
  //simbolos.swap();
  int p = partition(simbolos, simbolos.size()/2, 0, 0);
  return 0;
}