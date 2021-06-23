# Selection Sort

1. Time Complexity: O(n^2) due to two nested loops. 
2. Space Complexity: O(1)
3. Applications: Useful when memory write is a costly operation.
4. Founder's Name: Oscar Wilde

## Steps

1. Divide the array into two sub-arrays Unsorted and Sorted. Initially, keep the sorted array as empty and unsorted array as the whole array.
2. Remove the minimum element from unsorted array and place it at the end of sorted array.
3. Repeat step 2 until the length of sorted array is equal to initial array and the length of unsorted array becomes 0.
4. Return the sorted array.

## Example

Given array is
**13, 44, 5, 34, 3**

Sorted array is
**3, 5, 13, 34, 44**

**First pass**

Unsorted array: [13, 44, 5, 34, 3]

Minimum in an unsorted array: 3

Sorted array: [3]

**Second pass**

Unsorted array: [13, 44, 5, 34]

Minimum in unsorted array: 5

Sorted array: [3, 5]

**Third pass**

Unsorted array: [13, 44, 34]

Minimum in an unsorted array: 13

Sorted array: [3, 5, 13]

**Fourth pass**

Unsorted array: [44, 34]

Minimum in an unsorted array: 34

Sorted array: [3, 5, 13, 34]

**Fifth pass**

Unsorted array: [44]

Minimum in an unsorted array: 44

Sorted array: [3, 5, 13, 34, 44]



Unsorted array: []

Return the sorted array.

## Implementation

- [Java](../../../algorithms/Java/sorting/selection-sort.java)
- [C++](../../../algorithms/CPlusPlus/Sorting/selection-sort.cpp)
- [JavaScript](../../../algorithms/JavaScript/src/sorting/selection-sort.js)
- [Python](../../../algorithms/Python/sorting/selection_sort.py)

## Video URL

[Selection Sort](https://www.youtube.com/watch?v=GUDLRan2DWM&list=PL2_aWCzGMAwKedT2KfDMB9YA5DgASZb3U&index=2)
