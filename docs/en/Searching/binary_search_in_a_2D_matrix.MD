# Binary Search

**Binary search**, also known as half-interval **search**, logarithmic **search**, or **binary** chop, is a **search** algorithm that finds the position of a target value within a sorted array. **Binary search** compares the target value to the middle element of the array.

1. Time Complexity: O(log n) 
2. Space Complexity: O(1)
3. Applications: Best when data is sorted and large
4. Founder's Name: P.F. Windley, A.D. Booth, A.J.T. Colin, and T.N. Hibbard
5. It is one of the popular and daily using Searching Algorithm

## Steps

1. Find the middle element of the array
2. Check whether the key is equal to middle element if yes then return the index and exit the program
3. If the 2 step didn't run then test whether the element is less than the middle element if yes then run the step: 1 between the start to middle-1 index 
4. If the 3 step didn't run then test whether the element is high than the middle element if yes then run the step: 1 between the middle+1 to last index.
5. Run the loop till the starting index is less than end index
6. If the loop over and data not found then return false that means data doesn't exist
> **Note:** To implement Binary Search in a matrix, the matrix has to be sorted row-wise and column-wise in ascending order

In a 2D array to implement this without using an array of size m X n to store the elements of the matrix, the low will be 0 and high will be m*n-1 initially and then everytime we need to use the middle index(low+high/2) value to calculate the row and the column. It can be simply done by row = middle / no. of columns & column = middle % no. of columns. 

## Example

Input: **1,3,5,7**
       **10,11,16,20**
       **23,30,34,50**

Element to search: **23**

Procedure:

Here m = 3 , n = 4
So low=0 , high=11

Middle element: **11** 
mid = (0+11)/2 = 5
arr[5/4][5%4] = arr[1][1] = 11
11 < 23 , so low = 5+1 = 6

Middle element: **23** 
mid = (6+11)/2 = 8
arr[8/4][8%4] = arr[2][0] = 23
23 = 23 , so true returned.
Thus, element present in matrix.

Output: **Element present in matrix.**



## Implementation

- [Java](https://github.com/MakeContributions/DSA/blob/main/algorithms/Java/searching/binary_search_in_a_2D_matrix.java)


## Video URL

[Watch Binary Search Implementation](https://youtu.be/P3YID7liBug)


## Others

Solve Problem Related to Binary Search 

[Click Me](https://leetcode.com/problems/search-a-2d-matrix/)
