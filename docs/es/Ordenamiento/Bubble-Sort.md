# Ordenamiento de Burbuja

Bubble Sort, también conocido como Sinking Sort, es el algoritmo de clasificación más simple. Intercambia los números si no están en el orden correcto. La complejidad del tiempo en el peor de los casos es O(n^2)

## Pasos

1. Compara el primer elemento con el siguiente elemento.
2. Si el primer elemento es más grande que el siguiente, los elementos se intercambian.
3. Se realiza el paso 2 hasta que el número seleccionado se coloca en su posición correcta y luego se compara el siguiente elemento.
4. Se realizan varias pasadas hasta que se completa la clasificación.

## Ejemplo

Dado el arreglo:
**5 1 4 2 8**

La arreglo ordenado es
**1 2 4 5 8**

Pasos
**Primer vuelta**

- ( **5 1** 4 2 8 ) → ( **1 5** 4 2 8 ), Aquí, el algoritmo compara los dos primeros elementos y los intercambia desde 5 > 1.
- ( 1 **5 4** 2 8 ) → ( 1 **4 5** 2 8 ), Intercambia desde 5 > 4
- ( 1 4 **5 2** 8 ) → ( 1 4 **2 5** 8 ), Intercambia desde 5 > 2
- ( 1 4 2 **5 8** ) → ( 1 4 2 **5 8** ), Ahora, dado que estos elementos ya están en orden (8 > 5), el algoritmo no los intercambia.

**Segunda vuelta**

- ( **1 4** 2 5 8 ) → ( **1 4** 2 5 8 )
- ( 1 **4 2** 5 8 ) → ( 1 **2 4** 5 8 ), Intercambia desde 4 > 2
- ( 1 2 **4 5** 8 ) → ( 1 2 **4 5** 8 )
- ( 1 2 4 **5 8** ) → ( 1 2 4 **5 8** )

Ahora, el arreglo ya está ordenado, pero el algoritmo no sabe si está completo. El algoritmo necesita una vuelta completa adicional sin ningún intercambio para saber que está ordenado.

**Tercera vuelta**

- ( **1 2** 4 5 8 ) → ( **1 2** 4 5 8 )
- ( 1 **2 4** 5 8 ) → ( 1 **2 4** 5 8 )
- ( 1 2 **4 5** 8 ) → ( 1 2 **4 5** 8 )
- ( 1 2 4 **5 8** ) → ( 1 2 4 **5 8** )

## Implementación

- [C](../../../algorithms/C/sorting/bubble-sort.c)
- [C++](../../../algorithms/CPlusPlus/Sorting/bubble-sort.cpp)
- [CSharp](../../../algorithms/CSharp/src/Sorts/bubble-sort.cs)
- [Go](../../../algorithms/Go/sorting/bubble-sort.go)
- [Java](../../../algorithms/Java/sorting/bubble-sort.java)
- [JavaScript](../../../algorithms/JavaScript/src/sorting/bubble-sort.js)
- [Python](../../../algorithms/Python/sorting/bubble_sort.py)

## URL del video

[Video de Youtube acerca de Bubble Sort](https://www.youtube.com/watch?v=vnnL17I7pIY)

## Otros

[Wikipedia](https://es.wikipedia.org/wiki/Ordenamiento_de_burbuja)
