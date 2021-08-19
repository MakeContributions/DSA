/*

Digit dp is a very easy technique and also useful to solve many dynamic programming problems. 
Seeing the name “Digit DP” it’s easy to guess that we are going to do something using the digits. Yes we are actually going to play with digits. 

##PROBLEM-

Let’s explain the concept using a classical problem.
How many numbers x are there in the range a to b, where the digit d occurs exactly k times in x? 
There may have several solutions including number theory or combinatorics, 
but let’s see how we can solve this problem using digit dp.

*/

#include<bits/stdc++.h>
using namespace std;

//Function which returns a given number in the vector;
vector<int> convertnumtoarr(int n){
    vector<int>ans;
    while(n){
        ans.push_back(n%10);
        n=n/10;
    }
    reverse(ans.begin(),ans.end());
    return ans;

}

//THe function that generated all the number in the range of nums and also keep trak of digit occurence
int digitdp(int index,int flag,int cnt,int d,int k,vector<int>nums){

    //base cases
    if(index==nums.size()){
        //if cnt ==k means that generated digit has k 'd' digits so it returns 1;
        if(cnt==k){
            return 1;

        }
        //if k!=cnt that means the digit formed does not satisfy the condition hence it returns 0;
        else{
            return 0;
        }
    }

    //Initially limit is 9 that means we call fill digit from 0 to 9;
    int limit =9;
    //if flag==0 means that digit is smaller already and it should not be made greated and hence 
    //limit should be nums[index];
    if(flag==0)limit=nums[index];

    int count=0;
    for(int i=0;i<=limit;i++){
        //if the digit that is being filled now if smaller then we have the priviledge to fill next digit
        //hence flag is made 1;
            if(i<nums[index]){
                //if i==d then cnt should be incremented as we added digit d in the sequence of number that is being formed
                if(i==d){
                    count+=digitdp(index+1,1,cnt+1,d,k,nums);
                }else{
                    //if i!=d just a recursive call to the next index is made with flag 1 and no change in cnt
                    count+=digitdp(index+1,1,cnt,d,k,nums);
                }
            }else{
                //if i >=nums[index] no change in the flagf should be made.
                if(i==d){
                    count+=digitdp(index+1,flag,cnt+1,d,k,nums);
                }else{
                    count+=digitdp(index+1,flag,cnt,d,k,nums);
                }
            }
    }

        return count;
        //return the number from range l to r which have digit d in it k times;
}


int main(){
    /*
    input - l is the left range;
            r is the right range;
            d is the digit that we have to keep trak in range l to r;
            k is the number of times the digit d appears in the range l to r;
    */
    int l ,r,d,k;
    cin>>l>>r>>d>>k;

/*
    keep in mind that first we find ans for range 0 to r;
    then we find the ans for o to l-1;
    and finally the output will be ans(r)-ans(l-1);
*/  

    //converting r to vector;

    vector<int>nums = convertnumtoarr(r);
    //getting the ans for range 0 to r
    int ans1 =digitdp(0,0,0,d,k,nums);
    //converting l-1 to vector;
    nums = convertnumtoarr(l-1);
    //getting ans for l-1;
    int ans2 = digitdp(0,0,0,d,k,nums);
    //finally the required output will be ans(r)-ans(l-1);
    cout<<ans1-ans2<<endl;
    return 0;
}