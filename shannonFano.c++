#include <iostream>
#include <map>
#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

void Mapeo(string frase){
  // Para simplificar la declaración de iteradores
  typedef map<char,int> Mapa;

  Mapa contador;

  double largoFrase = frase.length();
  cout << largoFrase;

  for( size_t i=0; i<frase.size(); ++i)
    contador[frase[i]]++;

  cout << "Resultado:\n";
  int n=0;
  int k;
  for( Mapa::const_iterator it = contador.begin(); it != contador.end(); ++it )
  {
      //cout << it->first << ":" << it->second << '\n';
      double probLetra = it->second/largoFrase;
      unsigned char simb = it->first;
      k = simb;
      //cout << it->first << " : " << k << '\n';
      cout << "Probabilidad de: " << it->first << " : " << probLetra << '\n';
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
  Mapeo(frasexd);


}