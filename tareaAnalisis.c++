#include <iostream>
#include <map>
#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

void Mapeoqlo(string frase){
  int * ascci=0;
  ascci = new int[256];
  for(int i=0;i<=frase.length();i++){
    cout<<frase[i]<<" :"<<int(frase[i])<<'\n';
  }
  for(int i=0;i<=256;i++){
    cout<<i<<' ' << char(ascci[i])<<": "<<ascci[i]<<'\n';
  }
  


}
void Mapeo(string frase){
  // Para simplificar la declaración de iteradores
  typedef map<char,int> Mapa;

  Mapa contador;

  double largoFrase = frase.length();
  cout << largoFrase;


  string * probabilidades = NULL;
  probabilidades = new string[frase.length()];

  for( size_t i=0; i<frase.size(); ++i)
    contador[frase[i]]++;

  cout << "Resultado:\n";
  int n=0;
  int k;
  for( Mapa::const_iterator it = contador.begin(); it != contador.end(); ++it )
  {
      //cout << it->first << ":" << it->second << '\n';
      //double probLetra = it->second/largoFrase;
      k = it->first;
      cout << it->first << " : " << k << '\n';
      //cout << "Probabilidad de: " << it->first << " : " << it->second << '\n';
      n+=1;
  }
  cout<<n<<'\n';
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
  Mapeoqlo(frasexd);

  /*int k;
  string fr = "afd";
  for (int i = 0; i < fr.length(); i++)
  {
    k = fr[i];
    cout << k << '\n';
  }*/


}