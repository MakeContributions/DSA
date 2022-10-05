# Bucket Sort

Bucket sort, or bin sort, is a sorting algorithm that works by distributing the elements of an array into a number of buckets.
Each bucket is then sorted individually, either using a different sorting algorithm, or by recursively applying the bucket sorting algorithm.

Time Complexity : O(n) 
- Worst Case : O(n^2) 
- Average Case: O(n) 
- Best Case : O(n)

Space complexity :
The space complexity of the bucket sort is O(n+k).
Auxiliary space: O(n)

## Steps

The bucket sort algorithm works as follows.

1. Assume the input array is:
2. 
3. Else, we have to find the correct position of **A** by counting the number of elements smaller than it. Another element **B** is replaced to be moved to its correct position. This process continues until we get an element at the original position of **A**.

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

- [C++](https://www.tutorialspoint.com/cplusplus-program-to-implement-bucket-sort)
- [Java](https://www.codespeedy.com/bucket-sort-in-java/)
- [Python](https://stackabuse.com/bucket-sort-in-python/)

## Video URL

[Youtube Video about Bucket Sort](https://www.youtube.com/watch?v=JMlYkE8hGJM&feature=share&utm_source=EJGixIgBCJiu2KjB4oSJEQ)

## Other

[Wikipedia](https://en.wikipedia.org/wiki/Bucket_sort)
