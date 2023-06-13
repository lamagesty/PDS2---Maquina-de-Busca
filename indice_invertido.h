#ifndef INDICE_INVERTIDO_
#define INDICE_INVERTIDO_
#include <map>
#include <string>
#include <set>

using namespace std;

class indice_invertido{
    public:
        void Preencher();

        void Inserir(string palavra, string documento);

        void Procurar(string palavra);

        void Excluir();

        void Imprimir();

        string Normalizar(string palavra);

    private:
        map<string, map<string, int>> indiceInvertido_;
};

#endif