package searching

import (
	"fmt"
	"math/rand"
	"time"
)

func linearSearch(arr []int, elem int) {
	n := len(arr)

	fmt.Printf("Array: %v\nElement: %v\n", arr, elem)

	for i := 0; i < n; i++ {
		if arr[i] == elem {
			fmt.Printf("Element found at index %v", i)
			return
		}
	}
	fmt.Printf("Element not found!")
}

func RunLinearSearch() {
	rand.Seed(time.Now().UnixNano())
	arr := rand.Perm(20)
	elem := rand.Intn(30)
	linearSearch(arr, elem)
}
