package arrays
import("fmt")
/*
Given an integer array nums, 
return true if any value appears at least twice in the array, and return false if every element is distinct.

Example:
	Input: nums = [1, 2, 3, 1]
	Output: true

Time: O(n)
Space: O(n)

*/

func containsDuplicate(nums []int) bool {
    dictionary := make(map[int]int)
    
    for _, num := range(nums){
    if _, found := dictionary[num]; found{
			return true;
		}else{
			dictionary[num] = 1
		}
    }
    return false;
}

func runContainDuplicate(){
	nums := []int{1,2,3,1}
	hasDuplicate := containsDuplicate(nums)
	fmt.Printf("Contain Duplicate %t\n", hasDuplicate)
}