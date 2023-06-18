#include "indice_invertido.h"
#include <iostream>
#include <string>
using namespace std;


int main(){
    indice_invertido Dicionario;
    Dicionario.Excluir();
    Dicionario.Preencher();
    
    string palavra;

    map<string, map<int , int>> documentos;

    while(cin >> palavra){
        documentos = Dicionario.Procurar(palavra);
    }

}