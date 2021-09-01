package searching

import "fmt"

/*

Find the minimum element in the rotated sorted array(ascending order).
An array [a[0], a[1], a[2], ..., a[n-1]] after 1 rotation will be [a[n-1], a[0], a[1], a[2], ..., a[n-2]]

All elements are unique

*/
func findMin(nums []int) int {
    if len(nums) == 1 || nums[0] < nums[len(nums)-1]{
        return nums[0]
    }
    
    front, back := 0, len(nums) -1 
    for front <= back {
        mid := (front+back) / 2
        if nums[mid] > nums[mid+1]{
            return nums[mid+1]
        }else if nums[mid] < nums[mid-1]{
            return nums[mid]
        }

        if nums[mid] > nums[0]{
            front = mid + 1
        }else if nums[mid] < nums[0]{
            back = mid - 1
        }
    }
    return 0
}

//I will hard-code the input for now but feel free to modify
func runFindMin(){
	nums1 := []int{4,5,6,7,8,0,1,2}
	result1 := findMin(nums1)
	fmt.Println(result1) 	// should print 0

	nums2 := []int{1,2,3,4,5,6,7,8}
	result2 := findMin(nums2)
	fmt.Println(result2) 	// should print 1
}