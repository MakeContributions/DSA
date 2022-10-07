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

Bucket Sort for numbers having integer part:
Algorithm : 
1.Find maximum element and minimum of the array
2.Calculate the range of each bucket

range = (max - min) / n
n is the number of buckets

3.Create n buckets of calculated range
4.Scatter the array elements to these buckets

BucketIndex = ( arr[i] - min ) / range

5.Now sort each bucket individually
6.Gather the sorted elements from buckets to original array

## Example

Input :    
Unsorted array:  [ 9.8 , 0.6 , 10.1 , 1.9 , 3.07 , 3.04 , 5.0 , 8.0 , 4.8 , 7.68 ]
No of buckets :  5

Output :  
Sorted array:   [ 0.6 , 1.9 , 3.04 , 3.07 , 4.8 , 5.0 , 7.68 , 8.0 , 9.8 , 10.1 ]

![image](https://user-images.githubusercontent.com/98322627/194531206-9414d713-51df-44db-b51c-09b2b8307d78.png)
 Input :    
Unsorted array:  [0.49 , 5.9 , 3.4 , 1.11 , 4.5 , 6.6 , 2.0]
No of buckets: 3

Output :  
Sorted array:   [0.49 , 1.11 , 2.0 , 3.4 , 4.5 , 5.9 , 6.6]

## Implementation

- [C++](https://www.tutorialspoint.com/cplusplus-program-to-implement-bucket-sort)
- [Java](https://www.codespeedy.com/bucket-sort-in-java/)
- [Python](https://stackabuse.com/bucket-sort-in-python/)

## Video URL

[Youtube Video about Bucket Sort](https://www.youtube.com/watch?v=JMlYkE8hGJM&feature=share&utm_source=EJGixIgBCJiu2KjB4oSJEQ)

## Other

[Wikipedia](https://en.wikipedia.org/wiki/Bucket_sort)
