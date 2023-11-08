#include <sstream>
// #include <map>
#include "../include/huffman.h"
#include "iostream"
#define tam 28
#define espaco 27

Huffman::Huffman(ifstream & livro) {

    if(livro.is_open()){
        this->nSaida = 0;
        this->nEntrada = 0;
        this->livro = &livro;

        contFreq(); // ve a frenquencia dos caracteres      
        huffmanTree(); // cria a árvore de huffman
        Codifica(); // gera os códigos de 0 1 para cada caracter
        calculaBits(); // realiza as contas dos bits
    }
    else{
        cout << "Não foi possível abrir o arquivo" << endl;
        exit(404);
    }
}

// conta a frenquência de cada caractere
void Huffman::contFreq() {
    stringstream aux;
    string line;
    string word;
    // Array usado para auxiliar na contagem de frequencia de cada caractere
    MinHeapNode* vetorFreq[tam];
    // inicializa o vetor vetorFreq com nullptr
    for(int i = 0 ; i < tam; i++){
        vetorFreq[i] = nullptr;
    }
    // Tratamento para espaço
    vetorFreq[espaco] = new MinHeapNode(' ', 0);

    while(this->livro->peek() != EOF){
        aux.clear();
        getline(*this->livro, line);
        aux << line;
        // Tratamento para inserir espaço na tabela
        for(int i = 0 ; i < line.length() ; i++){
            if(line[i] == ' '){
                vetorFreq[espaco]->incrementaFreq();
            } 
        }

        // armazena palavra por palavra
        while(aux >> word){
            // coloca tudo para minúsculo
            for (int i = 0; i < word.length(); i++){
                if (isupper(word[i])){
                    word[i] = tolower(word[i]);
                }
            }

            string clear_string = "";

            // remove todos os caracteres fora do alfabeto minúsculo
            for (int i = 0; i < word.length(); i++){
                if(word[i] >= 97 && word[i] <= 122){
                    clear_string += word[i];
                } 
            }

            // armazena os caracteres em pos. nula no vetor de frequencia
            // faz um incremento se a posição é não nula
            for(int i = 0; i < clear_string.length(); i++){
                int index = clear_string[i] - 'a';
                if(vetorFreq[index] != nullptr){
                    vetorFreq[index]->incrementaFreq();
                }
                else{ // alocando um nó para armazenar no vetorFreq
                    MinHeapNode * newNode = new MinHeapNode(clear_string[i], 1);
                    vetorFreq[index] = newNode;
                }
            }
        }
    }

    // todos os valores não null são inseridos na fila de prioridade
    for(int i = 0 ; i < tam; i++){
        if(vetorFreq[i] != nullptr){
            frequencyQueue.push(vetorFreq[i]); // função para add na fila
        }
    }
}

// construção da árvore de huffman
void Huffman::huffmanTree() {

    //instancia uma fila_aux
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> fila_aux = this->frequencyQueue;

    // diversos passos ocorrem nessa função: (LEMBRAR)

    // - os nós estão ordenados de forma decrescente na fila de prioridade
    // - para ir formando a árvore, basta remover o último nó, colocar na 
    // esquerda, depois o penúltimo, colocar na direita
    // - criar um nó pai com um caracter fora do alfabeto e colocar sua FREQ como a soma dos dois 
    // - colocar esse nó pai na fila novamente para ele ser usado na próxima iteração
    // oq sobrar é a raiz

    while(fila_aux.size() != 1){

        MinHeapNode * filhoEsq = fila_aux.top(); // coloca o topo como filho à esquerda
        fila_aux.pop(); // remove da fila

        MinHeapNode * filhoDir = fila_aux.top(); // coloca o topo como filho à direita
        fila_aux.pop(); // remove da fila
        MinHeapNode * pai = new MinHeapNode('?', filhoEsq->getFreq()+filhoDir->getFreq());
        //ajusta a frequência 
        pai->setLeft(filhoEsq);// atribui a parternidade
        pai->setRight(filhoDir);// atribui a paternidade
        fila_aux.push(pai); // coloca de volta na fila
    }

    this->root = fila_aux.top(); // a sobra é a raiz (root)
}

// coloca os códigos de 0 1 em cada nó 
void Huffman::Codifica() {
    CodificaAux(this->root, "");
}

//função recursiva auxiliar
void Huffman::CodificaAux(MinHeapNode * aux, string code) {
    if(aux == nullptr){// retorna quando não tem filho
        return;
    }

    if(aux != this->root){// seta o código
        aux->setCode(code);
    }

    CodificaAux(aux->getLeft(), code + "0"); //chamada recursiva passando esquerda com 0 no código
    CodificaAux(aux->getRight(), code + "1"); //chamada recursiva passando direita com 1 no código
}

//função pública para chamar a escrita no csv
void Huffman::escreveCSV(ofstream & csv_file) {
    csv_file << "carac;freq;cod";
    this->escreveCSVAux(this->root, "",csv_file);
}

//função interna auxiliar e recursiva para fazer a escrita no csv
void Huffman::escreveCSVAux(MinHeapNode * aux, string code, ofstream& csv_file) {
    if(aux == nullptr)
        return;

    if(aux->getInfo() != '?')
        csv_file << endl << aux->getInfo() << "|" << aux->getFreq() << "|" << aux->getCode();

    escreveCSVAux(aux->getLeft(), code + "0", csv_file);
    escreveCSVAux(aux->getRight(), code + "1", csv_file);
}

