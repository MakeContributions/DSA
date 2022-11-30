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
4. If the 3 step didn't run then test whether the element is higher than the middle element if yes then run the step: 1 between the middle+1 to the last index.
5. Run the loop till the starting index is less than end index
6. If the loop over and data not found then return -1 that means data doesn't exist
> **Note:** The array should be sorted in ascending to descending order

## Example

Input: **10,20,30,40,50**

Element to search: **20**

Procedure:

Middle element:**30** and element is less than 30 so search between start to middle -1 index

Middle element: **20** and yes the middle element is the key to found so return the index=**1**

Output: **1**

## Implementation

- [C](https://github.com/MakeContributions/DSA/blob/main/algorithms/C/searching/Binary-search.c)
- [C++](https://github.com/MakeContributions/DSA/blob/main/algorithms/CPlusPlus/Searching/binary-search.cpp)
- [CSharp](https://github.com/MakeContributions/DSA/blob/main/algorithms/CSharp/src/Search/binary-search.cs)
- [Go](https://github.com/MakeContributions/DSA/blob/main/algorithms/Go/searching/binary-search.go)
- [Java](https://github.com/MakeContributions/DSA/blob/main/algorithms/Java/searching/binary-search.java)
- [JavaScript](https://github.com/MakeContributions/DSA/blob/main/algorithms/JavaScript/src/searching/binary-search.js)
- [JavaScript](https://github.com/MakeContributions/DSA/blob/main/algorithms/JavaScript/src/searching/binary-search-recursive.js)
- [Python](https://github.com/MakeContributions/DSA/blob/main/algorithms/Python/searching/binary_search.py)

## Video URL

[Watch Binary Search Implementation](https://youtu.be/P3YID7liBug)

## Others

Solve Problem Related to Binary Search 

[Click Me](https://leetcode.com/tag/binary-search/)
