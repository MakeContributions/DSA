/*

The Boyer-Moore voting algorithm is one of the popular optimal algorithms which is used to find the majority element among the given elements that have more than N/ 2 occurrences. This works perfectly fine for finding the majority element which takes 2 traversals over the given elements, which works in O(N) time complexity and O(1) space complexity.

Original credit : https://www.geeksforgeeks.org/boyer-moore-majority-voting-algorithm/

*/


// Function to find majority element
function findMajority(nums) {
    var count = 0, candidate = -1;

    // Finding majority candidate
    for (var index = 0; index < nums.length; index++) {
        if (count == 0) {
            candidate = nums[index];
            count = 1;
        }
        else {
            if (nums[index] == candidate)
                count++;
            else
                count--;
        }
    }

    // Checking if majority candidate occurs more than
    // n/2 times
    count = 0;
    for (var index = 0; index < nums.length; index++) {
        if (nums[index] == candidate)
            count++;
    }
    if (count > (nums.length / 2))
        return candidate;
    return -1;

    // The last for loop and the if statement step can
    // be skip if a majority element is confirmed to
    // be present in an array just return candidate
    // in that case
}


