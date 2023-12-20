//Description: Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique ///element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums
//Time Complexity: O(n)
//Space Complexity: O(n)

//Input: nums = [1,1,2]
//Output: 2, nums = [1,2,_]

package main

import "fmt"

func removeDuplicates(nums []int) int {
	ans := []int{}
	var j int = 0

	ans = append(ans, nums[0])

	for i := 0; i < len(nums); i++ {
		if nums[i] != nums[j] {
			j = i
			ans = append(ans, nums[i])
		}
	}
	// for i := 0; i < len(ans); i++ {
	// 	nums[i] = ans[i]
	// }
	copy(nums, ans)
	_ = j
	return len(ans)
}

func mainRemoveDuplicates() {
	arr := []int{1, 2, 2, 3, 4, 4, 4, 5}
	res := removeDuplicates(arr)
	fmt.Println(res)
}
