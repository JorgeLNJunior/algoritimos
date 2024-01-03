## Queue

Fila é uma estrutura de dados FIFO (first in first out) em que os novos elementos adicionados sempre estarão ao fim da lista, enquanto os elementos "mais antigos" sempre estarão no início. Filas permitem o processamento de dados de forma sequencial na ordem em que os dados foram inseridos. Além da fila comum existem diferentes tipos de filas como, fila de prioridade (priority queue), fila circular (circular queue) e fila aleatória (random queue).

## Métodos

- Enqueue O(1)
- Dequeue O(1)

## Implementação

Uma fila pode ser implementada usando tanto um array, quanto uma linked list.

### Linked list

A implemetação da linked list deve suportar um nó "tail" para que o processo de adicão de um item a fila seja executado em tempo constante, ou seja, O(1). Linked lists sem um nó "tail" levariam o método a ter um tempo de execução constante.

Para enfileirar um item simplesmente adicionamos no nó "tail" da linked list. Já para desenfileirar um item retiramos ele do nó "head".

### Array

A implementação usando um array aumenta a complexidade, já que é necessário armazenar e atualizar o primeiro e último índice do array que nos mostram que parte do array está ocupado com os items da fila.

## Vantagens

- Processamento de dados na ordem de inserção.
- Dados são obtidos em tempo constante - O(1).
