// Program to find sum of all integer elements in an array
// Executable link: https://ide.geeksforgeeks.org/cey3HeTjYK

#include <iostream>

using namespace std;

int findSum(int A[], int n) {
    if (n <= 0)
        return 0;
    return (findSum(A, n-1) + A[n-1]);
}

int main() {
    int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "The sum of the array is " << findSum(A, 10);
    return 0;
}
