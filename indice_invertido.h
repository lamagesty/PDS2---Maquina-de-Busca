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

        set<string> documentos(string palavra);

        bool Pertence(string palavra);

        void Ordenacao(map<string, map<int, int>>);

        void Excluir();

        void ExcluirDoc();

        void Imprimir();

        void ImprimirDoc(int contador_palavras);

        string Normalizar(string palavra);

    private:
        map<string, map<string, int>> indiceInvertido_;

        map<string, pair<int, int>> documentos_;
};

#endif