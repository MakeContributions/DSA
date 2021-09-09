package arrays

import "fmt"
/*
Given a non-empty array of int, every element appears twice except for 1.
Find that element.
*/

/*
Hash table approach
	Time: O(n)
	Space: O(n)
*/

func singleNumberWithHashTable(nums [] int) int{
	counts := make(map[int] int)
    for _, num := range nums{
        counts[num]++
    }
    
    for key, value := range counts{
        if value == 1{
            return key
        }
    }
    return -1
}

/*
Bit-manipulation approach
	Time: O(n)
	Space: O(1)
*/
func singleNumberWithConstantSpace(nums [] int) int{
	result := 0
	for _, num := range nums{
		result ^= num
	}
	return result
}

func runSingleNumber(){
	input1 := []int{2,2,1}
	input2 := []int{4,1,2,1,2}

	fmt.Printf("The Single Number for input 1 is %d\n",singleNumberWithConstantSpace(input1))
	fmt.Printf("The Single Number for input 2 is %d\n",singleNumberWithConstantSpace(input2))

	fmt.Printf("The Single Number for input 1 is %d\n",singleNumberWithHashTable(input1))
	fmt.Printf("The Single Number for input 2 is %d\n",singleNumberWithHashTable(input2))

}