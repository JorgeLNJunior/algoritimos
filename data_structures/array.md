## Array

Array é uma estrutura de dados que permite o armazenamento e leitura de uma coleção de dados do mesmo tipo. Os dados são armazenados de forma contínua em um espaço da memória alocada previamente e podem ser acessados e manipulados em tempo constante com uso de índices.

## Implementação

Para implementar um array, podemos alocar um espaço de memória que pode acomodar `n` elementos do mesmo tipo. `(sizeof(type) * n)`

Para acessar uma posição do array podemos fazer uso de índices. Podemos acessar cada índice do array usando aritimética de ponteiros. `(*(array + index))`

## Métodos

- Push O(1).
- Pop O(1).
- At O(1)
- Insert O(n).
- Find O(n).

## Vantagens

- Acesso rápido a qualquer item com uso de índices.
- Novos itens podem ser adicionados ao final em tempo constante.

## Desvantagens

- Remover um item requer que os items seguintes sejam movidos.
- Sua capacidade só pode ser aumentada se uma cópia de todo o array for feita.
- Só pode armazenar itens do mesmo tipo.