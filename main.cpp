#include "indice_invertido.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;


int main(){
    indice_invertido MaquinaDeBusca;
    MaquinaDeBusca.Excluir();
    MaquinaDeBusca.Preencher();
    string palavra; 

    string linha;

    while (getline(cin, linha)) {
        std::stringstream ss(linha); // Cria um stringstream com a linha atual
        
        string palavra;
        int contador_palavras = 0;
        
        // Lê palavra por palavra da linha atual
        while (ss >> palavra) {
            contador_palavras++;
            try{
                MaquinaDeBusca.Procurar(palavra);
            } catch(PalavraInexistente e){
                cout << "A palavra " << e.palavra << " não está presente em nenhum documento." << endl;
            }
        }
        
        try{
            MaquinaDeBusca.Imprimir(contador_palavras);
        } catch(ConsultaSemCorrespondencia e){
             cout << "Não existem documentos com todas as palavras consultadas." << endl;
        }
        
        MaquinaDeBusca.ExcluirDoc(); 
    }

}