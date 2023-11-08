// Teste 3:
// Estudo comparativo entre 4 diferentes funções hash.

#include "../tabela/include/hash.h"

#include <fstream>
#include <string>
#include <string.h>
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

#define hash_size 524287

// Método que compara se uma string é um artigo
bool ehArtigo(string p)
{
    return (p.compare("o") == 0   || p.compare("a") == 0  || p.compare("os") == 0  || 
            p.compare("as") == 0  || p.compare("um") == 0 || p.compare("uma") == 0 || 
            p.compare("uns") == 0 || p.compare("umas") == 0 ||p.compare("O") == 0   || p.compare("A") == 0  || p.compare("os") == 0  || 
            p.compare("As") == 0  || p.compare("Um") == 0 || p.compare("Uma") == 0 || 
            p.compare("Uns") == 0 || p.compare("Umas") == 0);
}

// Método que compara se uma string é uma preposição
bool ehPreposicao(string p)
{
    return (p.compare("a") == 0       || p.compare("ante") == 0  || p.compare("após") == 0   || 
            p.compare("até") == 0     || p.compare("com") == 0   || p.compare("contra") == 0 || 
            p.compare("de") == 0      || p.compare("desde") == 0 || p.compare("em") == 0     || 
            p.compare("entre") == 0   || p.compare("para") == 0  || p.compare("por") == 0    || 
            p.compare("perante") == 0 || p.compare("sem") == 0   || p.compare("sob") == 0    || 
            p.compare("sobre") == 0   || p.compare("trás") == 0  || p.compare("per") == 0    || 
            p.compare("e") == 0 || p.compare("A") == 0       || p.compare("Ante") == 0  || p.compare("Após") == 0   || 
            p.compare("Até") == 0     || p.compare("Com") == 0   || p.compare("Contra") == 0 || 
            p.compare("De") == 0      || p.compare("Desde") == 0 || p.compare("Em") == 0     || 
            p.compare("Entre") == 0   || p.compare("Para") == 0  || p.compare("Por") == 0    || 
            p.compare("Perante") == 0 || p.compare("Sem") == 0   || p.compare("Sob") == 0    || 
            p.compare("Sobre") == 0   || p.compare("Trás") == 0  || p.compare("Per") == 0    || 
            p.compare("E") == 0);
}

// Método que compara se uma string é uma pontuação
bool ehPontuacao(char s)
{
    return (s == ','  || s == '.'  || s == ';'  || s == ':'  || s == '?' || s == '<'  || s == '>' || 
            s == '\\' || s == '/'  || s == '!'  || s == '='  || s == '*' || s == '+'  || 
            s == '_'  || s == '\"' || s == '('  || s == ')'  || s == '&' || s == '%'  || s == '$' || 
            s == '#'  || s == ' '  || s == '\n' || s == '\t' || s == '{' || s == '}'  || s == '[' || 
            s == ']'  || s == '|'  || s == '\f' || s == '\r' || s == '~' || s == '^');
}

// Método para a leitura do arquivo
vector<string> leArquivo(string nomeArquivo)
{
    cout << "Importando dados do arquivo " << endl;
    fstream arq;
    arq.open(nomeArquivo, ios::in);
    if (!arq.is_open())
    {
        cout << "FALHA AO ABRIR O ARQUIVO" << endl;
        vector<string> vazio;
        return vazio;
    }

    vector<string> palavras;
    string line;

    while (getline(arq, line))
    {
        stringstream ss(line);
        string palavra;

        while (getline(ss, palavra, ' ')) // so espaços separando as palavras
        {
            //cout << palavra << endl;
            for(int i=0; i<palavra.size(); i++){
                if(ehPontuacao(palavra[i])) //para tirar pontuações das palavras
                    palavra[i]='\0';
                // if(palavra[i]=='-' && palavra[i+1]=='-'){ //para tirar travessões de falas
                //     int j=i;
                //     do{
                //         palavra[j]=palavra[j+2];
                //         j++;
                //     }while (j<palavra.size()-2);
                //     palavra[j+1]='\0'; //fim da string
                // }
            }
            //cout << palavra << endl;
            if(!ehPreposicao(palavra) && !ehArtigo(palavra) && palavra.compare("\n")!=0){ //desconsidera artigos, preposições e \n
                palavras.push_back(palavra.c_str()); 
                // cout<<palavra<<endl;
            }
        }
            // for(int i=0; i<palavras.size(); i++)   
            //     cout<<palavras[i]<<endl;
    }


    arq.close();
    return palavras;
}
int funcHash1(string key)
{
    int i; 
    int tamS = key.size();
    unsigned int hash = 0;

    for(i = 0; i < tamS; i++)
        hash += key[i] * (i + 1); // somatório do código ASCII vezes a posição
    return hash % hash_size; 

}

