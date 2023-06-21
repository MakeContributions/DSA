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
#include <iostream>
using namespace std;
//Binary search function. It returns the smallest element in the rotated array.
int findSmallestElement(int nums[], int n) {
    int low = 0;
    int high = n - 1;
    
    while (low < high) {
        int mid = low + (high - low) / 2;
        
        if (nums[mid] > nums[high]) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    
    return nums[low];
}

int main() {
    int nums[] = {5, 6, 8, 9, 10, 2, 3, 4};
    int n = sizeof(nums) / sizeof(nums[0]);
    int smallest = findSmallestElement(nums, n);
    cout << "The smallest element in the rotated array is: " << smallest << endl;
    return 0;
}
