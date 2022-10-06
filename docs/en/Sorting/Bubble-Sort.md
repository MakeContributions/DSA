# Bubble Sort

Bubble Sort also known as Sinking Sort is the simplest sorting algorithm. It swaps the numbers if they are not in correct order.
The Worst Case -
Time Complexity : O(n^2)
Space Compldxity : O(1) i.e it use constant space.
## Steps

1. Compares the first element with the next element.
2. If the first element is larger than the next element then the elements are swapped.
3. Step 2 is performed until the selected number is put to its correct position then the next element is compared.
4. Multiple passes are made until the sorting is completed.

## Example

Given array is
**5 1 4 2 8**

Sorted array is
**1 2 4 5 8**

Steps
**First Pass**

- ( **5 1** 4 2 8 ) → ( **1 5** 4 2 8 ), Here, algorithm compares the first two elements, and swaps since 5 > 1.
- ( 1 **5 4** 2 8 ) → ( 1 **4 5** 2 8 ), Swap since 5 > 4
- ( 1 4 **5 2** 8 ) → ( 1 4 **2 5** 8 ), Swap since 5 > 2
- ( 1 4 2 **5 8** ) → ( 1 4 2 **5 8** ), Now, since these elements are already in order (8 > 5), algorithm does not swap them.

**Second Pass**

- ( **1 4** 2 5 8 ) → ( **1 4** 2 5 8 )
- ( 1 **4 2** 5 8 ) → ( 1 **2 4** 5 8 ), Swap since 4 > 2
- ( 1 2 **4 5** 8 ) → ( 1 2 **4 5** 8 )
- ( 1 2 4 **5 8** ) → ( 1 2 4 **5 8** )

Now, the array is already sorted, but the algorithm does not know if it is completed. The algorithm needs one additional whole pass without any swap to know it is sorted.

**Third Pass**

- ( **1 2** 4 5 8 ) → ( **1 2** 4 5 8 )
- ( 1 **2 4** 5 8 ) → ( 1 **2 4** 5 8 )
- ( 1 2 **4 5** 8 ) → ( 1 2 **4 5** 8 )
- ( 1 2 4 **5 8** ) → ( 1 2 4 **5 8** )

## Implementation

- [C](../../../algorithms/C/sorting/bubble-sort.c)
- [C++](../../../algorithms/CPlusPlus/Sorting/bubble-sort.cpp)
- [CSharp](../../../algorithms/CSharp/src/Sorts/bubble-sort.cs)
- [Go](../../../algorithms/Go/sorting/bubble-sort.go)
- [Java](../../../algorithms/Java/sorting/bubble-sort.java)
- [JavaScript](../../../algorithms/JavaScript/src/sorting/bubble-sort.js)
- [Python](../../../algorithms/Python/sorting/bubble_sort.py)

## Video URL

[Youtube Video about Bubble Sort](https://www.youtube.com/watch?v=Jdtq5uKz-w4&ab_channel=mycodeschool)

## Others

[Wikipedia](https://en.wikipedia.org/wiki/Bubble_sort)
