// Teste 4_02:
// Testes Unitários
// Testa o método de busca da ABD

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

    cout << "*****************************************" << endl;
    cout << "Buscando a palavra inserida 'aboboras'..." << endl;
    if(tst->search("aboboras"))
        cout << "Palavra encontrada com sucesso!" << endl << endl;
    else
    {
        cout << "Palavra não encontrada." << endl << endl;
        return -1;
    }

    cout << "*****************************************" << endl;
    cout << "Buscando a palavra inserida 'abobora'..." << endl;
    if(tst->search("abobora"))
        cout << "Palavra encontrada com sucesso!" << endl << endl;
    else
    {
        cout << "Palavra não encontrada." << endl << endl;
        return -1;
    }

    cout << "*****************************************" << endl;
    cout << "Buscando a palavra inserida 'abacaxi'..." << endl;
    if(tst->search("abacaxi"))
        cout << "Palavra encontrada com sucesso!" << endl << endl;
    else
    {
        cout << "Palavra não encontrada." << endl << endl;
        return -1;
    }

    cout << "*****************************************" << endl;
    cout << "Buscando a palavra inserida 'abacate'..." << endl;
    if(tst->search("abacate"))
        cout << "Palavra encontrada com sucesso!" << endl << endl;
    else
    {
        cout << "Palavra não encontrada." << endl << endl;
        return -1;
    }

    cout << "*****************************************" << endl;
    cout << "Buscando a palavra inserida 'feijao'..." << endl;
    if(tst->search("feijao"))
        cout << "Palavra encontrada com sucesso!" << endl << endl;
    else
    {
        cout << "Palavra não encontrada." << endl << endl;
        return -1;
    }

    cout << "*****************************************" << endl;
    cout << "Buscando a palavra inserida 'feijoada'..." << endl;
    if(tst->search("feijoada"))
        cout << "Palavra encontrada com sucesso!" << endl << endl;
    else
    {
        cout << "Palavra não encontrada." << endl << endl;
        return -1;
    }

    cout << "*****************************************" << endl;
    cout << "Buscando a palavra inserida 'amar'..." << endl;
    if(tst->search("amar"))
        cout << "Palavra encontrada com sucesso!" << endl << endl;
    else
    {
        cout << "Palavra não encontrada." << endl << endl;
        return -1;
    }

    cout << "*****************************************" << endl;
    cout << "Buscando a palavra inserida 'amarelo'..." << endl;
    if(tst->search("amarelo"))
        cout << "Palavra encontrada com sucesso!" << endl << endl;
    else
    {
        cout << "Palavra não encontrada." << endl << endl;
        return -1;
    }

    cout << "*****************************************" << endl;
    cout << "Buscando a palavra inserida 'abacateiro'..." << endl;
    if(tst->search("abacateiro"))
        cout << "Palavra encontrada com sucesso!" << endl << endl;
    else
    {
        cout << "Palavra não encontrada." << endl << endl;
        return -1;
    }

    return 0;
}