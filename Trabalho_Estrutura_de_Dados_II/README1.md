[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=7957152&assignment_repo_type=AssignmentRepo)
# Trabalho 1: Processamento de Texto

O objetivo desta tarefa é desenvolver um programa para ler e processar arquivos ASCII para encontrar as palavras mais usadas na língua portuguesa. Para isso iremos utilizar como base livros em língua portuguesa disponíveis em:  [Projeto Guteberg](https://www.gutenberg.org/browse/languages/pt) 

O Projeto Gutenberg (AO 1945: Projecto Gutenberg) (PG) é um esforço voluntário para digitalizar, arquivar e distribuir obras culturais através da digitalização de livros. Fundado em 1971, é a mais antiga biblioteca digital. A maioria dos itens no seu acervo são textos completos de livros em domínio público. O projeto tenta torná-los tão livres quanto possível, em formatos duradouros e abertos, que possam ser usados em praticamente quaisquer computadores [trecho obtido da wikipedia].

## Métodos
Há muitas maneiras de atingir esse objetivo, mas vamos usar uma tabela hash para contar o número de vezes que cada palavra única ocorre à medida que digitalizamos o arquivo ascii. Deve-se iniciar com uma tabela de hash vazia. Em seguida, você lerá uma palavra do arquivo ascii e inserirá essa palavra na tabela de hash. Se a palavra já for encontrada na tabela de hash, você incrementa o contador de palavras correspondente em vez de adicionar uma entrada duplicada. Se a palavra não for encontrada na tabela hash, insira uma nova entrada na tabela de hash com um contador de palavras definido como 1 (um). Quando você terminar de processar o documento, a tabela de hash conterá N palavras exclusivas e seus contadores de palavras associados.

Para encontrar as 50 palavras mais usadas no documento, seu programa deve copiar o conteúdo da tabela de hash em um vetor "words" e ordená-lo em ordem decrescente.

Existem várias questões-chave de design que devem ser abordadas neste trabalho: 
1. como ler o arquivo de texto e extrair as palavras individuais;
2. como armazenar e acessar pares de "(palavras,contagem)" na tabela de hash;
3. como extrair e classificar pares de "(palavras/contagem)" para identificar as 50 palavras mais usadas no documento.

Para esta tarefa, os alunos devem usar um encadeamento separado para implementar a tabela hash. 
Essa abordagem usa listas encadeadas para lidar com colisões na hash, portanto, os alunos devem 
implementar "list.cpp" no diretório src. 

### Tipo Abstrado de Dados: Tabela Hash

O tipo abstrato de dados hash com encadeamento separado deve conter as seguintes rotinas implementadas:
1. *Construtor*: Deve receber como entrada o tamanho *M* da tabela.
2. *Insere*    : O parametro de entrada deve ser um registro. 
3. *Busca*     : Dado a chave de busca, a rotina deve retornar o ponteiro para o registro procurado. A função deve retornar *nullptr* caso a busca seja invalida.
4. *Remove*    : Dada uma chave de busca, deve-se remover o registro da tabela hash.
5. ImprimeInfo : Imprime o número de colisões ocorridas nas inserções de dados na tabela ao usar uma determinada função hash.
6. *Destrutor* : desaloca toda a memoria ocupada pela tabela hash.

**IMPORTANTE**:
1. Implemente o TAD que permita o uso de diferentes funções hash. 

## Experimentos que devem ser realizados
 
### Caso 1: Testes Unitários

Criar casos de testes unitários para testar as rotinas da tabela hash. 
O grupo pode adotar um dos sistemas de testes unitários: CTest, Googletest e Catch 2.

### Caso 2: Funções Hash

O grupo deve fazer um estudo comparativo entre diferentes funções hash. Para tanto, deve-se escolher um 
texto disponível no Projeto Guteberg e indexar as palavras em tabelas hashes com funções distintas. O programa deve reportar o número de palavras e o total de colições para cada uma das funções testadas.

### Caso 3: Analisar o desempenho dos métodos de ordenação

Ao identificar as 50 palavras mais usadas de um livro, o grupo deve analisar o desempenho de pelo menos 3 métodos de ordenação. 
Sendo **obrigatoriamente** um deles o quicksort, o segundo pode ser qualquer outro método de ordenação visto em aula e o terceiro método de livre escolha do grupo, desde que não tenha sido visto em aula.  As métricas de desempenho são: número de comparações, número de movimentação e tempo de processamento.
Usar o método mais eficiente obtido nos pŕoximos casos.

### Caso 4: Identificar as 50 palavras mais usadas

O grupo deverá processar um conjunto de 10 livros. O programa deve ser capaz de:
  - Identificar as 50 palavras mais usadas de cada livro. Para cada livro, faça o processamento e escreva em um arquivo ascii as 50 palavras mais frequentes com suas respectivas contagens.

  - Identificar as 50 palavras mais usadas no total. Escreva em um arquivo ascii as 50 palavras mais frequentes no total com suas respectivas contagens ordenadas em ordem decrescente. Considere para essa atividade que 10 livros distintos devem ser processados.

Para padronizar a leitura dos dados, considere que os arquivos com os textos de entrada estejam dentro da pasta *input* do projeto raiz.  

**Observações**:
Palavras como artigos (o, a, um …), preposições (de, em, para, …) e pontuações (‘.’ , ‘ !’, ‘?’, ...) devem ser ignoradas nas contagens. 

## Entrega

- O grupo deve usar seu arquivo REPORT.md para explicar a abordagem empregada para solucionar a tarefa: como foi a distribuição das tarefas entre os membros,  escolhas de algorimos, o que funcionou ou o que não funcionou, mudanças de planos, etc. Tente resumir todas as diferentes maneiras pelas quais você desenvolveu, avaliou e melhorou seu código. 
- Mantenha o repositório do grupo sempre atualizado. O histórico de atualizações e as contribuições individuais será usado para verificar a distribuição de tarefas entre os membros do grupo. 
- Após o encerramento do prazo de entrega, o código que será avaliado será aquele que estiver no branch principal do grupo.
- Assim como o códig-fonte, o projeto cmake para a configuração e compilação do trabalho tem que estar disponível. 
- **Não é ncessário incluir a pasta build no repositório**.
 

## Critérios da avaliação:
 - (F) *Funcionalidade (50%)*: Será observado se todas as funcionalidades estão gerando os resultados esperados de acordo com a especificação dada acima; se a especificação for ambígua e você tiver que fazer uma determinada escolha, defenda essa escolha em seu arquivo REPORT.
 - (D) *Desempenho (15%)*: refere-se a quão rápido e/ou utilização eficiente de memória seu programa pode produzir os resultados requeridos em comparação com outras submissões.
 - (T) *Testes (10%)*    : refere-se adequação dos testes de unidade para todas as classes de estrutura de dados desenvolvidos nesta tarefa.
 - (E) *Estilo  (15%)*   : refere-se ao estilo de programação C/C++, incluindo coisas como identação consistente, nomes de identificadores apropriados, comentários úteis, etc.
 - (O) *Organização (10%)*: refere-se a estruturação do projeto, diretórios, projeto cmake, etc

Nota final calculada será dada então por: 
 - NF = (F + D + T + E + O)* I.

Onde I é o fator de contribuição individual que vai variar entre 0 e 1. 

