/*

    Program to check For a given range of integers between l to r how many number have their 
    first and last digit same;    
*/


#include<bits/stdc++.h>
using namespace std;

//Function which converts the number into the vector so that each of its digit 
//can be accessed by using the index;
vector<int> convertnumtoarr(int n){
    vector<int>ans;
    while(n){
        ans.push_back(n%10);
        n=n/10;
    }
    reverse(ans.begin(),ans.end());
    return ans;

}

//Recusrsive digit dp function that forms the number between range o to nums;

int digitdp(int index,int flag,int first,int last,vector<int>nums){

    //base cases
    if(index==nums.size()){
        //if first ==last then we add 1 to our ans
        if(first==last){
            return 1;
        }
        //if first is not equal to last we jst return 0;
        else{
            return 0;
        }
    }

    //Initially limit is 9 that means we call fill digit from 0 to 9;
    int limit =9;
    ////if flag==0 means that digit is smaller already and it should not be made greated and hence 
    //limit should be nums[index]; 
    if(flag==0)limit=nums[index];

    int count=0;
    for(int i=0;i<=limit;i++){
            if(i<nums[index]){
                //if first is equal to zero means no digit is filled so first and last both will be i;
                if(first==0){
                    count+=digitdp(index+1,1,i,i,nums);
                }else{
                    //ELse first remains same what it is last is passed as i ;
                    count+=digitdp(index+1,1,first,i,nums);
                }
            }else{
                //if first is equal to zero means no digit is filled so first and last both will be i;

                if(first==0){
                    count+=digitdp(index+1,flag,i,i,nums);
                }
                 //ELse first remains same what it is last is passed as i ;
                else{
                    count+=digitdp(index+1,flag,first,i,nums);
                }
            }
    }

        return count;
        //return the number of digit from 0 to nums which have first and last digit same;

}


int main(){

    /*
    input l-Left range;
           r-right range
    */
    int l ,r;
    cin>>l>>r;


    //converting the range r to vector;
    vector<int>nums = convertnumtoarr(r);
    //getting the ans for o to r;
    int ans1 =digitdp(0,0,0,0,nums);
    //converting l-1 to vector;
    nums = convertnumtoarr(l-1);
    //getting ans for the range l-1;
    int ans2 = digitdp(0,0,0,0,nums);
    //output is ans(r)-ans(l-1)
    cout<<ans1-ans2<<endl;
    return 0;
}