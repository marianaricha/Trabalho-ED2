<!-- INTRODUÇÃO
O trabalho consistia em desenvolver um programa para ler e processar arquivos 
ASCII para encontrar as palavras mais usadas na língua portuguesa. Para isso, 
tentamos usar a tabela hash com encadeamento separado para o tratamento de colisões 
(implementado em list.h e list.cc).


DISTRIBUIÇÃO DAS TAREFAS
As tarefas foram separadas entre os membros mas na maioria das vezes foram 
feitas em conjunto por ligação (a implementação das rotinas fundamentais 
"Construtor","Insere"(erro), "Busca", "Remove", "ImprimeInfo" e "Destrutor" foram 
feitas totalmente em conjunto).

Maria Eduarda Ribeiro: OrdenaTabela, organização do código, testes unitários 
Gustavo Carvalhaes: funções Hash, lista encadeada
Vitor Fernandes: CombSort, leitura dos arquivos, arquivos de livros
Mariana Richa:Insere2, leitura dos arquivos, arquivos de livros


ABORDAGENS EMPREGADAS PARA SOLUCIONAR A TAREFA
Foram apresentados três métodos de ordenação: MergeSort, QuickSort e o CombSort 
(que não foi visto em aula). Foi analisado o desempenho de cada método através 
das métricas: tempo de execução (time), número de comparções (n_comp) e número 
de movimentações (n_mov). Verificamos que o QuickSort é o método mais vantajoso, 
logo foi o utilizado a partir do segundo livro (no primeiro foram testados os 
três métodos).
Tentamos implementar a tabela hash por meio de encadeamento linear através da 
classe list.h, porém não conseguimos aplicar os métodos na hash.h no tratamento 
das colisões. Assim, utilizamos o algoritmo de sondagem linear para resolver o problema.
Deixamos salvos os arquivos hash2.h, hash2.cc, list.h, list.cc, Node.h e Node.cc para 
que sejam visualizados.

Questões-chave de design:
Para ler o arquivo de texto e extrair as palavras individuais utilizamos um 
vetor de strings para armazenar as palavras de cada linha com funções para 
identificar artigos, preposições, espaços e pontuações.
Para armazenar e acessar pares de "(palavras,contagem)" na tabela de hash 
fizemos a inserção a partir do vetor de palavras (a função que insere verifica 
se as palavras são repetidas,etc).
Para extrair e classificar pares de "(palavras/contagem)" para identificar as 50 
palavras mais usadas no documento foi feita a ordenação  em ordem decrescentecom 
o método mais vantajoso (QuickSort) e foram selecionadas as 50 primeiras 
palavras (que mais repetem) e, em seguida, colocadas em um arquivo com "palavra;
número de repetições".

Testes Unitários:
(foi utilizado o CMake)
Teste 1: faz a seleção das 50 palavras mais repetidas de cada livro (fazendo o 
teste dos 3 métodos de ordenação no primeiro) e depois as armazena em um 
arquivo. Então, coloca todas as palavras de cada arquivo em uma Hash, ordenando 
novamente e verificando as 50 palavras mais usadas em todos os livros.
Teste 2: testa as rotinas fundamentais da tabela Hash.
Teste 3: compara as 4 funções Hash.

Através dos testes foi possível ver os erros e corrigí-los. Mudamos diversas 
vezes o algoritmo para que funcionasse da maneira que queríamos e fizemos muitas 
pesquisas para encontrar novas maneiras que fossem efetivas na solução dos 
problemas. 

-------------------------------------------------------------------------------

Construção da build:

cmake -B build

Compilação e Execução:

cd build
make
./tests/test1
./tests/test2
./tests/test3 -->
