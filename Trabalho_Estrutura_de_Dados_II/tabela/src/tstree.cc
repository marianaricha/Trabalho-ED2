#include "../include/tstree.h"
#include <iostream>
#include <string>

using namespace std;


TSTree::TSTree(){
    this->root = nullptr;
}

TSTree::~TSTree(){
    //preciso procurar como fica esse destrutor
}

bool TSTree::isEmpty(){
    return root == nullptr;
}

void TSTree::makeEmpty(){
    this->root = nullptr;
}

void TSTree::deleta(string word){
    deleta(this->root, word, 0);
}

void TSTree::deleta(TSTNode* r, string word, int p){

    if (r == nullptr){  
        return;   
    }
    if (word[p] < r->data){  
        deleta(r->left, word, p); 
    } 
    else if (word[p] > r->data){
        deleta(r->right, word, p);
    }  
    else  
    {  
        /** to delete a word just make isEnd false **/  
        if (r->isEnd && p == word.length() - 1){ 
            r->isEnd = false;  
        }    
        else if (p + 1 < word.length()){  
            deleta(r->middle, word, p + 1);
        }  
    }          
}

void TSTree::insert(string word){
    this->root = insert(this->root, word, 0);
}

TSTNode* TSTree::insert(TSTNode* r, string word, int p){

    if (r == nullptr){  
        TSTNode* aux = new TSTNode(word[p]); 
        r = aux;
    } 
    if (word[p] < r->data)  
        r->left = insert(r->left, word, p);  
    else if (word[p] > r->data)  
        r->right = insert(r->right, word, p);  
    else  
    {  
        if (p + 1 < word.length())  {
            r->middle = insert(r->middle, word, p + 1);  
        }
        else  {
            r->isEnd = true;  
        }  
    }
    return r;  
}

bool TSTree::search(string word){
    return search(this->root, word, 0);
}

bool TSTree::search(TSTNode* r, string word, int p){
    if (r == nullptr)  
            return false;  
        if (word[p] < r->data)  
            return search(r->left, word, p);  
        else if (word[p] > r->data)  
            return search(r->right, word, p);  
        else  
        {  
            if (r->isEnd && p == word.length() - 1)  
                return true;  
            else if (p == word.length() - 1)
                return false;  
            else  
                return search(r->middle, word, p + 1);  
        }          
}

//para printar 
void TSTree::toString(){
    this->a = vector<string>();  
    traverse(root, "");
    for(int i= 0; i<a.size(); i++)
    {
        cout << a.at(i) << " | ";
    }  
}

//para printar 
void TSTree::toString(string arquivo_saida){  
    ofstream arq_out;
    arq_out.open(arquivo_saida);
    if(!arq_out.is_open())
    {
        std::cout << "FALHA AO ABRIR ARQUIVO DE SAIDA" << endl;
        exit(-1);
    }

    this->a = vector<string>();  
    traverse(root, "");
    for(int i= 0; i<a.size(); i++)
    {
        cout << a.at(i) << " | ";
        arq_out << a.at(i) << " | ";
    }  
}

//para percorrer
void TSTree::traverse(TSTNode* r, string str){  
        if (r != nullptr)
        {  
            traverse(r->left, str);  
            str = str + r->data;  
            if (r->isEnd)  
                a.push_back(str);   //adiciona na lista
            traverse(r->middle, str);  
            str = str.substr(0, str.length() - 1);   
            traverse(r->right, str);  
        }  
    }  