void Huffman::salvaTextCodificado(ofstream& bin_file) {
    // faz uma fila aux 
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> aux = this->frequencyQueue;
    MinHeapNode * vetNodes[tam]; 
    for(int i = 0 ; i < tam; i++){ //inicializando o vetor com nullptr
        vetNodes[i] = nullptr;
    }

    //fazendo um tratamento para caso tenha espaços
    while(!aux.empty()){
        if(aux.top()->getInfo() == ' '){
            vetNodes[espaco] = aux.top();
        }
        else{
            vetNodes[aux.top()->getInfo() - 'a'] = aux.top();
        }
        aux.pop();
    }

    this->livro->clear();
    this->livro->seekg(0);

    // faz a leitura dos caracteres 
    // transforma tudo em minúsculo
    // se estiver no alfabeto minúsculo o código é salvo 
    char ch;
    while(*this->livro >> noskipws >> ch){

        ch = tolower(ch);

        if(ch == ' '){
            bin_file << vetNodes[espaco]->getCode();
        }
        else if(ch >= 97 && ch <= 122){
            bin_file << vetNodes[ch - 'a']->getCode();
        }
    }
}

//função q decodifica o que está escrito codificado
void Huffman::Decodifica(ifstream& orig_file, ostream& dest_file){
    if(!orig_file.is_open()){
        cout << "Nao foi possivel abrir arquivo" << endl; // acredito q o arquivo precisaria estar comprimido
        return;
    }

    // - desce na árvore a partir da raiz 
    // - quando o nó não possui filhos, escreve no arquivo e retorna para a raiz
    else{
        MinHeapNode * atual = this->root;
        char carac;
        while (orig_file >> noskipws >> carac){

            if(carac == '0'){
                atual = atual->getLeft();
            }

            else{
                atual = atual->getRight();
            }

            if(atual->getLeft() == nullptr && atual->getRight() == nullptr){
                dest_file << atual->getInfo();
                atual = this->root;
            }

        }
    }
}

// avalia o número de entrada e saída de bytes
void Huffman::calculaBits(){

// a saída precisa ser cálculada de outra forma: 
// - deve ser uma mult do tamanho da saida de bits * pela quant de repetições e dividido por 8, pq 1 byte tem 8 bits 

    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> aux = this->frequencyQueue;
    int nSaida = 0;

    while(!aux.empty()){
        nEntrada += aux.top()->getFreq();
        nSaida += aux.top()->getCode().length() * aux.top()->getFreq();
        aux.pop();
    }
    this->nSaida = (double) nSaida / 8;
}

double Huffman::compressao() {
    return ( (double) (nEntrada - nSaida) / nEntrada);
}

void Huffman::imprimeResultados(){
    cout << endl;
    cout << "Entrada: " << nEntrada << endl;
    cout << "Saída: "<< nSaida << endl;
    cout << "Percentual de compressão: " << compressao() * 100 << "%" << endl;
    cout << endl;
}

/* Funcoes extras */

// void Huffman::printFrequencyQueue(){
//     priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> aux = this->frequencyQueue;
//     cout << endl;
//     while(!aux.empty()){
//         cout << aux.top()->getInfo() << " [" << aux.top()->getFreq()<< "] | ";
//         aux.pop();
//     }
// }

// void Huffman::printFrequencyQueue(priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> queue){
//     priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> aux = queue;
//     cout << endl;
//     while(!aux.empty()){
//         cout << aux.top()->getInfo() << " [" << aux.top()->getFreq()<< "] | ";
//         aux.pop();
//     }
// }

// void Huffman::travelTree(){
//     MinHeapNode * atualPosition = root;
//     bool proxNode = 0;
//     cout << "Digite ' 0 ' para ir para sub-arvore a esquerda " << endl;
//     cout << "Digite ' 1 ' para ir para sub-arvore a direita ";


//     while(atualPosition != nullptr){
//         cout << endl << "\t" << atualPosition->getInfo() << " - " << atualPosition->getFreq() << endl;

//         if(atualPosition->getLeft() != nullptr)
//             cout << atualPosition->getLeft()->getInfo() << " - " << atualPosition->getLeft()->getFreq();
//         else
//             cout << "NULL";

//         if(atualPosition->getRight() != nullptr)
//             cout << "\t|\t" << atualPosition->getRight()->getInfo() << " - " << atualPosition->getRight()->getFreq() << endl;
//         else
//             cout << "\t|\tNULL";
//         cin >> proxNode;
//         if(proxNode){
//             atualPosition = atualPosition->getRight();
//         }else{
//             atualPosition = atualPosition->getLeft();
//         }
//     }
// }

// void Huffman::printCodesRec(MinHeapNode *aux, string code) {
//     if(aux == nullptr){
//         return;
//     }

//     if(aux->getInfo() != '?'){
//         cout << aux->getInfo() << "\t" << aux->getFreq() << "\t" << code << endl;
//     }

//     printCodesRec(aux->getLeft(), code + '0');
//     printCodesRec(aux->getRight(), code +'1');
// }

// void Huffman::printCodes(){
//     cout << endl << "char\tfreq\tcode" << endl;
//     this->printCodesRec(this->root, "");
// }