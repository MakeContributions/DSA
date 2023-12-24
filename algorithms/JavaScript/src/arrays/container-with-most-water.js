//Description: You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
// Find two lines that together with the x-axis form a container, such that the container contains the most water.
// Return the maximum amount of water a container can store.

// Time Complexity: O(n)
// Space Complexity: O(1)

//Example 1: 
// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.


//height is an array
const maxArea = function (height) {
    let i = 0;
    let j = height.length - 1;
    let area = 0;
    let max_area = 0;
    while (i < j) {
        let length = Math.min(height[i], height[j]);
        let width = j - i;
        area = length * width;
        if (area > max_area) {
            max_area = area;
        }
        if (height[i] < height[j]) {
            i++;
        }
        else {
            j--;
        }
    }
    return max_area;
};

const height = [1,8,6,2,5,4,8,3,7]
console.log(maxArea(height))