#include <iostream>
#include <dirent.h>
#include <sys/types.h>
#include <fstream>
#include <string>

using namespace std;

DIR* d = opendir("documentos");
dirent* rd = readdir(d);
string line;

int main(){

    while(rd != NULL){
        string nameOfFile = rd->d_name;
        ifstream myFile("documentos/" + nameOfFile);
        if((rd->d_name[0]) == '.'){
            break;
        }
        cout << rd->d_name << endl;
        rd = readdir(d);
    }
    closedir(d);

}