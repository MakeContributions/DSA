/* Maximum contiguous subarray Sum of array brute to optimized all approaches */

#include <bits/stdc++.h>
using namespace std;
//example int arr[3]={-1,3,-2};
/*subarrays are  
                 -1 
                 -1 3 
                 -1 3 -2 
                  3 
                  3 -2 
                 -2 
                  3

ans=3
*/
int max_subarray_sum_method_1(int arr[],int n)
{
    int sum,maxi;//declaring variables
    maxi=INT_MIN;//initializing maxi by minimum value;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {   sum=0;
                for(int k=i;k<=j;k++)
                {
                 sum+=arr[k];//taking sum of elements from ith position to jth position
                }
                maxi=max(maxi,sum);//taking max of our final answer maxi and sum
            }
        }
        return maxi;
}

//further optimized version by for two loops 

int max_subarray_sum_method_2(int arr[],int n)
{
    int sum,maxi;//declaring variables
    maxi=INT_MIN;//initializing maxi by minimum value;
        for(int i=0;i<n;i++)
        {  sum=0;
            for(int j=i;j<n;j++)
            {   
                sum+=arr[j];//as we are just adding an element in our subarray so we can remove the k loop.
                maxi=max(maxi,sum);//and taking max of maxi and sum 
            }
        }
        return maxi;
}
//most optimized version kadane's algo with one for loop
int max_subarray_sum_method_3(int arr[],int n)
{
      int sum,maxi;//declaring variables
      sum=0,maxi=arr[0];//initializing sum by 0 and maxi by 0th element;
        for(int i=0;i<n;i++)
        { 
            sum+=arr[i];
            maxi=max(sum,maxi);
            if(sum<0) sum=0;
        }
        return maxi;
}
// optimized version kadane's algo with one loop
long long max_subarray_sum_method_4 (int arr[],int n) {  //used for long and big values or integers
    long long sum,maxi=0; //declaring variables
    for (int i=0; i<size; i++) {
        maxi= maxi+arr[i];  
        if (sum<maxi) {  //if maxSum is greater then maxElement then the maxSum == maxElement 
            sum=maxi;
        }
        else if (maxi<0) { //if elements in array is 0 then return 0
            sum=0;
        }
    }
    cout<<"\nUsing Kadane's Algoritham maximum sum of subarray is: "<<sum;
    return 0;
}

int main()
{
 int n;
 cout<<"Enter the size of array"<<endl;
 cin>>n;
 int arr[n];
 for(int i=0;i<n;i++)
 {  cout<<"Enter "<<i<<"th elements of array"<<endl;
    cin>>arr[i];
 }
 int ans1=max_subarray_sum_method_1(arr,n);//this is brute force approach time complexity=O(n^3) || space complexity=O(1);
 int ans2=max_subarray_sum_method_2(arr,n);//this is optimized brute force approach time complexity=O(n^2) || space complexity=O(1);
 int ans3=max_subarray_sum_method_3(arr,n);//this is further optimized approach called "Kadane's Algorithm" time complexity=O(n)|| space complexity=O(1);
 int ans4=max_subarray_sum_method_4(arr,size);//this is optimized approach time complexity=O(n) || space complexity=O(1);
 cout<<"max_subarray_sum:"<<ans1<<endl;
 cout<<"max_subarray_sum:"<<ans2<<endl;
 cout<<"max_subarray_sum:"<<ans3<<endl;
 cout<<"max_subarray_sum:"<<ans4<<endl; //print any ans1,ans2,ans3,ans4;
}

