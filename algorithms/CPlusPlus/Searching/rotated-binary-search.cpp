// You are given a sorted array of distinct integers. 
// However, the array has been rotated an unknown number of times in a clockwise direction.
// Your task is to find the smallest element in the rotated array using the binary search algorithm.

// Write a function findSmallestElement that takes in an array of integers, nums, and its size, n, as parameters.
// The function should return the smallest element in the rotated array.

// Note:

// The array nums is rotated in a clockwise direction, which means that some elements from the beginning of the original 
// sorted array have been moved to the end in an unknown pattern.
// The array does not contain any duplicate elements.



// C++ program to implement binary search on an array of integers, rotated an unknown number of times.
//Time complexity - O(log n).
#include <iostream>
using namespace std;

int findSmallestElement(int nums[], int n) {
    int low = 0;                    // Initialize the low pointer to the start of the array
    int high = n - 1;               // Initialize the high pointer to the end of the array

    while (low < high) {            // Perform binary search until low becomes equal to high
        int mid = low + (high - low) / 2;   // Calculate the middle index
        
        if (nums[mid] > nums[high]) {       // If the element at mid is greater than the element at high
            low = mid + 1;                  // Update low to mid + 1, as the smallest element is to the right of mid
        } else {
            high = mid;                     // Otherwise, update high to mid, as the smallest element is at mid or to the left
        }
    }
    
    return nums[low];               // Return the element at low, which is the smallest element in the rotated array
}

int main() {
    int nums[] = {5, 6, 8, 9, 10, 2, 3, 4};
    int n = sizeof(nums) / sizeof(nums[0]);
    int smallest = findSmallestElement(nums, n);
    cout << "The smallest element in the rotated array is: " << smallest << endl;
    return 0;
}

