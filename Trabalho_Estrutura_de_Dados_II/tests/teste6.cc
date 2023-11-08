// Teste 6:
// Taxas de compressão: Huffman

#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <iostream>
#include "../tabela/include/config.h"
#include "../tabela/include/huffman.h"
using namespace std;

int main()
{
    //Abrindo arquivo com os nomes de cada livro:
    fstream arq_nomes;
    string inp = INPUT_DIR + string("nome_arquivos.txt"); 
    arq_nomes.open(inp, ios::in);
    if (!arq_nomes.is_open())
    {
        cout << "FALHA AO ABRIR O ARQUIVO COM OS NOMES DOS LIVROS" << endl;
        return -1;
    }

    string arq_livro;

    //Abrindo todos os livros:
    for (int i = 0; i < 10; i++)
    {
        getline(arq_nomes, arq_livro);
        cout << "\nIniciando compressão do " << arq_livro << ":" << endl;

        //Diretório do arquivo que será lido:
        string input = INPUT_DIR + arq_livro; 

        //Abrindo o livro:
        ifstream arq;
        arq.open(input, ios::in);
        if (!arq.is_open())
            cout << "FALHA AO ABRIR O LIVRO" << endl;

        //Comprimindo o livro e imprimindo os resultados:
        Huffman huff(arq);
        cout << "Resuldados da compressão de Huffman:";
        huff.imprimeResultados();
    }

    return 0;
}