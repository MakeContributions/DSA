//Description: Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
// The overall run time complexity should be O(log (m+n)).

// Space Complexity: O(n)
// Time Complexity: O(n)

// Example 1:

// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.
// Example 2:

// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.


var findMedianSortedArrays = function (nums1, nums2) {
    let ans = [];
    let i = 0, j = 0;

    while (i < nums1.length && j < nums2.length) {
        if (nums1[i] < nums2[j]) {
            ans.push(nums1[i]);
            i++;
        }
        else {
            ans.push(nums2[j]);
            j++;
        }
    }
    for (; i < nums1.length; i++) {
        ans.push(nums1[i]);
    }
    for (; j < nums2.length; j++) {
        ans.push(nums2[j]);
    }

    let mid = Math.floor(ans.length / 2);
    if (ans.length % 2 === 0) {
        return (ans[mid - 1] + ans[mid]) / 2;
    } else {
        return ans[mid];
    }
};

const nums1 = [1,2]
const nums2 = [3,4]
console.log(findMedianSortedArrays(nums1, nums2))

