// Description: Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

//Time Complexity: O(n)
//Space Complexity: O(1)

// Example 1:
// Input: nums = [0,1,2,2,3,0,4,2], val = 2
// Output: 5, nums = [0,1,4,0,3,_,_,_]
// Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
// Note that the five elements can be returned in any order.
// It does not matter what you leave beyond the returned k (hence they are underscores).

//nums is array and val is an integer parameter
const removeElement = function (nums, val) {
    const arr = []
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] == val) {
            nums.splice(i, 1);// We can use splice function to do changes in-place
            i--;
        }
    }
    //This way we have we use extra space
    // for (let i = 0; i < arr.length; i++) {
    //     nums[i] = arr[i];
    // }
    return nums.length;
};

const arr = [0, 1, 2, 2, 3, 0, 4, 2];
const val = 2;
console.log(removeElement(arr, val))