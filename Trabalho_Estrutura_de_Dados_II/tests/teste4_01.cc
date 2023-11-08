// Teste 4_01:
// Testes Unitários
// Testa o método de inserção da ABD

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
    tst->toString("test4_01.csv");
    cout << endl << endl;

    return 0;
}