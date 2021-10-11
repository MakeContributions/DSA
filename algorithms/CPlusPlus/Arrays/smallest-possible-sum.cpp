//smallest possible sum in a given array of elements
//time complexity : O(n) || space complexity : O(1)
// n: size of array 

#include <bits/stdc++.h>
using namespace std;

int smallest_possible_sum(vector<int> &arr,int n) //function to claculate smallest_possible_sum
{
  int ans=0;
  //smallest_possible_sum would be sum of all negative numbers in the array if there are any
  // or else equal to the smallest element in the array(if all numbers are >=0)
  for(int i=0;i<n;i++)
  {
    if(arr[i]<0)
    ans+= arr[i];
  }

  if(ans!=0) //if ans is not equal to zero, there was atleast 1 negative number
  {
    return ans;
  }
  else
  {
    int min_ele=INT_MAX;

    for(int i=0;i<n;i++)
    min_ele=min(min_ele,arr[i]);

    return min_ele;
  }
}

int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    vector<int> arr(n); // for storing array of n elements
    for(int i=0;i<n;i++)
    cin>>arr[i];

    int ans= smallest_possible_sum(arr,n);

    cout<<"The smallest possible sum is : "<<ans<<"\n";

    return 0;
}
