# Quick Sort

1. **Time Complexity:** O(n^2) occurs when the picked pivot is always an extreme (smallest or largest) element.
2. **Space Complexity:** O(n).
3. **Applications:** Commercial computing, search for information, operations research, event-driven simulation, numerical computations, combinatorial search.
4. **Founder's Name:** Tony Hoare

## Steps

1. Consider the last element of the list as pivot.
2. Define two variables i and j. Set i and j to first and last elements of the list.
3. Increment i until list[i] > pivot then stop.
4. Decrement j until list[j] < pivot then stop.
5. If i < j then exchange list[i] and list[j].
6. Repeat steps 3,4 and 5 until i > j.
7. Exchange the pivot element with list[j] element.

## Example

**Given array : [10, 80, 30, 90, 40, 50, 70]**

**Pivot (last element) : 70**

**1. 10 < 70 then i++ and swap(list[i],list[j]):** [10, 80, 30, 90, 40, 50, 70]

**2. 80 < 70, then no actions needed:** [10, 80, 30, 90, 40, 50, 70]

**3. 30 < 70 then i++ and swap(list[i],list[j]):** [10, 30, 80, 90, 40, 50, 70]

**4. 90 < 70, then no actions needed:** [10, 30, 80, 90, 40, 50, 70]

**5. 40 < 70 then i++ and swap(list[i],list[j]):** [10, 30, 40, 90, 80, 50, 70]

**6.  50 < 70 then i++ and swap(list[i],list[j]):** [10, 30, 40, 50, 80, 90, 70]

**7. Swap list[i+1] and pivot:** [10, 30, 40, 50, 70, 90, 80]

**8. Quick sort the left part of the pivot:** [10, 30, 40, 50]

**9. Quick sort the right part of the pivot:** [70, 80, 90]

**10. Sorted Array:** [10, 30, 40, 50, 70, 80, 90]


## Implementation

- [Java](../../../algorithms/Java/sorting/quick-sort.java)
- [JavaScript](../../../algorithms/JavaScript/src/sorting/quick-sort.js)
- [Go](../../../algorithms/Go/sorting/quicksort.go)
- [C++](../../../algorithms/CPlusPlus/Sorting/quick-sort.cpp)
- [Python](../../../algorithms/Python/sorting/quicksort.py)

## Video URL

[Youtube Video about Quick Sort](https://www.youtube.com/watch?v=PgBzjlCcFvc&ab_channel=GeeksforGeeks)

## Others

[Wikipedia](https://en.wikipedia.org/wiki/Quicksort)
