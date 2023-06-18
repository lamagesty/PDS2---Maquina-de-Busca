#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "indice_invertido.h"
#include <dirent.h>
#include <sys/types.h>
#include <fstream>

using namespace std;

//teste 
void indice_invertido::Inserir(string palavra, string documento){
    indiceInvertido_[palavra][documento]++;
}

void indice_invertido::Preencher(){
    DIR* d = opendir("documentos");
    dirent* rd = readdir(d);

    while(rd != NULL){
        string nameOfFile = rd->d_name;
        ifstream myFile("documentos/" + nameOfFile);
        if((rd->d_name[0]) == '.'){
        } else{
            string palavra;
            cout << rd->d_name << endl;
            while(myFile >> palavra){
                string palavra_normalizada = Normalizar(palavra);
                Inserir(palavra_normalizada, rd->d_name);
            }
        }
        rd = readdir(d); 
        myFile.close();
    }
    closedir(d);
}

void indice_invertido::Procurar(string palavra){

}

void indice_invertido::Imprimir(){
    for (auto it = indiceInvertido_.begin(); it != indiceInvertido_.end(); it++) {
        cout << it->first << " ";

        // Loop no mapa interno
        for (auto innerIt = it->second.begin(); innerIt != it->second.end(); innerIt++) {
            cout << innerIt->first << " " << innerIt->second << endl;
        }
    }
}

void indice_invertido::Excluir(){
    indiceInvertido_.clear();
}

bool find(vector<char> v, char c){
    for(vector<char>::iterator it = v.begin(); it != v.end(); it++){
        if((*it)==c){
            return true;
        }
    }
    return false;
}


string indice_invertido::Normalizar(string palavra){
    ifstream Alfabeto("alfabeto.txt");
    vector<char> letras_validas;
    char c;
    string result;

    while(Alfabeto.get(c)){
        letras_validas.push_back(c);
    }
    
    Alfabeto.close();

    for(int i = 0;i < palavra.size();i++){
        if(find(letras_validas, palavra[i])){
            result.push_back(palavra[i]);
        }
        else if(isupper(palavra[i])){
            result.push_back(tolower(palavra[i]));
        }
    }

    return result;
}