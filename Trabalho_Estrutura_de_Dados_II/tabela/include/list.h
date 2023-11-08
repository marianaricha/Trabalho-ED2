#ifndef LIST_H
#define LIST_H

#include <string>
#include "Node.h"

class List
{
    public:// funcionalidades básicas de um TAD lista
     
        List();//construtor
        ~List();//destrutor
        int getTamanho();//retorna o tamanho da lista

        Node* get(int position);// obtem o nó da posição
        Node* get(std::string chave); //retorna o nó com o valor passado se existir na lista

        void insert(int position, std::string chave); //insere um novo nó na lista na posição passada
        void insertPrimeiro(std::string chave);//insere um nó no começo
        void insertUltimo(std::string chave);//insere um novo nó no final no final

        void removePrimeiro();//remove o primeira nó
        void removeUltimo();//remove o último nó
        void remove(int position);// remove o npo da posição pedida
        void remove(std::string chave);// remove o nó que possui o valor passado

        bool vazio();// verifica se a lisra está vazia
        bool busca(std::string chave);//busca o nó com o valor passado, retorna true se existe ou false senão 

    private:
        Node *primeiro;
        Node *ultimo;
        int Tamanho;
        void insertApos(Node *node, std::string chave);// insere após o nó com determinado valor
        void removeApos(Node *node);// remove após o nó com determinado valor
};

#endif