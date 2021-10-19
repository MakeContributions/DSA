/*
Description: Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. 

Time Complexity: O(n) where n is the number of elements in the array
*/
#include <iostream>
#include <vector>
using namespace std;

//function starts
//will check if every jth element is smaller than ith element
vector<int> smallerNumbersThanCurrent(vector<int> &nums)
{
    vector<int> v;
    for (int i = 0; i < nums.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] < nums[i])
            {
                count++;
            }
        }
        v.push_back(count);
    }
    return v;
}

//main starts
int main()
{
    vector<int> nums = {8, 1, 2, 2, 3};
    vector<int> ans = smallerNumbersThanCurrent(nums);
    cout << "The answer is: \n";
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}

/*
Input: nums = [8,1,2,2,3]
Output: [4,0,1,1,3]
Explanation: 
For nums[0]=8 there exist four smaller numbers than it (1, 2, 2 and 3). 
For nums[1]=1 does not exist any smaller number than it.
For nums[2]=2 there exist one smaller number than it (1). 
For nums[3]=2 there exist one smaller number than it (1). 
For nums[4]=3 there exist three smaller numbers than it (1, 2 and 2).
*/