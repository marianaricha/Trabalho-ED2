#ifndef HASH_H__
#define HASH_H__

#include <cstring>
#include <vector>
#include <list.h>
#include <iostream>

#include "sort.h"
#include "palavra.h"
#include "list.h"

using namespace std;

#define MASK_EMPTY   0
#define MASK_FILLED  1
#define MASK_DELETED 2
#define HASH_KEY_SIZE 49

typedef enum {QUICKSORT, MERGESORT, COMBSORT} sort_met;

class HashData
{
    friend class Hash;
  public:
    HashData(): flag(MASK_EMPTY), local(0) {
        // memset(chave, 0, HASH_KEY_SIZE);
    }
    HashData(string key, unsigned int pos) : 
        local(pos),
        flag(0),
        contador_chave(0)
    {
        // strcpy(chave, key);
        chave = key;
    }
    
    string         chave;
    unsigned int   local;
    unsigned short flag;
    unsigned int   contador_chave;
};

/**
 * @brief Classe que implementa o algoritmo de hash.
 *        Com sondagem linear.
 * */

class Hash
{
    public:
        Hash(int size, int (*hash)(string  key));
        int Busca(string key);
        int Insere1(string key, unsigned int position);
        int Insere2(string key, unsigned int position, int cont);
        int Remove(string key);
        void ImprimeInfo(); 
        vector<Palavra> OrdenaTabela(sort_met metodo);
        HashData& operator[](int index) { return tabelaHash[index]; }
        ~Hash();
        
    private:
        int (*_hash)(string key);
        vector<HashData> tabelaHash;
        int tamHash;
        int colisoesHash;
        vector<int> indexPreenchidos;
};

#endif /* HASH_H__ */