/*
	Package arrays maximumSubarraySum problem
	Input: An array of integers
	Output: Subarray with maximum sum
	The Strategy: Keep track of the previous encounter sum and the current element.
 				  If the current element is largest than the previous sum + current element
				  then throw the previous sum and start with the current element as the largest sum.
	Algorithm Type: Kadane's Algorithm
	Time Complexity: O(n)
	Dry Run :
	 		[-2,1,-3,4,-1,2,1,-5,4]
	initial := largestSum = -2 , currentSum = -2
	i=1     -> currentSum = max(1,  (-2 + 1 )) = 1 ,      largestSum = max(-2, 1) = 1
	i=2		-> currentSum = max(-3, (1 + -3 )) = -2,	  largestSum = max(1, -2) = 1
	i=3 	-> currentSum = max(4,  (-2 + 4 )) = 4 , 	  largestSum = max(1, 4)  = 4
	i=4		-> currentSum = max(-1, (4 + -1 )) = 3 , 	  largestSum = max(4, 3) = 4
	i=5		-> currentSum = max(2,  (3 +  2 )) = 5 , 	  largestSum = max(4, 5) = 5
	i=6		-> currentSum = max(1,  (5 + 1  )) = 6 , 	  largestSum = max(5, 6) = 6
	i=7		-> currentSum = max(-5, (6 + -5 )) = 1 , 	  largestSum = max(6, 1) = 6
	i=8		-> currentSum = max(4,  (1 + 4 ))  = 5 , 	  largestSum = max(6, 5) = 6
*/
package arrays

import (
	"math"
)

// To find the maximum subarray sum.
func maximumSubarraySum(nums []int) int {
	maximumSum := nums[0]
	currentSum := maximumSum
	for i := 1; i < len(nums); i++ {
		currentSum = int(math.Max(float64(nums[i]), float64(nums[i]+currentSum)))
		maximumSum = int(math.Max(float64(maximumSum), float64(currentSum)))
	}

	return maximumSum
}
