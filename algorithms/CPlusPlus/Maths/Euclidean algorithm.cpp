/*The Euclidean Algorithm is a technique for quickly finding the GCD of two integers.
GCD of two numbers is the largest number that divides both of them. A simple way to find GCD is to factorize both numbers and multiply common prime factors.

Basic Euclidean Algorithm for GCD: 
If we subtract a smaller number from a larger one (we reduce a larger number), GCD doesn’t change. So if we keep subtracting repeatedly the larger of two, we end up with GCD.
Now instead of subtraction, if we divide the smaller number, the algorithm stops when we find the remainder 0.
If A = 0 then GCD(A,B)=B, since the GCD(0,B)=B, and we can stop.  
If B = 0 then GCD(A,B)=A, since the GCD(A,0)=A, and we can stop.  
Write A in quotient remainder form (A = B⋅Q + R)
Find GCD(B,R) using the Euclidean Algorithm since GCD(A,B) = GCD(B,R)

Below is a recursive function to evaluate gcd using Euclid’s algorithm: */

#include <bits/stdc++.h>
using namespace std;
 
// Function to return gcd of a and b
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
 
// Driver Code
int main()
{
    int a,b;
  cout<<"Enter two numbers : ";
  cin>>a>>b>>endl;
   
      // Function call
    cout << "GCD(" << a << ", " << b << ") = " << gcd(a, b)
         << endl;
   =
    return 0;
}



/*
Sample input-output
GCD(10, 15) = 5
GCD(35, 10) = 5
GCD(31, 2) = 1
*/


//Time Complexity: O(Log min(a, b))
//Auxiliary Space: O(Log (min(a,b))
