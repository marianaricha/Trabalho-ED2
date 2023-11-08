#ifndef TRABALHO_PARTE_2_HUFFMAN_H
#define TRABALHO_PARTE_2_HUFFMAN_H
#include "queue"
#include "minheapnode.h"
#include "iostream"
#include <fstream>
using namespace std;

struct compare { // utilizado para auxiliar a comparar as frequências
    bool operator()(MinHeapNode * l, MinHeapNode * r){
        return (l->getFreq() > r->getFreq());
    }
};

class Huffman{
private:
    ifstream* livro;
    MinHeapNode * root;
    unsigned int nEntrada;
    unsigned int nSaida;
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> frequencyQueue;
    void escreveCSVAux(MinHeapNode * aux, string code, ofstream& csv_file);
    void contFreq();
    void huffmanTree();
    void Codifica();
    void CodificaAux(MinHeapNode * aux, string code);
    void calculaBits();
    void mapCodes();
    // void printFrequencyQueue();
    // void printFrequencyQueue(priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> queue);
    // void printCodesRec(MinHeapNode * aux, string code);

public:
    Huffman(ifstream & book);
    double compressao();
    void imprimeResultados();
    void escreveCSV(ofstream& csv_file);
    void salvaTextCodificado(ofstream& bin_file);
    void Decodifica(ifstream& orig_file, ostream& dest_file);
    // void travelTree();
    // void printCodes();
};

#endif //TRABALHO_PARTE_2_HUFFMAN_H
