#include <iostream>
#include <map>
#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

struct node{
  char simbolo;
  int ascii;
  string code;
  double prob;
  struct node *next;
};
typedef struct node *Lista;


void insertarFinal(Lista &lista, double valor){
  Lista t, q = new(struct node);

  q->prob = valor;
  q->next = NULL;

  if (lista == NULL){
    lista = q;
  }
  else{
    t = lista;
    while (t->next != NULL){
      t = t->next;
    }
    t->next = q;
  }
  
}

void imprimeLista (Lista lista){
  int i = 0;

  while (lista != NULL){
    cout << ' ' << i+1 << ") " << lista->prob << endl;
    lista = lista->next;
    i++;
  }
  
}

Lista Mapeo(string frase){
  // Para simplificar la declaración de iteradores
  typedef map<char,int> Mapa;

  Mapa contador;
  Lista lista = NULL;

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
      double probLetra = it->second/largoFrase;
      unsigned char simb = it->first;
      k = simb;
      //cout << it->first << " : " << k << '\n';
      cout << "Probabilidad de: " << it->first << " : " << probLetra << '\n';
      insertarFinal(lista, probLetra);
      n+=1;
  }
  cout<<n<<'\n';

  return lista;
}

int main()
{
  string nombreArchivo = "english.100MB";
  ifstream archivo(nombreArchivo.c_str());
  string linea;
  int n =1;
  string frasexd;

  Lista lista = NULL;

    // Obtener línea de archivo, y almacenar contenido en "linea"
  while (getline(archivo, linea)){
    frasexd+=linea;
  } 
  lista = Mapeo(frasexd);
  imprimeLista(lista);

  /*int k;
  string fr = "afd";
  for (int i = 0; i < fr.length(); i++)
  {
    k = fr[i];
    cout << k << '\n';
  }*/

 /* node prueba;
  prueba.prob = 0.2;
  cout << prueba.prob;*/


}