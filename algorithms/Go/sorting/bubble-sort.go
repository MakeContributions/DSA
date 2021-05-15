/*
   Bubble sort is a recursive algorithm based on swapping 2 values closest to each other: k and k+1
   We start by checking the first two values of the array, and we swap them if the first value is bigger than the second one.
   Then we recursively swap the second value with the third, if needed and so on until the array is sorted.
   Average Time Complexity: O(n^2))
*/

package sorting

import (
	"fmt"
)

func bubbleSort(sliceInt []int, n int) {
	for k := 0; k < n-1; k++ {
		if sliceInt[k] > sliceInt[k+1] {
			// We swaps the value if sliceInt[k] > sliceInt[k+1]
			sliceInt[k], sliceInt[k+1] = sliceInt[k+1], sliceInt[k]
			bubbleSort(sliceInt, n)
		}
	}
}

func RunBubbleSort() {
	sliceInt := []int{1, 2, -1, 0, 534, -100, 9, 53, 203}
	bubbleSort(sliceInt, len(sliceInt))
	fmt.Println(sliceInt)
}

