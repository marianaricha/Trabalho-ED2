#include "Node.h"
#include <string>

Node::Node()
{
    this->cont = 1;
    this->Prox = nullptr;
}

Node::Node(std::string chave)// construtor para uma dada chave
{
    this->setChave(chave);
    this->cont = 1;
    this->Prox = nullptr;
}

Node::~Node()// destrutor vazio
{

}

std::string Node::getChave()
{
    return this->chave;
}

int Node::getCont()
{
    return this->cont;
}

Node *Node::getProx()
{
    return this->Prox;
}

void Node::setChave(std::string chave)
{
    this->chave = chave;
}

void Node::setProx(Node *Proxde)
{
    this->Prox = Prox;
}

void Node::incrementCont()
{
    this->cont++;
}

void Node::decrementCont()
{
    if (this->cont > 0)
        this->cont--;
}

void Node::setCont(int count)
{
    this->cont = count;
}
