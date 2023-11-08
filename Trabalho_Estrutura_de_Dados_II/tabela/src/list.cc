#include "list.h"
#include <iostream>

using namespace std;

List::List()// construtor
{
    this->primeiro = nullptr;
    this->ultimo = nullptr;
    this->Tamanho = 0;
}

List::~List()// destrutor
{
    Node *currentprimeiro = this->primeiro;
    while (currentprimeiro != nullptr)
    {
        Node *aux = currentprimeiro->getProx();
        delete currentprimeiro;
        currentprimeiro = aux;
    }
}

void List::insert(int position, std::string chave)
{
    if (position > this->getTamanho() || position < 0)
        return;

    if (position == 0)
        return this->insertPrimeiro(chave);
    
    if (position == this->getTamanho())
        return this->insertUltimo(chave);

    Node *currentNode = this->get(position - 1);

    if (currentNode != nullptr)
        this->insertApos(currentNode, chave);
}

void List::insertApos(Node *node, std::string chave)
{
    if (node == nullptr)
        return this->insertPrimeiro(chave);
    
    if (node == this->ultimo)
        return this->insertUltimo(chave);

    Node *newNode = new Node(chave);
    newNode->setProx(node->getProx());
    node->setProx(newNode);

    this->Tamanho++;
}

void List::insertPrimeiro(std::string chave)
{
    Node *node = new Node(chave);// cria um novo nó
    node->setProx(this->primeiro);

    this->primeiro = node;// aponta para o primeiro nó, que é o criado agora
    this->Tamanho++;

    if (this->Tamanho == 1)//se a lista estiver vazia o *ultimo também aponta para esse nó novo
        this->ultimo = node;
}

void List::insertUltimo(std::string chave)
{
    Node *node = new Node(chave);

    if (this->Tamanho == 0)
        this->primeiro = node;//se o nó novo é o único da lista então *primeiro aponta para esse nó
    else
        this->ultimo->setProx(node);
        
    //senão então ele é o novo último

    this->ultimo = node;
    this->Tamanho++;
}

void List::removePrimeiro()
{
    if (this->primeiro == nullptr)// verifica se está vazia
        return;
    Node *remove = this->primeiro;
    this->primeiro = this->primeiro->getProx();// troca o nó apontado por *primeiro
    delete remove;//realiza a remoção do primeiro nó

    this->Tamanho--;

    if (this->Tamanho == 0)
        this->ultimo = nullptr;    
}

void List::remove(std::string chave)// remove nó da chave específica
{
    Node *antesNode = this->primeiro;

    if(antesNode != nullptr && antesNode->getChave().compare(chave) == 0){
        return this->removePrimeiro();
    }

    for (antesNode = this->primeiro; antesNode->getProx() != nullptr; antesNode = antesNode->getProx()){
        if (antesNode->getProx()->getChave().compare(chave) == 0){
            return this->removeApos(antesNode);
        }
            
    }
}

void List::removeUltimo()
{
    if (this->primeiro == nullptr)
        return;

    Node *aux = this->primeiro;
    Node *antesAux = nullptr;

    while (aux->getProx() != nullptr)
    {
        antesAux = aux;
        aux = aux->getProx();
    }

    if (this->primeiro == this->ultimo)
        this->primeiro = nullptr;
    else
        antesAux->setProx(nullptr);

    this->ultimo = antesAux;
    delete aux;
    this->Tamanho--;
}

void List::remove(int position)//remove nó da posição
{
    if (position >= this->getTamanho() || position < 0)
        return;

    if (position == 0)
        return this->removePrimeiro();

    if (position == this->getTamanho() - 1)
        return this->removeUltimo();

    Node *antesNode = this->get(position - 1);

    if (antesNode != nullptr){
        this->removeApos(antesNode);
    }    
}


void List::removeApos(Node *node)
{
    if (node == nullptr){
        return this->removePrimeiro();
    }
    Node *remove = node->getProx();
    node->setProx(remove->getProx());
    if (remove == this->ultimo){
        this->ultimo = node;
    }    
    delete remove;
    this->Tamanho--;
}

Node* List::get(std::string chave)
{
    for (Node *node = this->primeiro; node != nullptr; node = node->getProx())
    {
        if (node->getChave().compare(chave) == 0)
            return node;
    }

    return nullptr;
}

int List::getTamanho()
{
    return this->Tamanho;
}

Node* List::get(int position)
{
    Node *node = this->primeiro;
    for (int i = 0; i < position && node != nullptr; node = node->getProx(), i++){}
    return node;
}

bool List::vazio()
{
    if(this->Tamanho == 0)
        return true;// verificação simples se está vazia
    else
        return false;
}

bool List::busca(std::string chave)
{
    for (Node *node = this->primeiro; node != nullptr; node = node->getProx())
    {
        if (node->getChave().compare(chave) == 0){
            return true;
        }    
    }
    return false;
}