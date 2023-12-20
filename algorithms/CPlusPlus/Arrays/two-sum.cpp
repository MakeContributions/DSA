//Description :c++ solution to find all the unique two indices in an array whose sum is equal to the give number in O(n) complexity.
//using this method we will be able to find all the unique pairs
//Time Complexity : O(n), where n is the array size
//Space Complexity : O(n),map data structure will be used.
//sample
//input 1: nums = [2,7,11,15], target = 9
//output 1: [0,1]
//explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

//input 2: nums = [3,2,4], target = 6
//output 2: [1,2]
//explanation: Because nums[1] + nums[2] == 6, we return [1, 2].

#include<iostream>
#include<vector>
#include<map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    map<int,int> mp;
    vector<int> vec;
    for(int i=0;i<nums.size();i++)
    {
        int temp = target - nums[i];
        if(mp.find(temp)==mp.end()){
            mp.insert({nums[i] ,i});
        }
        else{
            vec.push_back(mp[temp]);
            vec.push_back(i);
        }
    }
    return vec;
}

int main() {
    //you can take array and target as an input from user.
    vector<int> num = {2,7,11,15};
    vector<int> ans;
    int target = 9;
    ans = twoSum(num, target);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}


