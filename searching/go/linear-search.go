package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	var (
		arr  = rand.Perm(20)
		elem = rand.Intn(30)
		n    = len(arr)
	)

	fmt.Printf("Array: %v\nElement: %v\n", arr, elem)

	for i := 0; i < n; i++ {
		if arr[i] == elem {
			fmt.Printf("Element found at index %v", i)
			return
		}
	}
	fmt.Printf("Element not found!")
}
