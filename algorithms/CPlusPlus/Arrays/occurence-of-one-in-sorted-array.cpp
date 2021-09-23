/*
Description: Index of first 1 in a sorted array of 0s and 1s.
Given a sorted array consisting 0’s and 1’s. The task is to find the index of first ‘1’ in the given array.

Approach: Use binary search to solve in least time complexity (O log n).
*/

#include <iostream>
#include <algorithm>
using namespace std;
 int firstIndex(int a[], int n)  {
      
      int low=0;
      int high=n-1;

      while(low<=high) {
          int mid = (low+high)/2;
            //if mid appears to be 0, update low as mid+1 index because we want to search 1 in array
            if(a[mid]==0){
                low=mid+1;
            }
            //checking if mid element is 1 and the element at mid-1 is 0
            //if it is so, then we have found index of first 1
            //simply return mid
            else if(a[mid]==1 && (mid==0 || a[mid-1]==0)){
                return mid;
            }
            //updating the high to mid-1
            //because the element at mid-1 index is not zero
            else if (a[mid]==1){
                high=mid-1;
            }
        }
        //if index not found, return -1
        return -1;
    }
int main() {
  int n;
  cout << "Enter number of elements in an array\n";
  cin>>n;
  int a[n];
  cout<<"Enter array elements: (only 0 and 1 in sorted order)\n";
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  //if someone forgets to pass sorted array
  sort(a,a+n);
  int ind = firstIndex(a,n);
  cout<<"Index of first 1 in sorted array: "<<ind;
}

/*
Sample Input:
Enter number of elements in an array
4
Enter array elements: (only 0 and 1 in sorted order)
0
0
0
1

Output:
Index of first 1 in sorted array: 3
*/
