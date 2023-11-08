// #ifndef HASH_H__
// #define HASH_H__

// #include <vector>
// #include <list.h>
// #include <iostream>

// #include "sort.h"
// #include "palavra.h"
// #include "list.h"

// using namespace std;

// #define MASK_EMPTY   0
// #define MASK_FILLED  1
// #define MASK_DELETED 2
// #define HASH_KEY_SIZE 49

// typedef enum {QUICKSORT, MERGESORT, COMBSORT} sort_met;

// class Hash
// {
//     public:
//         Hash(int size, int (*hash)(const char *key));
//         ~Hash();
//         int Busca(const char *key);
//         bool Existe(int index);
//         int Insere1(const char *key);
//         int Insere2(const char *key, int cont);
//         int Remove(const char *key);
//         void ImprimeInfo(); 
//         vector<Palavra> OrdenaTabela(sort_met metodo);
//         List *operator[](int index) {return this->tabelaHash[index];}
        
//     private:
//         int (*_hash)(const char *key);
//         List **tabelaHash;
//         int tamHash;
//         int colisoesHash;
//         vector<int> indexPreenchidos;
// };

// #endif /* HASH_H__ */