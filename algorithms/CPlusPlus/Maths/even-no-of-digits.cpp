/*
Description: Given an array nums of integers, return how many of them contain an even number of digits.

Time Complexity: O(n) where n is the size of the array
*/

#include <iostream>
#include <vector>
using namespace std;

//function to count the number of digits of every array element
int countdigits(int n)
{
    int c = 0;
    while (n > 0)
    {
        n = n / 10;
        c++;
    }
    //return the count
    return c;
}

int findNumbers(vector<int> &nums)
{
    int count = 0;
    for (auto it : nums)
    {
        //countdigits() will return the number of digits present in the element
        int dc = countdigits(it);
        //if it is even, increment the count
        if (dc % 2 == 0)
        {
            count++;
        }
    }
    //at the end, return the count
    return count;
}

//main starts
int main()
{
    vector<int> nums = {12, 345, 2, 6, 7896};
    cout << "Number of even no. digits are: " << findNumbers(nums);
    return 0;
}

/*
Input: nums = [12,345,2,6,7896]
Output: 2
Explanation: 
12 contains 2 digits (even number of digits). 
345 contains 3 digits (odd number of digits). 
2 contains 1 digit (odd number of digits). 
6 contains 1 digit (odd number of digits). 
7896 contains 4 digits (even number of digits). 
Therefore only 12 and 7896 contain an even number of digits.
*/