package arrays
import ("fmt")
/*
Given an array nums of size n, return the majority element.
The majority element appears more than n/2 times

Time: O(n)
Space: O(1)
*/

func majorityElement(nums []int) int {
    count := 1
    candidate := nums[0]
    
    for i:= 1; i < len(nums); i++{
        num := nums[i]
        if count == 0{
            candidate = nums[i]
            count = 1
        }else if num == candidate{
            count++
        }else if num != candidate{
            count--
        }
    }
    return candidate
}

func runmajorityElement(){
	nums1 := []int{2,2,1,1,1,2,2}
    target := majorityElement(nums1)
    fmt.Printf("Majority Element is %d\n", target)
}