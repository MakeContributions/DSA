/*
* Analogizing this algorithm with inserting a playing
* card into your hand, we distinguish the "key" as
* the inserting card and find the position of that
* card among the previous j - 1 cards.

* O(n^2) runtime (the deck is sorted in descending order).
 */

package sorting

import (
	"fmt"
)

func insertionSort(arr []int) {
	n := len(arr)
	for i := 1; i < n; i++ {
		key := arr[i]
		j := i - 1
		for j >= 0 && arr[j] > key {
			arr[j+1] = arr[j]
			j--
		}
		arr[j+1] = key
	}
}

func RunInsertionSort() {
	arr := []int{10, 1, 6, 256, 2, 53, 235, 53, 1, 7, 23}
	fmt.Println("Unsorted Array:", arr)
	insertionSort(arr)
	fmt.Println("Sorted Array:", arr)
}
