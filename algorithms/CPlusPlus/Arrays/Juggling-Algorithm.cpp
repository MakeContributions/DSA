/* In this method, divide the array into M sets, where M = GCD (n, k), and then rotate the elements in each set.
From the number of elements ( n ) of the array and number of rotations ( k ) to be made to the array, the GCD(n, k) number of blocks are made.
Then in each block, shifting will take place to the corresponding elements in the block.
 After all the elements in all the blocks are shifted, the array will be rotated for the given number of times.
Example: If we want to rotate the array Arr : {10, 20, 30, 40, 50, 60} by 2 positions :
 M = GCD(60, 20) = 20
Initial Array : 10  20  30  40  50  60  
First Set Moves : 50  20  10  40  30  60
Second Set Moves : 50   60  10  20  30  40 
Time complexity : O(N) 
Auxiliary Space : O(1)
 */


#include <bits/stdc++.h>
using namespace std;
 int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
void ArrayRotate(int A[], int n, int k) {
    int d = -1, i, temp, j;
    for (i = 0; i < gcd(n, k); i++) {
        j = i;
        temp = A[i];
        while (1) {
            d = (j + k) % n;
            if (d == i) break;
            A[j] = A[d];
            j = d;
        }
        A[j] = temp;
    }
}
void displayArray(int A[], int n) {
    int i;
    for (i = 0; i < n; i++) 
    cout<<A[i];
    cout<<" ";
}
int main() {
    int n = 9, i, k = 3;
    
    cout<<"The size of the Array: "<< n<<endl;
    int A[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout<<"The Array elements";
    for (i = 0; i < n; i++) 
    cout<<A[i]<<" ";
    cout<<"\nThe value of k: "<<k<<endl;
    
    cout<<"Original array: ";
    displayArray(A, n);
    ArrayRotate(A, n, k);
    cout<<"\nArray after rotation: ";
    displayArray(A, n);
    return 0;
}