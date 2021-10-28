//c++ program to find the next greatest permutation of given number.
//Sample input 1 :
//nums =[1,2,3]
//sample output 1:
// nums =[1,3,2]
//sample input 2:
//nums =[3,2,1]
//sample output:
//nums =[1,2,3]
//time complexity:O(n).
//space complexity:O(1),because we are doing in place.
#include<bits/stdc++.h>
using namespace std;
 vector<int>nextPermutation(int n,vector<int>nums) {
         
        int k;
        int change=-1;
		//Base case if vector have size  either 0 or 1 element. 
        if(nums.size()==0 || nums.size()==1)
            return nums;
        //Base Case if vector have  size 2,simply reverse them suppose we have nums=[1,2] then output will be [2,1].    
         if(nums.size()==2)
        {
             reverse(nums.begin(),nums.end());
            
        }
        //case where the size of vector is greater the 2 start traversing from the right side 
		// While going from right to left, if we find an index whose value is less than index at right
        //   changes in permutation starts from that index.     
       for(k=nums.size()-2;k>=0;k--)
           {
             if(nums[k]<nums[k+1])
                  
             {
                 //swap(nums[k],nums[k+1]);
                 change=k;
                 break;
             }
                  
        }  
            if (change==-1)
            {
                reverse(nums.begin(),nums.end());
                //return;
            }
            //Next thing that we can observe is the value at nums[change] is always replaced by the value
          // which is greater than value at change index and occurring first while traversing from back.
            for(k=nums.size()-1;k>change;k--)
            {
                if(nums[k]-nums[change]>0)
                {
                    swap(nums[k],nums[change]);
                    break;
                }
                
            }
          //After swapping we are just sort the values from change+1 index to n-1 index. 
        reverse(nums.begin()+change+1,nums.end());
        return nums;
    }
int main()
{
    int n = 6;
    vector<int>v{5,3,4,9,7,6};
    vector<int> res;
    res = nextPermutation(n, v);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
}
 
