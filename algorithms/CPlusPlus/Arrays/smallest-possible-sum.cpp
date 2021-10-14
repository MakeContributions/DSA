//smallest-possible-sum
//Given an array of n elements,the smallest possible value we can get by adding any elements from the given array

//time complexity : O(n) || space complexity : O(1)
// n: size of array

#include <bits/stdc++.h>
using namespace std;

int smallest_possible_sum(vector<int> &arr) //function to calculate smallest_possible_sum
{
  int sum=0,n=arr.size();
  //smallest_possible_sum would be sum of all negative numbers in the array if there are any
  // or else equal to the smallest element in the array(if all numbers are >=0)
  for(int i=0;i<n;i++)
  {
    if(arr[i]<0)
      sum+= arr[i];  
  }

  if(sum!=0) //if ans is not equal to zero, there was at least 1 negative number
  {
    return sum;
  }
  else
  {
    int min_ele= *min_element(arr.begin(),arr.end());
    return min_ele;
  }
}

int main()
{
    int size;
    cout<<"Enter the size of array: ";
    cin>>size;

    vector<int> arr(size); // for storing array of n elements
    for(int i=0;i<size;i++)
      cin>>arr[i];

    int res= smallest_possible_sum(arr);

    cout<<"The smallest possible sum is : "<<res<<"\n";

    return 0;
}
