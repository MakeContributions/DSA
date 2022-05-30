/*
Description: linear search using recursion

Time Complexity: O(n) where n is the number of elements in the array
*/

#include <iostream>
#include <vector>
using namespace std;

//function starts
int linearSearch(vector<int> arr, int i, int n, int target)
{
    //base case
    if (i == n)
    {
        return -1;
    }
    //if the ith element in the array is equal to the target, return the index
    if (arr[i] == target)
    {
        return i;
    }
    //recursive function call
    //i refers to the index that we will need to check the element in the array
    //at every recursive call we will increment the i by 1
    return linearSearch(arr, i + 1, n, target);
}

//main starts
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();
    int target = 3;
    cout << linearSearch(arr, 0, n, target);
    return 0;
}

/*
Input:
arr = [1,2,3,4,5]
target = 3

Output:
2

*/