#include "indice_invertido.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;


int main(){
    indice_invertido Dicionario;
    Dicionario.Excluir();
    Dicionario.Preencher();
    string palavra;
    map<string, map<int , int>> documentos;

    string linha;

    while (getline(cin, linha)) {
        std::stringstream ss(linha); // Cria um stringstream com a linha atual
        
        string palavra;
        int contador_palavras = 0;
        
        // Lê palavra por palavra da linha atual
        while (ss >> palavra) {
            contador_palavras++;
            Dicionario.Procurar(palavra);
        }
        
        Dicionario.ImprimirDoc(contador_palavras);
        Dicionario.ExcluirDoc(); 
    }

}