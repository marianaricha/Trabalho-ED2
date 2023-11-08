#include "hash.h"

#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
            p.compare("e") == 0       || 
            p.compare("A") == 0       || p.compare("Ante") == 0  || p.compare("Após") == 0   || 
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
            for(int i=0; i<palavra.size(); i++){
                if(ehPontuacao(palavra[i])) //para tirar pontuações das palavras
                {
                    palavra[i]='\0';
                    break;
                }    
                // if(palavra[i]=='-' && palavra[i+1]=='-'){ //para tirar travessões de falas
                //     int j=i;
                //     do{
                //         palavra[j]=palavra[j+2];
                //         j++;
                //     }while (j<palavra.size()-2);
                //     palavra[j+1]='\0'; //fim da string
                // }
            }
            if(!ehPreposicao(palavra) && !ehArtigo(palavra) && palavra.compare("\n")!=0){ //desconsidera artigos, preposições e \n
                palavras.push_back(palavra); 
            }
        }
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
    return hash; 

}

int main()
{
    //abrindo arquivo com os nomes de cada livro:
    fstream arq_nomes;
    string inp = INPUT_DIR + string("nome_arquivos.txt"); 
    arq_nomes.open(inp, ios::in);
    if (!arq_nomes.is_open())
    {
        cout << "FALHA AO ABRIR O ARQUIVO COM OS NOMES DOS LIVROS" << endl;
        return -1;
    }

    string arq_livro;
    int k = 1;

    //faz a leitura de 10 livros e encontra as 50 palavras mais usadas em cada um:
    while(getline(arq_nomes, arq_livro))
    {
        cout << "\nIniciando leitura do " << arq_livro << endl;

        //diretório do arquivo que será lido:
        string input = INPUT_DIR + arq_livro;  

        //Chama a função que lê o arquivo e separa as palavras:
        vector<string> palavras = leArquivo(input); 
        //Verifica se a leitura falhou:
        if(palavras.empty())
            return -1;

        //Criando uma tabela hash vazia utilizando a função hash 1:
        Hash hash(hash_size, funcHash1); 

        int n_inseridos = 0;
        for (int i = 0; i < palavras.size(); i++)
        {
            // insere os elementos do vetor na hash:
            if(hash.Insere1(palavras[i], i)!=-1){
                n_inseridos++;
                // cout << palavras[i] << endl;
            }
                
        }
        cout << "Numero de palavras inseridas: " << n_inseridos << endl;
        hash.ImprimeInfo();

        //ordena a tabela hash em ordem decrescente de acordo com os contadores das palavras:
        vector<Palavra> words;
        if(k == 1){
            //para o primeiro livro, analisa o desempenho dos 3 métodos de ordenação:
            words = hash.OrdenaTabela(QUICKSORT);
            vector<Palavra> words2 = hash.OrdenaTabela(MERGESORT);
            vector<Palavra> words3 = hash.OrdenaTabela(COMBSORT);
        }
        else{
            //para os próximos livros, utiliza apenas o método de ordenação mais eficiente:
            words = hash.OrdenaTabela(QUICKSORT);
        }

        //escrevendo em um arquivo as 50 palavras mais frequentes e suas respectivas contagens:
        string nome = "palavras_" + arq_livro;
        fstream arq50palavras(nome, ios::in | ios::out | ios::app);
        for(int i = 0; i < 50 && i<words.size(); i++)
            arq50palavras << words[i].getChave() << ";" << words[i].getCont() << endl;
        
        arq50palavras.close();
        k++;
        // hash.~Hash();
    }
    arq_nomes.close();

    //Criando outra tabela hash vazia utilizando a função hash 1:
    Hash hash2(hash_size, funcHash1); 

    //abrindo arquivo com os nomes de cada livro: 
    arq_nomes.open(inp, ios::in);
    if (!arq_nomes.is_open())
    {
        cout << "FALHA AO ABRIR O ARQUIVO COM OS NOMES DOS LIVROS" << endl;
        return -1;
    }
    
    //faz a leitura das 50 palavras mais usadas em cada um dos livros:
    while(getline(arq_nomes, arq_livro))
    {
        string nome = "palavras_" + arq_livro;

        cout << "\nIniciando leitura do arquivo "<< nome << endl;

        //diretório do arquivo que será lido:
        string input = BUILD_DIR + nome; 

        //abrindo arquivo com as 50 palavras mais frequentes:
        fstream arq50palavras;
        arq50palavras.open(input, ios::in);
        if (!arq50palavras.is_open())
        {
            cout << "FALHA AO ABRIR O ARQUIVO COM AS 50 PALAVRAS MAIS FREQUENTES DO " << arq_livro << endl;
            return -1;
        }

        vector<string> palavra;
        vector<int> contador;
        string line;

        //leitura do arquivo com as 50 palavras mais frequentes, linha por linha:
        while (getline(arq50palavras, line))
        {
            stringstream ss(line);
            string token;
            vector<string> tokens;
            while(getline(ss, token, ';')){
                tokens.push_back(token);
            }
            if(tokens.size() == 2){
                //armazena as palavras e seus respectivos contadores em dois vetores:
                palavra.push_back(tokens[0].c_str());
                contador.push_back(stoi(tokens[1]));
            }
        }

        int n_inseridos = 0;
        for (int i = 0; i < palavra.size(); i++)
        {
            // insere os elementos dos vetores na hash:
            if(hash2.Insere2(palavra[i], i, contador[i]))
                n_inseridos++;
        }
        cout << "Numero de palavras inseridas: " << n_inseridos << endl;
        hash2.ImprimeInfo();
        arq50palavras.close();
    }

    //ordena a tabela hash com as palavras mais usadas em cada livro:
    vector<Palavra> wordsTotal = hash2.OrdenaTabela(QUICKSORT);

    //escrevendo em um arquivo as 50 palavras mais frequentes no total e suas respectivas contagens:
    fstream arq50palavrasTotal("mais_frequentes_total.txt", ios::in | ios::out | ios::app);
    for(int i = 0; i < 50 && i<wordsTotal.size(); i++)
        arq50palavrasTotal << wordsTotal[i].getChave() << ";" << wordsTotal[i].getCont() << endl;

    arq50palavrasTotal.close();
    // hash2.~Hash();
    
    return 0;
}