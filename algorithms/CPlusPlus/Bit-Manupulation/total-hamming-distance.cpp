#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int i,j,k,one,zero;
        int result = 0;
        for(i = 0; i < 32; i++){
            k = 1 << i;
            one  = 0;
            zero = 0;
            for(auto value: nums){
                if((value & k)) one++;
                else zero++;
            }
            
            if(one == nums.size() || zero == nums.size()) continue;
            
            result += one*zero;
            
        }
        
        return result;
    }
};

int main(){
    vector<int> nums{4,14,2};

    Solution solution;

    cout<<"Total hammind distance: ";
    cout<<solution.totalHammingDistance(nums)<<endl;

    return 0;
}