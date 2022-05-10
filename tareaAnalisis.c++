#include <iostream>
using namespace std;
#include <map>

void Mapeo(string frase){
  // Para simplificar la declaración de iteradores
  typedef map<char,int> Mapa;

  Mapa contador;
  string * probabilidades = NULL;
  probabilidades = new string[]

  double largoFrase = frase.length();
  cout << largoFrase;

  string * probabilidades = NULL;
  probabilidades = new string[largoFrase];

  for( size_t i=0; i<frase.size(); ++i)
    contador[frase[i]]++;

  cout << "Resultado:\n";
  for( Mapa::const_iterator it = contador.begin(); it != contador.end(); ++it )
  {
      //cout << it->first << ":" << it->second << '\n';
      double probLetra = it->second/largoFrase;
      cout << "Probabilidad de: " << it->first << " : " << probLetra << '\n';
    
  }
}

int main()
{
    string frase = "AASD,FG.gd,O) YSB";
    Mapeo(frase);
}