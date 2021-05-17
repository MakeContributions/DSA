//Description : To Find Square root of number using Binary Search 
#include<bits/stdc++.h>
using namespace std;
int square(int n) {
    int low = 0;   //Lower index
    int res = 0;  //Resultant Square Root
    int high = n; //Upper index
    while (low <= high) {
        int mid = (low + high) / 2;        //Calculate middle index  using low & high 
        if (mid * mid == n) {              //If square of mid becomes equal to the n, then we found the square root and return the middle index
            return mid;
        } else if (mid * mid < n) {        //Else if square of mid is less than n, then we ignore the left half and move to the right half
            res = mid;                     //and also save the potential element in the res
            low = mid + 1;
        } else {
            high = mid - 1;               //If square of mid  is greater than n, then we ignore the right half and move to the left half
        }
    }
    return res;
}
int main() {
    int n;
    cin>>n;
    cout<<square(n);
    return 0;
    //Ex: 15
    //Output:3
    //Time Complexity : O(log n)
    //Auxiliary Space : O(1)
}
