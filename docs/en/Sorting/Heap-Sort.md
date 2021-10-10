# Heap Sort

1. **Time Complexity:** O(log(n)) due to heapify(logn) and CreateandBuildHeap is O(n).
2. **Space Complexity:** O(1).
3. **Applications:** Finding the order in statistics, dealing with priority queues in Prim's algorithm and Huffman encoding or data compression.
4. **Founder's Name:** John William Joseph Williams

## Steps

1. Create and build a max heap.
2. Remove the root element and put at the end of the list. Put the last item of the tree at the vacant place.
3. Reduce the size of the heap by 1.
4. Heapify the root element again so that we have the highest element at root.
5. Repeat this process until all the elements are sorted.

## Example

**Given array : [4, 10, 3, 5, 1]**

**1. Create a heap:** [4, 10, 3, 5, 1]

**2. Build a max heap:** [10, 5, 3, 4, 1]

**3. Remove the node:** [1, 5, 3, 4, 10]

**4. Build a max heap:** [5, 4, 3, 1, 10]

**5. Remove the node:** [1, 4, 3, 5, 10]

**6. Build a max heap:** [4, 1, 3, 5, 10]

**7. Remove the node:** [3, 1, 4, 5, 10]

**8. Already max heap:** [3, 1, 4, 5, 10]

**9. Remove the node:** [1, 3, 4, 5, 10]

**10. Sorted Array:** [1, 3, 4, 5, 10]


## Implementation

- [Java](../../../algorithms/Java/sorting/heap-sort.java)
- [C](../../../algorithms/C/sorting/heap-sort.c)
- [C++](../../../algorithms/CPlusPlus/Sorting/heap-sort.cpp)
- [Python](../../../algorithms/Python/sorting/heap-sort.py)

## Video URL

[Youtube Video about Heap Sort](https://www.youtube.com/watch?v=MtQL_ll5KhQ&ab_channel=GeeksforGeeks)

## Others

[Wikipedia](https://en.wikipedia.org/wiki/Heapsort)
