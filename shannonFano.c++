#include <iostream>
#include <map>
#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;
// Para simplificar la declaración de iteradores
typedef map<unsigned char,double> Mapa;
typedef map<unsigned char,double,string> Mapa1;
template<typename Map>

void PrintMap(Map& m)
{
    cout << "[ ";
    for (auto &item : m) {
        cout << item.first << ":" << item.second << " ";
    }
    cout << "]\n";
}

Mapa Mapeo(string frase){
  Mapa contador;
  Mapa final;

  double largoFrase = frase.length();
  cout << largoFrase;

  for( size_t i=0; i<frase.size(); ++i)
    contador[frase[i]]++;

  cout << "Resultado:\n";
  int n=0;
  int k;

  for(Mapa::const_iterator it=contador.begin();it!=contador.end();++it){
    double probLetra = it->second/largoFrase;
    final.insert(pair<unsigned char,double>(it->first,probLetra));
  }
  //PrintMap(final);
  return final;
}

void shannonfanon(Mapa simbolos,int inicio,int largo,Mapa1 simCodificado){
  //if(inicio==largo){
  //}
  Mapa A;
  Mapa B;
  map<unsigned char,double,string> 

  

}
int main()
{
  string nombreArchivo = "english.100MB";
  ifstream archivo(nombreArchivo.c_str());
  
  string linea;
  int n =1;
  string frasexd;


    // Obtener línea de archivo, y almacenar contenido en "linea"
  while (getline(archivo, linea)){
    frasexd+=linea;
  } 

  
  Mapa simbolos=Mapeo(frasexd);
  Mapa1 simCodificados;
  PrintMap(simbolos);


}