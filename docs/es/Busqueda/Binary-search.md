# Búsqueda binaria

La búsqueda binaria es un algoritmo de búsqueda utilizado para encontrar la posición de un elemento dentro de un arreglo (array) de elementos ordenados ascendentemente (de menor a mayor). Las complejidades temporal y espacial de este algoritmo son O(logN) y O(1) respectivamente. 

Existen distintas variaciones en la implementación de este algoritmo, por ejemplo, algunas implementaciones cuando deben retornar la posición de un elemento que aparece varias dentro del arreglo retornan la primera posición (la que está más a la izquierda) mientras que otros retornan la última (la que está más a la derecha).

## Pasos

1. Se define el rango de búsqueda, inicialmente se considera todo el arreglo.
2. Se obtiene el elemento que está justo en la mitad del arreglo.
3. Se verifica si el elemento del medio es igual al elemento que se desea encontrar, en tal caso, se acaba el algoritmo y se retorna la posición del elemento.
4. En caso de que el elemento del medio no sea igual al buscado, se verifica si dicho elemento es menor al buscado, o por el contrario si es menor al buscado.
5. Si el elemento del medio es menor al buscado, cambiaremos el límite inferior de nuestro rango de búsqueda a la posición del elemento del medio +1.
6. Si el elemento del medio es mayor al buscado, cambiaremos el límite superior de nuestro rango de búsqueda a la posición del elemento del medio -1.
7. Se repiten los pasos anteriores hasta encontrar la posición del elemento, o hasta que el límite inferior y superior del rango de búsqueda sean iguales.
8. En caso de no encontrarse el elemento deseado, se retornará “-1”.

## Ejemplo

-            (0  1  2  3   4   5   6   7   8   9)
- Arreglo: **(2, 5, 8, 12, 16, 23, 38, 56, 72, 91)**
- Encontrar la posición del número 23.


- Se definen los límites del intervalo, inicialmente serán: 0 y 9, siendo 0 la posición inicial y 9 la posición final del arreglo.
  
-    (0                                9)
-    (2, 5, 8, 12, 16, 23, 38, 56, 72, 91)

- Se obtiene el índice y el elemento que se encuentra en la mitad del arreglo, en este caso 4 y 16 respectivamente.
  
-    (0            4                   9)
-    (2, 5, 8, 12, 16, 23, 38, 56, 72, 91)

- 16 es menor al elemento deseado, entonces cambiamos nuestro límite inferior de nuestro rango a 4+1 (ya que 4 era la posición del valor de la mitad).

-                      (5               9)
-    (2, 5, 8, 12, 16, 23, 38, 56, 72, 91)

- Se obtiene el índice y el elemento que se encuentra en la mitad del rango arreglo, en este caso 7 y 56 respectivamente.

-                      (5       7       9)
-    (2, 5, 8, 12, 16, 23, 38, 56, 72, 91)

- 56 es mayor a 23, se cambia el límite superior del intervalo 7-1(ya que 7 era la posición del valor de la mitad).

-                      (5   6)           
-    (2, 5, 8, 12, 16, 23, 38, 56, 72, 91)

- Se obtiene la posición y valor de la mitad del rango, siendo este entre 5 y 6, obteniendo la posición 5 y el número 23, ya que este es el número buscado, se termina el algoritmo.

-                      (5)               
-    (2, 5, 8, 12, 16, 23, 38, 56, 72, 91)


## Implementación

- [C](https://github.com/MakeContributions/DSA/blob/main/algorithms/C/searching/Binary-search.c)
- [C++](https://github.com/MakeContributions/DSA/blob/main/algorithms/CPlusPlus/Searching/binary-search.cpp)
- [CSharp](https://github.com/MakeContributions/DSA/blob/main/algorithms/CSharp/src/Search/binary-search.cs)
- [Go](https://github.com/MakeContributions/DSA/blob/main/algorithms/Go/searching/binary-search.go)
- [Java](https://github.com/MakeContributions/DSA/blob/main/algorithms/Java/searching/binary-search.java)
- [JavaScript](https://github.com/MakeContributions/DSA/blob/main/algorithms/JavaScript/src/searching/binary-search.js)
- [JavaScript](https://github.com/MakeContributions/DSA/blob/main/algorithms/JavaScript/src/searching/binary-search-recursive.js)
- [Python](https://github.com/MakeContributions/DSA/blob/main/algorithms/Python/searching/binary_search.py)

## URL del video

[Video de Youtube acerca de la búsqueda binaria](https://www.youtube.com/watch?v=wAmu0Ly5ook)

## Otros

[Wikipedia](https://es.wikipedia.org/wiki/B%C3%BAsqueda_binaria)

Ejercicios (inglés)
[Ejercicios](https://leetcode.com/tag/binary-search/)