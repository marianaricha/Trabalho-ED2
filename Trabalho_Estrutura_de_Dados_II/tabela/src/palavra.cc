#include "palavra.h"

Palavra::Palavra(){
    this->chave = "";
    this->contador = 0;
}

Palavra::Palavra(string chave, int contador){
    this->chave = chave;
    this->contador = contador;
}

string Palavra::getChave(){
    return chave;
}

int Palavra::getCont(){
    return contador;
}

void Palavra::setChave(string chave){
    this->chave=chave;
}

void Palavra::setCont(int cont){
    this->contador=cont;
}

Palavra::~Palavra(){
}