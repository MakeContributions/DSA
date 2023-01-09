# Min Heap

**Min Heap** is a **a binary tree structure** introduced by J. W. J. Williams in 1964. It is defined by two following constraints:
- The binary tree is complete on all levels except the last one. The nodes in the last, deepest, level are filled from left to right.
- The key of each node is less or equal to the keys of its children
 
**Min Heap** has following properties:
1. Worst case time complexity:
    - build the heap: O(n)
    - remove min: O(log(n))
    - insert: O(log n)
    - remove all elements: O(n*log(n))
2. Space complexity:
    - build the heap: O(n)
    - remove min: O(1)
    - insert: O(1)
    - remove all elements: O(1)
3. Applications:
    - quick access to the smallest element
    - implementation of priority queue
    - heapsort 

## Operations on heap
**insert** 
1. Add the element next to the leftmost free node on the deepest level.
2. Compare the element with the key of its parent. 
3. If the parent is greater than the element, swap them (move the element one level up), then go to step two.
4. Stop if the parent is less or equal.

> **Note:** second and third steps shift the element up the tree, until correct order of elements is achieved.

**remove min**
1. Replace the root with the rightmost element on the deepest level. The new root is now current element.
2. Compare the current element with its smallest child. 
3. If the element is greater than its smallest child, swap the element with its smallest child (move the element one level deeper), and go to step 2.
4. If both children are greater or equal to the current element, stop.
> **Note:** second and third steps shift the element down the tree until correct order of elements is achieved. 

## Example

- **Inserting** elements 4, 10, 2, 22, 45, 18 <br> Output: 2 10 4 22 45 18 <br> Explanation: The numbers are stored subsequently. 2 is the root, 10 and 4 are its children. The children of 10 are  22 and 45. The only child of 4 is 18.
- **Deleting** the minimum in 2 10 4 22 45 18  <br> Output: 4 10 18 22 45 <br> Explanation: First, 2 is swapped with 18. Then, 18 is shifted down the tree, until the elements are in correct order. The size of the heap is reduced by 1.


## Implementation 
- [C](../../../algorithms/C/tree/min-heap.c)
- [C++](../../../algorithms/CPlusPlus/Trees/min-heap.cpp)
- [Java](../../../algorithms/Java/trees/MinHeap.java)
## Video URL
[Youtube Video about Heaps](https://www.youtube.com/watch?v=t0Cq6tVNRBA) 

## Others
[Wikipedia](https://en.wikipedia.org/wiki/Binary_heap)

