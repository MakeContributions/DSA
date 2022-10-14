//Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N is an element that appears more than N/2 times in the array.

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
//Time Complexity = O(n)
//Space Complexity = O(1)

//Application of moore's algorithm
class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        
        // your code here
        int m;
        int i=0;
        for(int j=0; j<size; j++)
        {
            if(i==0)
            {
                m=a[j];
                i+=1;
            }
            else if(m==a[j])
            {
                i+=1;
            }
            else
            {
                i-=1;
            }
        }
        i=0;
        for(int j=0; j<size; j++)
        {
            if(a[j]==m)
            {
                i+=1;
            }
        }
        if(i>size/2)
        {
            return m;
        }
        else
        {
            return -1;
        }
    }
};


int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}
