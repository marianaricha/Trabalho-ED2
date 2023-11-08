#ifndef TSTREE_H
#define TSTREE_H

#include "tstNode.h"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class TSTree
{
    friend class TSTNode;
    public:
        TSTree();
        ~TSTree();
        bool isEmpty();
        void makeEmpty();
        void insert(string word);
        TSTNode* insert(TSTNode* r, string word, int p);
        void deleta(string word);
        void deleta(TSTNode* r, string word, int p);
        bool search(string word);
        bool search(TSTNode* r, string word, int p);
        void toString();
        void toString(string arquivo_saida);
        void traverse(TSTNode* r, string str);
        //string print();
        //void traverse(TSTNode r, String str);

        private:
            TSTNode* root;
            vector<string> a;
};


#endif