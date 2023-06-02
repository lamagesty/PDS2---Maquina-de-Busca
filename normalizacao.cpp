#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool find(vector<char> v, char c){
    
    for(vector<char>::iterator it = v.begin(); it != v.end(); it++){
        if((*it)==c){
            return true;
        }
    }
    return false;
}

string normalizacao(string s){

    ifstream Alfabeto("alfabeto.txt");
    vector<char> letras_validas;
    char c;
    string result;

    while(Alfabeto.get(c)){
        letras_validas.push_back(c);
    }
    
    Alfabeto.close();

    for(int i = 0;i < s.size();i++){
        if(find(letras_validas, s[i])){
            result.push_back(s[i]);
        }
        else if(isupper(s[i])){
            result.push_back(tolower(s[i]));
        }
    }

    return result;
}

int main(){

    string palavra;
    cin >> palavra;
    cout << normalizacao(palavra) << endl;
    return 0;
}