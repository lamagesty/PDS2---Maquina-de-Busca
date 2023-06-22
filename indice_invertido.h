#ifndef INDICE_INVERTIDO_
#define INDICE_INVERTIDO_
#include <map>
#include <string>
#include <set>

using namespace std;

class indice_invertido{
    public:

        //Subsistema de Indexação: insere no índice invertido todas as
        //palavras contidas nos documentos.
        void Preencher();

        //Subsistema de Indexação: insere a palavra, o(s) documento(s) na qual ela aparece e 
        //o número de recorrências da mesma.
        void Inserir(string palavra, string documento);

        //Subsistema de Recuperação: procura as palavras consultadas e as armazena
        //com o número de hits e o contador de palavras que foram encontradas
        //em um determinado documento
        void Procurar(string palavra);

        //Subsistema de Indexação: diz se a palavra pertence ou não ao 
        //índice invertido. 
        bool Pertence(string palavra);

        //Subsistema de Indexação: limpa o índice invertido.
        void Excluir();

        //Subsistema de Recuperação: limpa os documentos ordenados por hits
        void ExcluirDoc();

        //Subsistema de Recuperação: imprime os documentos que contém as palavras da consulta,
        //já ordenados pelo número de hits
        void Imprimir(int contador_palavras);

        //Subsistema de Indexação e Recuperação: normaliza as palavras consultadas e
        //as palavras pertencentes aos documentos.
        string Normalizar(string palavra);

    private:
        //Indexação
        map<string, map<string, int>> indiceInvertido_;

        //Recuperação
        map<string, pair<int, int>> documentos_;
};

#endif