int funcHash2(string key)
{
    int a = 63;
    int b = hash_size;
    int c = key.size();
    int hash = 0;
    long p_pow = 1;
    for(int i = 0; i < c; i++) {
        hash = (hash + (key[i] - 'a' + 1) * p_pow) % b;
        p_pow = (p_pow * a) % b;
    }
    return hash;
}

int funcHash3(string key)
{
    int a = 37;
    int b = 1e9 + 9;
    int c = key.size();
    int hash = 0;
    long p_pow = 1;
    for(int i = 0; i < c; i++) {
        hash = (hash + (key[i] - 'a' + 1) * p_pow) % b;
        p_pow = (p_pow * a) % b;
    }
    return hash;
}

int funcHash4(string key)
{
    int hash = 0;
    for (int i = 0; i < key.size(); i++)
    {
        hash += key[i] + 9;
    }
    return hash % hash_size;
}

int main()
{
    //abrindo arquivo com os nomes de cada livro:
    fstream arq_nomes;
    string inp = INPUT_DIR + string("nome_arquivos.txt"); 
    arq_nomes.open(inp, ios::in);

    string arq_livro;

    //faz a leitura de 1 livro:
    getline(arq_nomes, arq_livro);
    cout << "\nIniciando leitura do " << arq_livro << endl;

    //diretório do arquivo que será lido:
    string input = INPUT_DIR + arq_livro; 

    //Chama a função que lê o arquivo e separa as palavras:
    vector<string> palavras = leArquivo(input); 
    //Verifica se a leitura falhou:
    if(palavras.empty())
        return -1;

    int n_inseridos;

    //Criando uma tabela hash vazia utilizando a função hash 1:
    Hash hash1(hash_size, funcHash1); 
    n_inseridos = 0;
    //insere os elementos do vetor na hash:
    for (int i = 0; i < palavras.size(); i++)
    {
        if(hash1.Insere1(palavras[i], i)!=-1)
            n_inseridos++;
    }
    cout << endl << "Utilizando a função hash 1:" << endl;
    cout << "Numero de palavras inseridas: " << n_inseridos << endl;
    hash1.ImprimeInfo();


    //Criando uma tabela hash vazia utilizando a função hash 2:
    Hash hash2(hash_size, funcHash2); 
    n_inseridos = 0;
    //insere os elementos do vetor na hash:
    for (int i = 0; i < palavras.size(); i++)
    {
        if(hash2.Insere1(palavras[i], i)!=-1)
            n_inseridos++;
    }
    cout << endl << "Utilizando a função hash 2:" << endl;
    cout << "Numero de palavras inseridas: " << n_inseridos << endl;
    hash2.ImprimeInfo();


    //Criando uma tabela hash vazia utilizando a função hash 3:
    Hash hash3(hash_size, funcHash3); 
    n_inseridos = 0;
    //insere os elementos do vetor na hash:
    for (int i = 0; i < palavras.size(); i++)
    {
        if(hash3.Insere1(palavras[i], i)!=-1)
            n_inseridos++;
    }
    cout << endl << "Utilizando a função hash 3:" << endl;
    cout << "Numero de palavras inseridas: " << n_inseridos << endl;
    hash3.ImprimeInfo();

    //Criando uma tabela hash vazia utilizando a função hash 4:
    Hash hash4(hash_size, funcHash4); 
    n_inseridos = 0;
    //insere os elementos do vetor na hash:
    for (int i = 0; i < palavras.size(); i++)
    {
        if(hash4.Insere1(palavras[i], i)!=-1)
            n_inseridos++;
    }
    cout << endl << "Utilizando a função hash 4:" << endl;
    cout << "Numero de palavras inseridas: " << n_inseridos << endl;
    hash4.ImprimeInfo();

    return 0;
}