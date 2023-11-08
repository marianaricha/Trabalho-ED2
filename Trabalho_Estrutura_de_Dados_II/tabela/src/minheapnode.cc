#include "../include/minheapnode.h"
#include <iostream>
using namespace std;

MinHeapNode::MinHeapNode(char info, unsigned int freq) {
    this->info = info;
    this->freq = freq;
    this->left = nullptr;
    this->right = nullptr;
    this->code = "";
}

MinHeapNode::~MinHeapNode() {}

unsigned int MinHeapNode::getFreq() {
    return this->freq;
}

void MinHeapNode::incrementaFreq() {
    this->freq++;
}

char MinHeapNode::getInfo(){
    return this->info;
}

MinHeapNode * MinHeapNode::getRight() {
    return this->right;
}

MinHeapNode * MinHeapNode::getLeft() {
    return this->left;
}

void MinHeapNode::setRight(MinHeapNode *right) {
    this->right = right;
}

void MinHeapNode::setLeft(MinHeapNode *left) {
    this->left = left;
}

void MinHeapNode::setCode(string code) {
    this->code = code;
}

void MinHeapNode::addCode(char code) {
    this->code += code;
}

string MinHeapNode::getCode(){

    if(this->code.empty())
        return "";

    else
        return this->code;
}