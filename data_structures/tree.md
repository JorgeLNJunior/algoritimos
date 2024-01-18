## Tree

Tree, ou árvore, é uma estrutura de dados composta por nós, cada nó pode conter dois nós filhos, um a esquerda e outro a direita.

### Percorrendo árvores

Árvore é uma estrutura de dados não linear, por isso precisamos armazenar os nós em alguma outra estutura de dados para visitá-los depois usando algum algorítimo, podendo ser recursivo ou não. As principais estruturas de dados usadas para isso são queue e stack.

Os principais métodos para percorrer árvores são:

#### Depth-first

No método depth-first percorremos uma sub-árvore completamente antes de percorrer os nós irmãos. Cada nó é adicionado a uma pilha de onde podem ser lidos.

Para percorrer uma árvore com depth-first podemos usar alguns algoritimos:

##### Pre-order

1. Se o nó atual estiver vazio retorne.
2. Visite o nó atual.
3. Percorra recursivamente a sub-árvore a esquerda. 
4. Percorra recursivamente a sub-árvore a direita. 

Tempo de execução: O(n)

Exemplos

<iframe width="560" height="315" src="https://www.youtube.com/embed/1WxLM2hwL-U?si=7_LoOKmQz1dRtc2w" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

##### Post-order

1. Se o nó atual estiver vazio retorne.
2. Percorra recursivamente a sub-árvore a esquerda. 
3. Percorra recursivamente a sub-árvore a direita. 
4. Visite o nó atual.

Tempo de execução: O(n)

Exemplos

<iframe width="560" height="315" src="https://www.youtube.com/embed/4zVdfkpcT6U?si=81xzlu_dW0yzOg4w" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

##### In-order

1. Se o nó atual estiver vazio retorne.
2. Percorra recursivamente a sub-árvore a esquerda. 
3. Visite o nó atual.
4. Percorra recursivamente a sub-árvore a direita. 

Tempo de execução: O(n)

Exemplos

<iframe width="560" height="315" src="https://www.youtube.com/embed/5dySuyZf9Qg?si=b82t8ytBIQ9U3x3q" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

#### Breadth-first 

No método breadth-first percorremos todos os nós de um nível antes de passar para o próximo nível. Cada nó é adicionado em uma fila de onde podem ser lidos.

Tempo de execução: O(n)

Exemplos

<iframe width="560" height="315" src="https://www.youtube.com/embed/IozGo2kwRYE?si=ck_p1RHAVmIY4TSR" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

#### Referências

https://en.wikipedia.org/wiki/Tree_traversal
https://github.com/jwasham/coding-interview-university#trees
