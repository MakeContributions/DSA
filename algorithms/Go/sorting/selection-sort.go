/*
	Selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning.
	The algorithm maintains two subarrays in a given array: 
		The subarray which is already sorted. 
		Remaining subarray which is unsorted.
	Average Time Complexity: O(n^2)
  
*/

package sorting

import "fmt"

func main() {
	arr := []int{7, 4, 7, 3, 2}
	selSortRec(arr, len(arr)-1) //using recursion
	fmt.Println(arr)
}

//sort using iterative method
func selSort(arr []int) {
	for arrIndex := range arr {
		minVal := arr[arrIndex]
		minIndex := arrIndex
		for subIndex := arrIndex + 1; subIndex < len(arr); subIndex++ {
			if arr[subIndex] < minVal {
				minVal = arr[subIndex]
				minIndex = subIndex
			}
		}
		arr[minIndex], arr[arrIndex] = arr[arrIndex], arr[minIndex]
	}
}


//sort using recursive method
func selSortRec(arr []int, i int) {
	if i < 0 {
		return
	}
	maxIn := maxSel(arr, i)
	//i = len(arr)-1
	if i != maxIn {
		arr[i], arr[maxIn] = arr[maxIn], arr[i]
	}
	selSortRec(arr, i-1)
}
func maxSel(arr []int, i int) int {
	if i > 0 {
		maxIn := maxSel(arr, i-1)
		if arr[i] < arr[maxIn] {
			return maxIn
		}
	}
	return i
}
