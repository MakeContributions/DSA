// Function to search data using jump search

#include <iostream>
#include <cmath>
using namespace std;

int jumpSearch(int arr[], int n, int key)
{
    int start = 0;
    int end = sqrt(n);          //the square root of array length
    while (arr[end] <= key && end < n)
    {
        start = end;            //if it is not correct block then shift block
        end += sqrt(n);
        if (end > n - 1)
            end = n;            //if right exceeds then bound the range
    }
    for (int pos = start; pos < end; pos++)
    { //perform linear search
        if (arr[pos] == key)
            return pos;         //the correct position of the key
    }
    return -1;                  // if element is not found
}
//recursive jump search function to search data in an array
int recursive_jump_search(int *arr,int start,int end,int n,int to_search,int jump)
{
    // if end index of n is greater than n that means data not found so return -1
    if(end>n)
        return -1;
    // is the element to search is greater than end index and end index is less than n than we need to jump
    else if(arr[end]<to_search)
    {
    start=end;
    end=end+jump;
    }
    // if else block run means data is between start and end index so then search linearly
    else
    {
                  // until start is less or equal to end run the loop
                  while(start<=end)
            {
                // if data found then return the data index number
                if(arr[start]==to_search)
                    return start;
               // if data not found at arr start th index then move forward
                start++;
            }
            // if data not found the the loop will stop and return -1
            return -1;
    }
// call the recursive jump search again with few changes in start and end
return recursive_jump_search(arr,start,end,n,to_search,jump);
}
int main()
{
    int n, key, loct;
    cout << "Enter the length of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of array:"<<endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i]; // Taking input
    cout << "Enter search key: ";
    cin >> key;
    //Calling of jumpSearch function and getting a location back
    cout<<"Iterative Solution:"<<endl;
    if ((loct = jumpSearch(arr, n, key)) != -1)
        cout << "Element found at location: " << loct << endl;
    else
        cout << "Element does not exist in the array." << endl;
        cout<<"Recursive solution:"<<endl;
        if ((loct=recursive_jump_search(arr,0,n-1,n,key,(int)sqrt(n-1))) != -1)             //Calling of recursive jump Search function and getting a location back
        cout << "Element found at location: " << loct << endl;
    else
        cout << "Element does not exist in the array." << endl;

return 0;

}
/*
Input: Enter the length of array: 5
       Enter the elements of array:
       1 2  3  4  5
       Enter search key: 4
       Iterative Solution:
       Element found at location: 3
       Recursive Solution:
       Element found at location: 3

Time complexity: O(square root (n))

*/
