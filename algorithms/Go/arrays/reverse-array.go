//Description : This program reverses array elements by swapping the first half part of the array
//Time Complexity : O(n/2), where n is the array size
//Auxiliary Space : O(1)

package arrays

import ("fmt")

func TestReverseArray() {
	// create an array of integers
    arr := []int{1, 2, 3, 4, 5}
    // get the length of the array
    n := len(arr)
    // iterate over half of the array and swap corresponding elements
    for i := 0; i < n/2; i++ {
        arr[i], arr[n-i-1] = arr[n-i-1], arr[i]
    }
    // print the reversed array
    fmt.Println(arr)
}

