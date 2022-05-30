/*
Given an array of distinct numbers, nums
find all the possible permutations. You can return the answer in any order.

Example:
    Input: nums = [1,2,3]
    Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> permute(vector<int> &nums);
void helper(vector<int> newNum, vector<int> current, vector<vector<int>> &result);

//Input will be similar to the example above, free feel to test with any kind of input
int main(){
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> permutations = permute(nums);
    for(int i  = 0 ; i < permutations.size(); i++){
        for(int j = 0; j < permutations[i].size();j++){
            cout<< permutations[i][j]<<" ";
        }
        cout<<endl;
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    helper(nums, {}, result);
    return result;
}

void helper(vector<int> newNum, vector<int> current, vector<vector<int>> &result){
    if(newNum.size() == 0 && current.size() > 0){
        result.push_back(current);
    }else{
        for(int i = 0; i < newNum.size(); i++){
            vector<int> newArray;
            newArray.insert(newArray.end(), newNum.begin(), newNum.begin() + i);
            newArray.insert(newArray.end(), newNum.begin()+i+1, newNum.end());
            vector<int> newPerms = current;
            newPerms.push_back(newNum[i]);
            helper(newArray, newPerms, result);
        }
    }
}