## Hash table

Hash table, também chamada de dicionário, é uma estrutura de dados que armazena pares de chave e valor.

Uma funcão de hash é executada para gerar um índice que indica onde os dados serão salvo dentro de um array. Em caso de colisões, ou seja, quando uma funcão de hash retorna um índice já ocupado, alguma técnicas podem ser usadas.

### Colisões

#### Chaining

Na técnica de chaining armazenados linked lists nos slots do array para lidar com colisões. Em caso de colisão, adicionamos um novo elemento na linked list daquele índice contento o par de chave e valor.

Essa abordagem torna necessária percorrer todos os elementos da linked list até que a chave desejada seja encontrada. No pior caso teríamos de percorrer toda a lista a cada operação (inserção, remoção e busca).

#### Open Adressing 

Na técnica de open adressing, armazaenamos os dados diretamente nos slots do array, quando nos deparamos com uma colisão podemos resolve-las procunado o próximo slot vazio do array e, então, inserindo o par de chave e valor.

Nas operações de busca por chave, devemos primeiramente verificar o slot do array indicado pela função de hash, caso a chave for diferente da que estamos buscando, devemos procurar no próximo slot até que as chaves sejam iguais ou o slot esteja vazio.

### Métodos

- Adicionar O(1).
- Remover O(1).
- Buscar O(1).

### Vantagens

- Operações em tempo constante.

### Desvantagens

- Funções de hash ineficientes podem gerar muitas colisões e desperdício de espaço.