## Linked list

Linked list é uma estrutura de dados em que cada elemento da está ligado ao elemento seguinte, o que permite o acesso a uma lista de dados de forma sequêncial.

## Métodos

- At O(n).
- Push front O(1)
- Pop font O(1).
- Push back O(1).
- Pop back O(1).
- At front O(1).
- At back O(1).
- Insert O(n).
- Remove O(n).
- Reverse O(n).

## Implementação

Uma linked list pode ser implementada usando dois nós, um head e um tail. Cada nó contém duas propriedades, value e next. A propriedade value armazena o valor a ser inserido na linked list, enquanto next é um ponteiro para o próximo elemento da lista.

Os nós tail e head são nós auxiliares. A propriedade next do nó head aponta para o primeiro elemento da lista, enquanto o next do nó tail aponta para o último. O nó tail é opicional, mas ele facilita a implementação de uma fila usando a linked list.

## Vantagens

- A lista pode ser reorganizada de forma mais rápida.

## Desvantagens

- A única maneira de acessar um item é seguindo os nós até que o item seja encontrado.
