#include<iostream>
#include<climits>
#define endl "\n"
using namespace std;

// Maximum Subarray Sum 

// Approach A - Brute Force O(n^3)
int maxSubArrSum_A(int a[],int n){
    int maxSum = INT_MIN;
    for(int i=0;i<n;++i){
        for(int j=i;j<n;++j){
            int sum = 0;
            for(int k=i;k<=j;++k){
                sum = sum + a[k];
            }
            maxSum = max(maxSum,sum);
        }
    }
    return maxSum;
}

// Approach B - Cumulative Sum Approach O(n^2)
int maxSubArrSum_B(int a[],int n){
    int currSum[n+1]; currSum[0] = 0;
    for(int i=1;i<=n;++i){
        currSum[i] = currSum[i-1] + a[i-1];
    }
    int maxSum = INT_MIN;
    for(int i=1;i<=n;++i){
        for(int j=0;j<i;++j){
            int sum = 0;
            sum =  currSum[i] - currSum[j];
            maxSum = max(maxSum,sum);
        }
    }
    return maxSum;
}

// Approach C - Kadane's Algo O(n)
int maxSubArrSum_C(int a[],int n){
    int currSum=0;
    int maxSum = INT_MIN;
    for(int i=0;i<n;++i){
        currSum += a[i];
        if(currSum < 0) currSum = 0;
        maxSum = max(maxSum,currSum);
    }
    
    return maxSum;
}

//Utility function to print array
void printArr(int a[],int n){
    for(int i=0;i<n;++i) cout<<a[i]<<" ";
    cout<<endl;
}


int main(){
    //Some sample test cases
    int a[] = {5,6,0,4,-1,4,7,2}; // n=8
    int b[] = {4,-4,6,-6,10,-11,12}; // n=7
    int c[] = {3,4,1,0,-2,-6,8,3}; // n=8
    cout<<maxSubArrSum_A(b,7)<<endl;
    cout<<maxSubArrSum_B(b,7)<<endl;
    cout<<maxSubArrSum_C(b,7)<<endl;
    return 0;
}
