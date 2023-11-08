#ifndef TRABALHO_PARTE_2_MINHEAPNODE_H
#define TRABALHO_PARTE_2_MINHEAPNODE_H
#include "string"
using namespace std;
class MinHeapNode{
private:
    char info;
    unsigned int freq;
    string code;
    MinHeapNode *left, *right;

public:
    MinHeapNode(char info, unsigned int freq);
    ~MinHeapNode();
    //funções específicas para a árvore de huffman
    unsigned int getFreq();
    void incrementaFreq();
    string getCode();
    // conjunto de funções básicas de qqr nó 
    char getInfo();
    MinHeapNode * getRight();
    MinHeapNode * getLeft();
    void setRight(MinHeapNode * right);
    void setLeft(MinHeapNode * left);
    void addCode(char code);
    void setCode(string code);
};

#endif //TRABALHO_PARTE_2_MINHEAPNODE_H
