#include <iostream>
#include <map>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cmath>

using namespace std;
// Para simplificar la declaración de iteradores
typedef map<unsigned char,double> Mapa;
typedef map<double, unsigned char> MapaS;
typedef map<string, unsigned char> MapaCod;
template<typename Map>

void PrintMap(Map& m)
{
    cout << "[ ";
    for (auto &item : m) {
        cout << item.first << ":" << item.second << " " << '\n';
    }
    cout << "]\n";
}


MapaS Mapeo(string frase){
  Mapa contador;
  MapaS final;

  double largoFrase = frase.length();

  for( size_t i=0; i<frase.size(); ++i)
    contador[frase[i]]++;

  for(Mapa::const_iterator it=contador.begin();it!=contador.end();++it){
    double probLetra = it->second/largoFrase;
    final.insert(pair<double, unsigned char>(probLetra *-1, it->first));
  }
  //PrintMap(final);
  return final;
}

int partition(MapaS simbolos, int p){
  double sumaA;
  double sumaB;
  double dif;
  int cont = 0;

  //Empieza la suma
  MapaS::const_iterator it=simbolos.begin();
  for(int i = 0; i < p; i++){ //Suma la primera parte
    sumaA += abs(it->first);
    //cout << "A" << abs(it->first) << " - "<< it->second << endl;
    ++it;
  }
  for (int i = p; i < simbolos.size(); i++){ //suma la segunda parte
    sumaB += abs(it->first);
    //cout << "B" << abs(it->first) << " - "<< it->second << endl;
    ++it;
  }

  //Se ve las diferencias de las sumas
  dif = sumaA - sumaB;
  if (sumaA > sumaB){
    int part = partition(simbolos, p-1);
  }
  
  cout << dif << endl;
  cout << "SumaA = " << sumaA << " " << "SumaB = " << sumaB << endl;  
  return p;
}

void shannonfanon(MapaS simbolos){
  if (simbolos.empty()) return; //Retorna si no hay ningun valor en el mapa

  MapaCod mapaCodificado;
  int p = partition(simbolos, simbolos.size()/2); //Se lama a la funcion que
  






  Mapa A;
  Mapa B;

  

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
  string nombreArchivo = "english.100MB";
  ifstream archivo(nombreArchivo.c_str());

  string linea;
  string frasexd;

  // Obtener línea de archivo, y almacenar contenido en "linea"
  while (getline(archivo, linea)){
    frasexd+=linea;
  } 

  MapaS simbolos=Mapeo(frasexd);
  //Mapa1 simCodificados;
  PrintMap(simbolos);
  //simbolos.swap();
  int p = partition(simbolos, simbolos.size()/2);
  return 0;
}