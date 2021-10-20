//Description :c++ solution to find all the unique triplet without using any extra space.
//using this method we will be able to find all the unique triplets 
//Time Complexity : O(n), where n is the array size
//Space Complexity : O(1),it will take only constant amount of time.
//sample 
// input 1: arr[]=[-1,0,1,2,-1,4]
//output 1:[[-1,0,1][-1,-1,2]]
//input 2:arr[]=[]
//output 2:[]

#include<bits/stdc++.h>
using namespace std;

    void findTriplet(int arr[],int n,int sum) {
    
	int i;
 
    // Sort the input array
    sort(arr, arr + n);
 
    // For handling the cases when no such
    // triplets exits.
    bool flag = false;
 
    // Iterate over the array from start to n-2.
    for (i = 0; i < n - 2; i++)
    {
        if (i == 0 || arr[i] > arr[i - 1])
        {
            // Index of the first element in
            // remaining range.
            int start = i + 1;
 
            // Index of the last element
            int end = n - 1;
 
            // Setting our new target
            int target = sum - arr[i];
 
            while (start < end)
            {
                // Checking if current element
                // is same as previous
                if (start > i + 1
                    && arr[start] == arr[start - 1])
                {
                    start++;
                    continue;
                }
 
                // Checking if current element is
                // same as previous
                if (end < n - 1
                    && arr[end] == arr[end + 1])
                {
                    end--;
                    continue;
                }
 
                // If we found the triplets then print it
                // and set the flag
                if (target == arr[start] + arr[end])
                {
                    cout << "[" << arr[i]
                         << "," << arr[start]
                         << "," << arr[end] << "] ";
                    flag = true;
                    start++;
                    end--;
                }
                // If target is greater then
                //  increment the start index
                else if (target > (arr[start] + arr[end]))
                {
                    start++;
                }
                // If target is smaller than
                // decrement the end index
                else {
                    end--;
                }
            }
        }
    }
 
    // If no such triplets found
    if (flag == false) {
        cout << "No Such Triplets Exist"
             << "\n";
    }
	
}
int main()
{
//	int arr[]={12,3,6,1,6,9};
int arr[]={-1,0,1,2,-1,-4};
	int n=sizeof(arr)/sizeof(arr[0]);
	int sum=0;
	findTriplet(arr,n,sum);
	return 0;
	
}
