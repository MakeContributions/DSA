// Description: Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

//Time Complexity: O(n)
//Space Complexity: O(1)

// Example 1:
// Input: nums = [0,0,1,1,1,2,2,3,3,4]
// Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
// Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
// It does not matter what you leave beyond the returned k (hence they are underscores).

//nums is array
function removeDuplicates(nums) {
    if (nums.length === 0) {
        return 0;
    }

    let k = 1; // Initialize the count of unique elements to 1
    for (let i = 1; i < nums.length; i++) {
        if (nums[i] !== nums[k - 1]) {
            nums[k] = nums[i]; // Overwrite the next unique element
            k++;
        }
    }

    return k;
}


const arr = [0,0,1,1,1,2,2,3,3,4];
console.log(removeDuplicates(arr))