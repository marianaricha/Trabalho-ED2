#ifndef NODE_H
#define NODE_H

#include <string>

class Node {
    public:// funcionalidades padrão de um TAD nó

        Node();
        Node(std::string Chave);
        ~Node();
        std::string getChave();// retorna o valor da chave do nó
        int getCont();// quantidade de nós
        Node* getProx();// retorna próximo nó
        void setChave(std::string Chave);// atribui um valor passado
        void setProx(Node *Prox);// atribui um próximo
        void setCont(int cont);// atribui um valor ao contador
        void decrementCont();// diminui o contador em uma unidade
        void incrementCont();// aumenta o contador em uma unidade

    private:
        std::string chave;
        int cont;
        Node *Prox;
};

#endif