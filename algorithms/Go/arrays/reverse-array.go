//Description : This program reverses array elements by swapping the first half part of the array
//Time Complexity : O(n/2), where n is the array size
//Auxiliary Space : O(1)

package arrays

import ("fmt")

func ReverseArray(arr []int) {
    // get the length of the array
    n := len(arr)
    // iterate over half of the array and swap corresponding elements
    for i := 0; i < n/2; i++ {
        arr[i], arr[n-i-1] = arr[n-i-1], arr[i]
    }
    // print the reversed array
    fmt.Println(arr)
}

