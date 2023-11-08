// #include "hash.h"

// Hash::Hash(int size, int (*hash)(const char *key))
// {

//     this->tamHash = size;
//     this->_hash = hash;
//     this->colisoesHash = 0;
//     this->tabelaHash = new List*[size];

//     for (int i = 0; i < size; i++)
//     {
//         tabelaHash[i] = new List();
//     }
// }

// Hash::~Hash()
// {
//     for(int i = 0; i < indexPreenchidos.size(); i++)
//     {
//         this->tabelaHash[indexPreenchidos[i]]->~List();
//     }
// }

// int Hash::Busca(const char *key)
// {
//     int index;
//     index = abs(_hash(key) % tamHash);//calcula o index baseado na chave

//     if(this->tabelaHash[index]->busca(key))// busca a chave na lista do index 
//     {
//         return index;// se achou retorna o index
//     }
//     return -1;// senão retorna -1
// }


// bool Hash::Existe(int index)
// {
//     for(int i=0; i < indexPreenchidos.size(); i++){
//         if(indexPreenchidos[i] == index){
//             return true;
//         }
//     }
//     return false;
// }

// int Hash::Insere1(const char *key)//insere a chave no final da lista q ela pertence
// {
//     int index;
//     index = abs(_hash(key) % tamHash);//calcula o index baseado na chave

//     if(!this->tabelaHash[index]->vazio()){//verificar se tem colisão
//         this->colisoesHash++;// se tiver incrementa
//     }

//     if(this->tabelaHash[index]->busca(key)){//se já existir a chave na lista
//         this->tabelaHash[index]->getNode(key)->incrementCont();//aumenta o contador de repetição
//         return -1;
//     }
//     else{// se não achar, adiciona a chave na lista
//         this->tabelaHash[index]->insertUltimo(key);
//         this->tabelaHash[index]->getNode(key)->setCont(1);
//         if(!Existe(index)){
//             indexPreenchidos.push_back(index);
//         }
//         return index;
//     }
// }

// int Hash::Insere2(const char *key, int cont)
// {
//     int index;
//     index = abs(_hash(key) % tamHash);//calcula o index baseado na chave

//     if(!this->tabelaHash[index]->vazio()){//verificar se tem colisão
//         this->colisoesHash++;//incrementa se houver
//     }

//     if(this->tabelaHash[index]->busca(key)){//se já existir a chave na lista
//         this->tabelaHash[index]->getNode(key)->setCont(this->tabelaHash[index]->getNode(key)->getCont()+cont);//aumenta o contador de repetição
//         return -1;
//     }
//     else{// se não achar adiciona a chave na lista
//         this->tabelaHash[index]->insertUltimo(key);
//         this->tabelaHash[index]->getNode(key)->setCont(cont);
//         if(!Existe(index)){
//             indexPreenchidos.push_back(index);
//         }
//         return index;
//     }
// }

// auto findIndex(vector<int> &arr, int item) {

//     for (auto i = 0; i < arr.size(); ++i) {
//         if (arr[i] == item)
//             return i;
//     }

//     return -1;
// }

// int Hash::Remove(const char *key)
// {
//     int index;
//     index = abs(_hash(key) % tamHash);//calcula o index baseado na chave

//     if(this->Busca(key) != -1){
//         this->tabelaHash[index]->deleta(key);
//         if(this->tabelaHash[index]->vazio()){
//             indexPreenchidos.erase(indexPreenchidos.begin()+findIndex(indexPreenchidos, index));
//         }
//         return index;
//     }
//     else{
//         cout << "Palavra não encontrada" << endl;
//         return -1;
//     }
// }

// void Hash::ImprimeInfo(){
//     cout<< "Número de colisões: "<< this->colisoesHash<< endl;
// }

// bool compara(Palavra &a, Palavra &b){
//     // se o segundo for maior que o primeiro vai ocorrer troca
//     return b.getCont() > a.getCont();
// }

// vector<Palavra> Hash::OrdenaTabela(sort_met metodo)
// {
//     cout << "entrou na ordenação" << endl;
//     vector<Palavra> words;

//     for(int i = 0; i < indexPreenchidos.size(); i++)
//     {
//         for(int j=0; j < tabelaHash[indexPreenchidos[i]]->getTamanho(); j++){
//             Palavra word(this->tabelaHash[indexPreenchidos[i]]->get(j)->getChave(), this->tabelaHash[indexPreenchidos[i]]->get(j)->getCont());
//             words.push_back(word);
//         }
//     }

//     int tam = words.size();
//     Palavra* aux_words = words.data();
    
//     switch (metodo)
//     {
//     case QUICKSORT:
//         quick_sort<Palavra>(aux_words, tam, compara);
//         break;
//     case MERGESORT:
//         merge_sort<Palavra>(aux_words, tam, compara);
//         break;
//     case COMBSORT:
//         comb_sort<Palavra>(aux_words, tam, compara);
//         break;
//     default:
//         cout << "Método de ordenação não encontrado" << endl;
//         break;
//     }

//     words.clear();
//     for(int i = 0; i < tam; i++)
//         words.push_back(aux_words[i]);

//     cout << "saiu da ordenação" << endl;
//     return words;
// }