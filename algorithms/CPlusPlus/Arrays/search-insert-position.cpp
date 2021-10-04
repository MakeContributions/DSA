/*
Description: Given a sorted array of distinct integers and a target value, 
return the index if the target is found. If not, return the index where it
would be if it were inserted in order.

Approach: Using Binary search to solve in least time complexity.

Time Complexity: O(log n)
*/

#include <iostream>
#include <vector>
using namespace std;

//function 
int searchInsert(vector<int>& nums, int target) {
    //starting index
    int start=0;
    //ending index
    int end=nums.size()-1;
    while(start<=end){
        //calculating mid element
        int mid = start + (end-start)/2;
        //if target found, return the index
        if(nums[mid]==target){
            return mid;
        }
        if(nums[mid]>target){
             end=mid-1;
        }
        else{
            start=mid+1;
       }
    }
    //returning end+1 so that we can get the index where the target element can be inserted
    return end+1;
        
}

//main starts
int main() {
    cout << "Enter number of elements in the array\n";
    int n;
    cin>>n;
    cout<<"Enter the array elements\n";
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<"Enter the target element\n";
    int target;
    cin>>target;
    cout<<"The target element can be inserted at: "<<searchInsert(nums,target);
    return 0;
}

/*
Example 1
Input: nums = [1,3,5,6], target = 5
Output: 2
(Since the target element is present it will return its index)

Example 2:
Input: nums = [1,3,5,6], target = 2
Output: 1
(Since the target element is not present in the nums array, it will return the position where the target element can be inserted)
We can insert 2 at position 1 - [1,2,3,5,6]

*/