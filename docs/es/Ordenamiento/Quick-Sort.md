# Quick Sort

1. **Complejidad temporal:** O(n^2) ocurre cuando el pivote elegido es siempre un elemento extremo (el más pequeño o el más grande).
2. **Complejidad espacial:** O(n).
3. **Aplicaciones:** Computación comercial, búsqueda de información, investigación de operaciones, simulación dirigida por eventos, cómputos numéricos, búsqueda combinatoria.
4. **Nombre del creador:** Tony Hoare

## Pasos

1. Considera el último elemento de la lista como pivote.
2. Define dos variables i y j. Asigna i y j al primer y último elemento de la lista.
3. Incrementa i hasta que lista[i] > pivote y luego detente.
4. Disminuye j hasta que lista[j] < pivote y luego detente.
5. Si i < j, entonces intercambia lista[i] y lista[j].
6. Repite los pasos 3, 4 y 5 hasta que i > j.
7. Intercambia el elemento pivote con el elemento lista[j].

## Ejemplo

**Dado el vector: [10, 80, 30, 90, 40, 50, 70]**

**Pivote (último elemento) : 70**

**1. 10 < 70 entonces i++ e intercambia(lista[i], lista[j]):** [10, 80, 30, 90, 40, 50, 70]

**2. 80 < 70, entonces no es necesario hacer nada:** [10, 80, 30, 90, 40, 50, 70]

**3. 30 < 70 entonces i++ e intercambia(lista[i], lista[j]):** [10, 30, 80, 90, 40, 50, 70]

**4. 90 < 70, entonces no es necesario hacer nada:** [10, 30, 80, 90, 40, 50, 70]

**5. 40 < 70 entonces i++ e intercambia(lista[i], lista[j]):** [10, 30, 40, 90, 80, 50, 70]

**6. 50 < 70 entonces i++ e intercambia(lista[i], lista[j]):** [10, 30, 40, 50, 80, 90, 70]

**7. Intercambia lista[i+1] y el pivote:** [10, 30, 40, 50, 70, 90, 80]

**8. Aplica Quick Sort a la parte izquierda del pivote:** [10, 30, 40, 50]

**9. Aplica Quick Sort a la parte derecha del pivote:** [70, 80, 90]

**10. Vector ordenado:** [10, 30, 40, 50, 70, 80, 90]

## Implementación

- [Java](../../../algorithms/Java/sorting/quick-sort.java)
- [JavaScript](../../../algorithms/JavaScript/src/sorting/quick-sort.js)
- [Go](../../../algorithms/Go/sorting/quicksort.go)
- [C++](../../../algorithms/CPlusPlus/Sorting/quick-sort.cpp)
- [Python](../../../algorithms/Python/sorting/quicksort.py)
- [C](../../../algorithms/C/sorting/quick-sort.c)
## URL del video

[Video de Youtube sobre Quick Sort](https://www.youtube.com/watch?v=DYmTpUfcyT8)

## Otro

[Wikipedia](https://es.wikipedia.org/wiki/Quicksort)
