/*
	Problem Statement : Given an array of integers nums and an integer target, return indices of
						the two numbers such that they add up to target.
						You may assume that each input would have exactly one solution, and you may
						not use the same element twice.

	Input: An array of integers and a target (int)
	Output: array of indexes of len(2) with sum of element at that index equal to target or nil
*/

package arrays

/*
	Using Brute Force : For every element check for another element if it exist in the array such that sum of
						both the element is equals to the target
	Time Complexity   : O(n^2)
*/
func twoSum(arr []int, target int) []int {
	for i := 0; i < len(arr); i++ {
		for j := i + 1; j < len(arr); j++ {
			if arr[i]+arr[j] == target {
				return []int{i, j}
			}
		}
	}
	return nil
}

/*
	Using Map := While traversing every element add the element as key and its position as its value in a map
  				 Check the required value (i.e target - arr[i]) in the map
  				 If the map contains the required value then we have two elements with the required sum and
				 return the positions.
	Time Complexity : O(n)
*/
func twoSumEfficient(arr []int, target int) []int {
	m := make(map[int]int)
	for i := 0; i < len(arr); i++ {
		compliment := target - arr[i]
		if _, ok := m[compliment]; ok {
			return []int{m[compliment], i}
		}
		m[arr[i]] = i
	}
	return []int{}
}
