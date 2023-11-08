// Teste 4_03:
// Testes Unitários
// Testa o método de remoção da ABD

#include <iostream>

#include "../tabela/include/tstree.h"

using namespace std;

int main()
{
    TSTree* tst = new TSTree();

    string palavras[] = {"aboboras", "abobora", "abacaxi", "abacate", "feijao", "abacate", "feijoada", "amar", "amarelo", "abacateiro"};

    cout << "Inserindo palavras..." << endl << endl;
    for(int i = 0; i < 10; i++)
        tst->insert(palavras[i]);

    cout << "Imprimindo as palavras da árvore:" << endl;
    tst->toString();
    cout << endl << endl;

    cout << "Buscando a palavra inserida 'amar'..." << endl;
    if(tst->search("amar"))
        cout << "Palavra encontrada com sucesso!" << endl << endl;
    else
    {
        cout << "Palavra não encontrada." << endl << endl;
        return -1;
    }
    

    cout << "Deletando a palavra 'amar'... " << endl << endl;
    tst->deleta("amar");

    cout << "Imprimindo as palavras da árvore:" << endl;
    tst->toString("test4_03.csv");
    cout << endl << endl;

    cout << "Buscando a palavra inserida 'amar'..." << endl;
    if(tst->search("amar"))
    {
        cout << "Palavra encontrada. Falha na remoção." << endl << endl;
        return -1;
    }
    else
        cout << "Palavra não encontrada. Removida com sucesso!" << endl << endl;
    

    return 0;
}