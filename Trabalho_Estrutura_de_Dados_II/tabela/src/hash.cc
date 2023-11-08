#include "hash.h"

Hash::Hash(int size, int (*hash)(string key))
{
    tabelaHash.resize(size);
    colisoesHash = 0;
    tamHash = size;
    _hash = hash;
    for(int i = 0; i < tamHash; i++)
    {
        tabelaHash[i].flag = MASK_EMPTY;
        tabelaHash[i].contador_chave = 0;
    }
}

int Hash::Busca(string key)
{
    int i     = 0;
    int h1 = abs(_hash(key) % tamHash);
    int index;

    while(true){
        index = (h1 + i) % tamHash;

        if(tabelaHash[index].flag == MASK_EMPTY)
            return -1;

        if(tabelaHash[index].chave == key)
            return index;
        else{
            i++;
            if(i == tamHash)
                return -1;
        }
    }
}

int Hash::Insere1(string key, unsigned int position)
{
    int i     = 0;
    int h1 = abs(_hash(key) % tamHash);
    int index;

    while(true){
        index = (h1 + i) % tamHash;
        
        if(tabelaHash[index].flag == MASK_EMPTY || tabelaHash[index].flag == MASK_DELETED){
            if(Busca(key) == -1){
                tabelaHash[index].chave = key;
                tabelaHash[index].local = position;
                tabelaHash[index].flag = MASK_FILLED;
                tabelaHash[index].contador_chave = 1;
                indexPreenchidos.push_back(index);
                return index;
            }
            tabelaHash[index].contador_chave++;
            return -1;
        }
        else{
            i++;
            colisoesHash++;
        }
        if(i == tamHash)
            return -1;
    }
}  

int Hash::Insere2(string key, unsigned int position, int cont)
{
    int i     = 0;
    int h1 = abs(_hash(key) % tamHash);
    int index;

    while(true){
        index = (h1 + i) % tamHash;
        
        if(tabelaHash[index].flag == MASK_EMPTY || tabelaHash[index].flag == MASK_DELETED){
            if(Busca(key) == -1){
                tabelaHash[index].chave = key;
                tabelaHash[index].local = position;
                tabelaHash[index].flag = MASK_FILLED;
                tabelaHash[index].contador_chave = cont;
                indexPreenchidos.push_back(index);
                return index;
            }
            tabelaHash[index].contador_chave += cont;
            return -1;
        }
        else{
            i++;
            colisoesHash++;
        }
        if(i == tamHash)
            return -1;
    }
}  

auto findIndex(vector<int> &arr, int item) {

    for (auto i = 0; i < arr.size(); ++i) {
        if (arr[i] == item)
            return i;
    }

    return -1;
}

int Hash::Remove(string key)
{
    int index = Busca(key);
    if(index != -1)
    {
        tabelaHash[index].flag = MASK_DELETED;
        for (int i=0; i<50; i++)
            tabelaHash[index].chave[i] = *"";
        tabelaHash[index].contador_chave = 0;
        indexPreenchidos.erase(indexPreenchidos.begin() + findIndex(indexPreenchidos, index));
        return index;
    }
    return -1;
}

void Hash::ImprimeInfo(){
    cout<< "Número de colisões: "<< colisoesHash<< endl;
}

bool compara(Palavra &a, Palavra &b){
    // se o segundo for maior que o primeiro vai ocorrer troca
    return b.getCont() > a.getCont();
}

vector<Palavra> Hash::OrdenaTabela(sort_met metodo)
{
    vector<Palavra> words;

    for(int i = 0; i < indexPreenchidos.size(); i++)
    {
        Palavra word(tabelaHash[indexPreenchidos[i]].chave, tabelaHash[indexPreenchidos[i]].contador_chave);
        words.push_back(word);
    }

    int tam = words.size();
    Palavra* aux_words = words.data();
    
    switch (metodo)
    {
    case QUICKSORT:
        quick_sort<Palavra>(aux_words, tam, compara);
        break;
    case MERGESORT:
        merge_sort<Palavra>(aux_words, tam, compara);
        break;
    case COMBSORT:
        comb_sort<Palavra>(aux_words, tam, compara);
        break;
    default:
        cout << "Método de ordenação não encontrado" << endl;
        break;
    }

    words.clear();
    for(int i = 0; i < tam; i++)
        words.push_back(aux_words[i]);

    return words;
}

Hash::~Hash()
{
    tabelaHash.clear();
}
