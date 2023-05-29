#include <iostream>
#include <map>
#include <string>
#include "indice_invertido.h"

using namespace std;

void indice_invertido::Inserir(string palavra, string documento){
    indiceInvertido[palavra][documento]++;
}