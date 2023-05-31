#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <set>

using namespace std;

int main(){

    ifstream MyReadFile("teste.txt");
    ifstream Alfabeto("alfabeto.txt");
    map<string, string> n;

    string letras;
    string character;

    set<string> alph;

    while(getline(Alfabeto, letras, '\n')){
        alph.insert(letras);
    }
    
    while(getline(MyReadFile, character, '\n')){
        if(alph.find(character) == alph.end()){
            n[character] = MyReadFile.peek();
        }
    }

    for (map<string, string>::iterator it = n.begin(); it != n.end(); it++){
        cout << (*it).first << " " << (*it).second << endl;
    }

    return 0;
}