package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	var (
		arr   = []int{1, 2, 4, 7, 8, 9, 12, 14, 17, 18, 20, 22, 23, 24, 26, 27, 29}
		start = 0
		end   = len(arr) - 1
		elem  = rand.Intn(20)
	)

	fmt.Printf("Array: %v\nElement: %v\n", arr, elem)

	for start <= end {
		mid := start + (end-start)/2
		if elem == arr[mid] {
			fmt.Printf("Element found at index %v", mid)
			return
		} else if elem < arr[mid] {
			end = mid - 1
		} else {
			start = mid + 1
		}
	}

	fmt.Printf("Element not found!\n")
}
