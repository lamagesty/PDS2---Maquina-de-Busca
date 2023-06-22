#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "indice_invertido.h"
#include <dirent.h>
#include <sys/types.h>
#include <fstream>
#include <algorithm>

using namespace std;


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

bool indice_invertido::Pertence(string palavra){
    int contador = 0;
    for(auto it = indiceInvertido_.begin(); it != indiceInvertido_.end(); it++){
        if(it->first == palavra){
            contador++;
        }
    }
    if(contador == 0){
        return false;
    } else{
        return true;
    }
}

void indice_invertido::Procurar(string palavra){
    
    if(Pertence(palavra)){
        for (auto it = indiceInvertido_.begin(); it != indiceInvertido_.end(); it++) {
            if(it->first == palavra){
                for (auto innerIt = it->second.begin(); innerIt != it->second.end(); innerIt++) {

                    documentos_[innerIt->first].first += innerIt->second;
                    documentos_[innerIt->first].second += 1;
                }
            }
        } 

    } else{
        cout << "A palavra " << palavra << " não pertence a nenhum documento" << endl;
    } 
}

//função externa
bool comparaHits(const pair<string, pair<int, int>>& a, const pair<string, pair<int, int>>& b) {
    return a.second.first > b.second.first;
}

void indice_invertido::Imprimir(int contador_palavras){

    vector<pair<string, pair<int, int>>> vetor(documentos_.begin(), documentos_.end());

    sort(vetor.begin(), vetor.end(), comparaHits);

    for (auto it = vetor.begin(); it != vetor.end(); it++) {
        if(contador_palavras == it->second.second){
            cout << it->first << endl;
        }
    }
}

void indice_invertido::Excluir(){
    indiceInvertido_.clear();
}

void indice_invertido::ExcluirDoc(){
    documentos_.clear();
}

//função externa
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