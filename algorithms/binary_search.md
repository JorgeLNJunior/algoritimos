## Binary Search

Binary search é um eficiente algoritimo de busca baseado na estratégia de divisão e conquista. Seu tempo de execução é O(log n).

### Implementação

O algoritimo verifica se o elemento no meio da lista é igual ao elemento procurado, se ele for maior a função é chamada de forma recursiva, mas desta vez passando somente o lado esquedo da lista a partir do índice do meio. Caso seja menor, o mesmo acontece mas passando o lado direito. O algoritimo é repetido até que o valor seja encontrado, retornando o índice onde ele se encontra. Caso o elemento não for encontrado a função retorna -1.

### Vantagens

- Busca em O(log n).

### Exemplo

<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/c/c1/Binary-search-work.gif/220px-Binary-search-work.gif" width="200px" />

