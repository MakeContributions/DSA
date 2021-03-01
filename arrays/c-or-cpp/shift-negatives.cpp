#include<bits/stdc++.h>
using namespace std;

// Move all negative elements to left and positives to right side of the array

// Approach 1 --> Partition Algo - O(n)
void shiftNegatives_A(int arr[],int size){
    int j = -1,pivot=0;
    for(int i=0;i<size;++i){
        if(arr[i]<pivot){
            j++;
            swap(arr[i],arr[j]);
        }
    }
}

// Approach 2 -->  Two-pointer Method - O(n)
void shiftNegatives_B(int arr[],int size){
    int left = 0, right =  size-1;
    while(left < right){
        if(arr[left]<0 && arr[right]<0){
            left++;
        }
        else if(arr[left]>0 && arr[right]>0){
            right--;
        }
        else if(arr[left]>0 && arr[right]<0){
            swap(arr[left],arr[right]);
            left++; right--;
        }
        else{
            left++; right--;
        }
    }
}

void printArray(int arr[],int size){
    for(int i=0;i<size;++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int arr[] = { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);
    // shiftNegatives_A(arr, n);
    // shiftNegatives_B(arr, n);
    printArray(arr, n);
    return 0;
}