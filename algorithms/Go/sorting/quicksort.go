/*
   Quick Sort is a divide and conquer algorithm.
   First we choose a pivot and split the array in two parts, one containing all elements less than or equal to the pivot and other contains the rest (the pivot element is in neither of them)
   Then we recursively sort the two arrays and finally concatenate them to get the sorted array.
   Average Time Complexity: O(n*log(n))
   For details explanation and proof of correctness check this -> https://cs.pomona.edu/classes/cs140/pdf/l09-quicksort-proof.pdf
*/

package sorting

import (
	"fmt"
	"math/rand"
	"time"
)

func quickSort(arr []int) []int {
	n := len(arr)
	if n <= 1 {
		return arr
	}
	rand.Seed(time.Now().UnixNano())
	pivot := rand.Int() % n
	var left []int
	var right []int
	for i := 0; i < n; i++ {
		if arr[i] <= arr[pivot] && i != pivot {
			left = append(left, arr[i])
		} else if arr[i] > arr[pivot] {
			right = append(right, arr[i])
		}
	}
	leftSorted := quickSort(left)
	rightSorted := quickSort(right)
	sortedArr := append(leftSorted, arr[pivot])
	sortedArr = append(sortedArr, rightSorted...)
	return sortedArr
}

func RunQuickSort() {
	arr := []int{10, 1, 6, 256, 2, 53, 235, 53, 1, 7, 23}
	fmt.Printf("Unsorted Array: %v\nSorted Array: %v", arr, quickSort(arr))
}

