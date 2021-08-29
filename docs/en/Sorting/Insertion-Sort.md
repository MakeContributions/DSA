# Insertion Sort

Inserion sort is an **inplace** sorting algorithm meaning it won't take any extra space to sort the array items. It works similar to the way you sort playing cards in your hand.
Consider you are dealt 4 cards one after the other. You pick one and keep in your hand, after that for the next card (key) you compare with the one in your hand and place it accordingly and so on until all the cards are in your hand.

## Steps

To sort an array of size n in ascending order:

1. Iterate from second element, arr[1] to arr[n-1] over the array.
2. Compare the current element (key) to its predecessor.
3. If the key element is smaller than its predecessor, compare it to the elements before. Move the greater elements one position up to make space for the swapped element.

## Example

Given array is
**12 11 13 5 6 7**

Sorted array is
**5 6 7 11 12 13**

## Implementation

- [Java](../../../algorithms/Java/sorting/insertion-sort.java)
- [C](../../../algorithms/C/sorting/insertion-sort.c)
- [C++](../../../algorithms/CPlusPlus/Sorting/insertion-sort.cpp)
- [JavaScript](../../../algorithms/JavaScript/src/sorting/insertion-sort.js)
- [Python](../../../algorithms/Python/sorting/insertion_sort.py)

## Video URL

[Youtube Video about Insertion Sort](https://www.youtube.com/watch?v=BO145HIUHRg)

## Others

[Wikipedia](https://en.wikipedia.org/wiki/Insertion_sort)
