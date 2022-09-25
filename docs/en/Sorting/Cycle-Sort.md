# Cycle Sort

Cycle sort is a comparison sorting algorithm that forces array to be factored into the number of cycles where each of them can be rotated to produce a sorted array. It is theoretically optimal in the sense that it reduces the number of writes to the original array.
It is an in-place and unstable sorting algorithm.

Time Complexity : O(n^2) 
- Worst Case : O(n^2) 
- Average Case: O(n^2) 
- Best Case : O(n^2)

Space complexity :
The space complexity is constant cause this algorithm is in place so it does not use any extra memory to sort.
Auxiliary space: O(1)

## Steps

Suppose there is an array **arr** with **n** distinct elements. Given an element **A**, we can find its index by counting the number of elements smaller than **A**.

1. If the element is at its correct position, simply leave it as it is.
2. Else, we have to find the correct position of **A** by counting the number of elements smaller than it. Another element **B** is replaced to be moved to its correct position. This process continues until we get an element at the original position of **A**.

The above-illustrated process constitutes a cycle. Repeat this cycle for every element of the list until the list is sorted.

## Example

arr[] = {10, 5, 2, 3}

 index =  0   1   2   3

cycle_start = 0 

item = 10 = arr[0]

Find position where we put the item  

pos = cycle_start

i=pos+1

while(i < n)

if (arr[i] < item) 

    pos++;

We put 10 at arr[3] and change item to 
old value of arr[3].

arr[] = {10, 5, 2, 10} 

item = 3 

Again rotate rest cycle that start with index '0' 

Find position where we put the item = 3 

we swap item with element at arr[1] now 

arr[] = {10, 3, 2, 10} 

item = 5

Again rotate rest cycle that start with index '0' and item = 5 

we swap item with element at arr[2].

arr[] = {10, 3, 5, 10 } 

item = 2

Again rotate rest cycle that start with index '0' and item = 2

arr[] = {2, 3,  5, 10}  

Above is one iteration for cycle_stat = 0.

Repeat above steps for cycle_start = 1, 2, ..n-2

## Implementation

- [C++](../../../algorithms/CPlusPlus/Sorting/cycle-sort.cpp)
- [Java](../../../algorithms/Java/sorting/cyclic-sort.java)
- [Python](../../../algorithms/Python/sorting/count-sort.py)

## Video URL

[Youtube Video about Cycle Sort](https://youtu.be/gZNOM_yMdSQ)

## Other

[Wikipedia](https://en.wikipedia.org/wiki/Cycle_sort)