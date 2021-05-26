//Description : Merge Sort Algorithm
#include<bits/stdc++.h>
using namespace std;

void merging(int arr[], int l, int h, int m) {
    int N1 = m - l + 1;                 //Left Array Size     
    int N2 = h - m;                     //Right Array Size
    int left[N1];                         
    int right[N2];
    for (int i = 0; i < N1; i++) {
        left[i] = arr[l + i];          //Copy elements to left array
    }
    for (int j = 0; j < N2; j++) {
        right[j] = arr[m + 1 + j];    //Copy elements to right array
    }
    int i = 0;
    int j = 0;
    int k = l;
    while (i < N1 && j < N2) {       //Inserting back the elements from left and right array
        if (left[i] <= right[j]) {   //If left element is smaller than the right one then we push 
            arr[k++] = left[i++];    //left element to our main array(arr)   
        } else {
            arr[k++] = right[j++];   //else we push right element to the main array
        }
    }
    for (; i < N1; i++) {            //These loop executes only when there is difference in size of
        arr[k++] = left[i];          //left and right array
    }
    for (; j < N2; j++) {
        arr[k++] = right[j];
    }
    return;
}

void merge_sort(int arr[], int l, int h) {
    if (l < h) {
        int mid = (l + ((h - l) / 2));
        merge_sort(arr, l, mid);           //Recursively calling for elements before mid(including mid)
        merge_sort(arr, mid + 1, h);       //Recursively calling for elements after mid
        merging(arr, l, h, mid);           //Merging the two arrays
    }
    return;
}
int main() {
    int arr[] = { 1,0,13,7,6,2,16 };
    cout << "Array Before Sorting" << endl;
    for (int i = 0; i < 7; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    merge_sort(arr, 0, 6);
    cout << "Array After Sorting" << endl;
    for (int i = 0; i < 7; i++) {
        cout << arr[i] << " ";
    }
    return 0;
   //Ex :Input : arr= { 1,0,13,7,6,2,16 };
   //    Output  
   //    Array Before Sorting 
   //    1 0 13 7 6 2 16
   //    Array After Sorting
   //    0 1 2 6 7 13 16
   //Time Complexity :O(nlogn)
   //Auxiliary Space :O(n)
   //where n is the array size
}
