# Selection Sort

1. Time Complexity: O(n^2) due to two nested loops. 
2. Space Complexity: O(1)
3. Applications: Useful when memory write is a costly operation.
4. Founder's Name: Oscar Wilde

## Steps
The algorithm divides the array into two parts in which one part is sorted array and the other part is to be sorted. Initially, the length of sorted array is zero and length of unsorted array is length of the entire array. The algorithm finds the minimum element in unsorted array and puts it at the end of sorted array and hence, keeps on decreasing the length of unsorted array. The final output will be a sorted array.

## Example
Let the array be : [13, 44, 5, 34, 3] <br>
Sorted array: [] <br>
Unsorted array: [13, 44, 5, 34, 3] <br>
Minimum in unsorted array: 3 <br>
Sorted array: [3] <br>
Unsorted array: [13, 44, 5, 34] <br>
Minimum in unsorted array: 5 <br>
Sorted array: [3,5] <br>
Unsorted array: [13, 44, 34] <br>
Minimum in unsorted array: 13 <br>
Sorted array: [3,5,13] <br>
Unsorted array: [44,34] <br>
Minimum in unsorted array: 34 <br>
Sorted array: [3,5,13,34] <br>
Unsorted array: [44] <br>
Minimum in unsorted array: 44 <br>
Sorted array: [3,5,13,34,44] <br>
Unsorted array: [] <br>
Hence, sorted array is obtained. <br>


## Implementation

- [Java](../../../algorithms/Java/sorting/selection-sort.java)
- [C++](../../../algorithms/CPlusPlus/Sorting/selection-sort.cpp)
- [JavaScript](../../../algorithms/JavaScript/src/sorting/selection-sort.js)
- [Python](../../../algorithms/Python/sorting/selection_sort.py)

## Video URL

<a href="https://www.youtube.com/watch?v=GUDLRan2DWM&list=PL2_aWCzGMAwKedT2KfDMB9YA5DgASZb3U&index=2">Selection Sort</a>
