// Algorithm to insert a new element in an array representation of a max heap

#include <bits/stdc++.h>

using namespace std;


void insert(int N, int* A, int X){

    // insert new element at the first empty leaf of the max heap
    // maintaining the condition of complete binary tree
    A[N] = X;

    int j = N, temp;

    // for node with index 'j'
    // left child is (2*j + 1)
    // right child is (2*j + 2)

    // while the inserted element is greater than its parent node
    // OR we reach the root node of the max heap
    // keep pushing the element up the binary tree
    while(A[(j-1)/2] < A[j] || j!=0){

        // switch the inserted element with its parent node
        temp = A[j];
        A[j] = A[(j-1)/2];
        A[(j-1)/2] = temp;

        // the new index of the inserted element
        // is the index of its old parent element
        j = (j-1)/2;
    }

    // new element is inserted at the leaf
    // and pushed up till the heap becomes a max heap
}


int main(){

    int n, arr[n+1], x;

    // input number of elements in the max heap
    cin>>n;

    // input max heap with 'n' elements represented as an array
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    // input the new element to be inserted in the max heap
    cin>>x;

    insert(n, arr, x);
    // new element is successfully added to the max heap

    for(int i=0; i<=n; i++){
        // output the representation of elements of the new max heap as an array
        cout<<arr[i]<<" ";
    }

    return 0;
}

/*
__Test case__
Input:
    n = 7
    arr = 50 30 20 15 10 8 16
    x = 60

Output:
    arr = 60 50 20 30 10 8 16 15
*/