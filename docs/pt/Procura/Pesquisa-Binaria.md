# Pesquisa Binária

A **Pesquisa Binária**(em inglês Binary Search) é um algoritmo de pesquisa que encontra a posição de um valor dentro da matriz.

1. Complexidade temporal: O(log n)
2. Complexidade de espaço: O(1)
3. Aplicações: Uma melhor aplicação quando os dados já estão organizados e temos bastantes
4. Nome do fundador: P.F. Windley, A.D. Booth, A.J.T. Colin, e T.N. Hibbard
5. É um dos algoritmos de pesquisa mais populares e usado diariamente.
 
## Passos

1. Encontrar o elemento do meio da matriz
2. Verificar se o elemento que estamos a procurar é igual ao elemento do meio e se sim, retornar o índice e acabar o programa/função.
3. Se o 2º passo não foi verificado, testamos se o elemento a procurar é menor que o elemento do meio, se sim voltamos para o passo 1 e usamos entre o início do matriz e o índice do elemento do meio -1.
4. Se o 3º passo não foi verificado, testamos se o elemento a procurar é maior que o elemento do meio, se sim voltamos para o passo 1 e usamos entre o índice do elemento do meio +1 até ao último índice da matriz.
5. Percorrer o ciclo até o índice inicial ser menor do que o índice final
6. Se o ciclo acabar e nenhum dado for encontrado retornar -1, que significa que o elemento a procurar não existe na matriz dada.
> **Nota:** A matriz deve estar organizada de forma crescente.

## Exemplos

Dados de Entrada: **10,20,30,40,50**

Elemento para procurar: **20**

Procedimento:

Elemento do meio: **30** e o elemento a procurar é menor do que 30, logo a pesquisa vai passar a ser do início do matriz até ao índice do meio -1

Logo em seguida o elemento do meio é o **20** e o elemento do meio é o elemento que estamos a procurar, logo retornar o índice **1**

Dados de Saída: **1**

## Implementações

- [C](https://github.com/MakeContributions/DSA/blob/main/algorithms/C/searching/Binary-search.c)
- [C++](https://github.com/MakeContributions/DSA/blob/main/algorithms/CPlusPlus/Searching/binary-search.cpp)
- [CSharp](https://github.com/MakeContributions/DSA/blob/main/algorithms/CSharp/src/Search/binary-search.cs)
- [Go](https://github.com/MakeContributions/DSA/blob/main/algorithms/Go/searching/binary-search.go)
- [Java](https://github.com/MakeContributions/DSA/blob/main/algorithms/Java/searching/binary-search.java)
- [JavaScript](https://github.com/MakeContributions/DSA/blob/main/algorithms/JavaScript/src/searching/binary-search.js)
- [JavaScript](https://github.com/MakeContributions/DSA/blob/main/algorithms/JavaScript/src/searching/binary-search-recursive.js)
- [Python](https://github.com/MakeContributions/DSA/blob/main/algorithms/Python/searching/binary_search.py)

## Video URL

[Video a explicar pesquisa binária](https://www.youtube.com/watch?v=5T1SDEZzCLo)

## Outros

[Wikipédia](https://pt.wikipedia.org/wiki/Pesquisa_bin%C3%A1ria)

[Exercícios e uma explicação mais detalhada](https://www2.unifap.br/furtado/files/2013/10/Algoritmos-busca-bin%c3%a1ria-vers%c3%a3o-simplificada1.pdf)