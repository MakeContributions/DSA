package searching

import (
	"fmt"
	"math/rand"
	"time"
)

func binarySearch(arr []int, elem int) {
	var (
		start = 0
		end   = len(arr) - 1
	)

	fmt.Printf("Array: %v\nNumber to be searched: %v\n", arr, elem)

	for start <= end {
		mid := start + (end-start)/2
		if elem == arr[mid] {
			fmt.Printf("Number found at index %v", mid)
			return
		} else if elem < arr[mid] {
			end = mid - 1
		} else {
			start = mid + 1
		}
	}

	fmt.Printf("Number not found!\n")
}

func RunBinarySearch() {
	rand.Seed(time.Now().UnixNano())
	arr := []int{1, 2, 4, 7, 8, 9, 12, 14, 17, 18, 20, 22, 23, 24, 26, 27, 29}
	elem := rand.Intn(20)
	binarySearch(arr, elem)
}
