#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "indice_invertido.h"
#include <dirent.h>
#include <sys/types.h>
#include <fstream>

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

map<string, map<int , int>> indice_invertido::Procurar(string palavra){
    map<string, map<int , int>> busca_documento;
    
    if(Pertence(palavra)){
        for (auto it = indiceInvertido_.begin(); it != indiceInvertido_.end(); it++) {
            if(it->first == palavra){
                for (auto innerIt = it->second.begin(); innerIt != it->second.end(); innerIt++) {

                    busca_documento[innerIt->first][innerIt->second]++;
                    
                }
            }
        } 

    } else{
        cout << "A palavra" << palavra << "não pertence a nenhum documento";
    }

    
     for (auto it = busca_documento.begin(); it != busca_documento.end(); it++) {
         cout << it->first << " ";

         //Loop no mapa interno
         for (auto innerIt = it->second.begin(); innerIt != it->second.end(); innerIt++) {
            cout << innerIt->first << " " << innerIt->second << endl;
        }
    }
    return busca_documento;
}


// void indice_invertido::Ordenacao(map<string, map<int, int>> busca_documento){

//     map<string, map<int , int>> busca_agrupada;

//     int contador_hits = 0;
//     int contador_documento = 0;

//     for (auto it = busca_documento.begin(); it != busca_documento.end(); it++) {

//         for (auto innerIt = it->second.begin(); innerIt != it->second.end(); innerIt++) {
//             contador_hits += innerIt->first;
//             contador_documento += innerIt->second;

//         }

//         busca_agrupada[it->first][contador_hits] = contador_documento;
            
//     }

//     for (auto it = busca_agrupada.begin(); it != busca_agrupada.end(); it++) {
//         cout << it->first << " ";

//         // Loop no mapa interno
//         for (auto innerIt = it->second.begin(); innerIt != it->second.end(); innerIt++) {
//             cout << innerIt->first << " " << innerIt->second << endl;
//         }
//     }
// }


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