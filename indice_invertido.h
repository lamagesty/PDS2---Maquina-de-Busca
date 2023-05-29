#ifndef INDICE_INVERTIDO_
#define INDICE_INVERTIDO_
#include <map>
#include <string>
#include <set>

using namespace std;

class indice_invertido{
    public:
        void Inserir(string palavra, string documento);

    private:
        map<string, map<string, int>> indiceInvertido;
};

#endif