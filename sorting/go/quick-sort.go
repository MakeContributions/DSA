package main

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

func main() {
	arr := []int{10, 1, 6, 256, 2, 53, 235, 53, 1, 7, 23}
	fmt.Printf("Unsorted Array: %v\nSorted Array: %v", arr, quickSort(arr))
}
