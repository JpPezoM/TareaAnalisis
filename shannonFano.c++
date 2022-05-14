#include <iostream>
#include <map>
#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;
// Para simplificar la declaración de iteradores
typedef map<unsigned char,double> Mapa;
typedef map<double, unsigned char> MapaS;
typedef map<unsigned char,double,string> Mapa1;
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
    final.insert(pair<double, unsigned char>(probLetra, it->first));
  }
  //PrintMap(final);
  return final;
}

void shannonfanon(Mapa simbolos,int inicio,int largo,Mapa1 simCodificado){
  //if(inicio==largo){
  //}
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
  return 0;
}