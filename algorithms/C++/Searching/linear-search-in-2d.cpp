/*
Description: program to perform linear search in 2d array

Time complexity: O (m*n) where m is the number of rows and n refers to the number of columns
*/

#include <iostream>
#include <vector>
using namespace std;

//function starts
void linearSearch(vector<vector<int>> arr, int target)
{
    //for every row
    for (int i = 0; i < arr.size(); i++)
    {
        //for every element in the row, i.e column
        for (int j = 0; j < arr[i].size(); j++)
        {
            //check if the element in the array is equal to the target
            if (arr[i][j] == target)
            {
                cout << i << " " << j; //print it
                return;
            }
        }
    }
    cout << "Element not found"; //else print element not found
}

//main starts
int main()
{
    vector<vector<int>> arr = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}}; //array

    int target = 9;            //element need to be search
    linearSearch(arr, target); //calling the function

    return 0;
}

/*
Input:
arr = [
    [1,2,3],
    [4,5,6],
    [7,8,9]
]
target = 9

Output: 2 2
*/