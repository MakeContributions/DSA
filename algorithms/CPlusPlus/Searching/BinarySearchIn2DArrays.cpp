// C++ program to implement Binary Search in 2D Arrays
#include <iostream>
#include <vector>
using namespace std;

// Floor of a array is the greatest number which is smaller than or equal to the target element
// Search the floor number in the first column. Since the array is sorted that means the target element
// should lie on the row which has the first element as its floor
int Floor(vector<vector<int>> arr, int target)
{
    int start = 0;
    int end = arr.size() - 1;
    if(target < arr[start][0])
        return arr[start][0];
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if(target < arr[mid][0])
            end = mid - 1; 
        else if(target > arr[mid][0])
            start = mid + 1;
        else 
            return mid; // if it is the target element return the column index
    }
    return end; // Since the condition in which the loop breaks is start > end that means the end will be smaller than target element
    // whereas start will be greater than target element.
}

// Search just in a row which has its first element smaller than or equal to target element(floor)
vector<int> BinarySearch(vector<vector<int>> arr, int target)
{
    int floor = Floor(arr, target);
    int start = 0;
    int end = arr[floor].size() - 1;
    while(start <= end)
    {
        int mid = start + (end - start) / 2;
        if(target > arr[floor][mid])
            start = mid + 1;
        else if(target < arr[floor][mid])
            end = mid - 1;
        else
            return {floor, mid};
    }
    return {-1 , -1};  // If element is not found return negatives.
}


int main(int argc, char const *argv[])
{
    vector<vector<int>> arr = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    vector<int> ans = BinarySearch(arr, 15); 

    cout << "[ " << ans[0] << " , " << ans[1] << " ]" << endl;  // [3, 2] for such target element

    
    return 0;
}