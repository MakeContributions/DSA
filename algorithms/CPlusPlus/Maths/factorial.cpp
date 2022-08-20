/*
Description: A program to calculate factorial of a number.
A factorial of number 4 is calculated as:
4 X 3 X 2 X 1 = 24

Approach: Calculating factorial using for loop.
Declaring the f variable to 1 (not initialising it to zero because any number multiplied by 0 will be 0)
Multiplying the f variable to 1,2,3...n and storing it in the f variable.
The same factorial can be calculated using while loop, recursion.

Time Complexity: O(number)
*/

#include <iostream>
using namespace std;

//function starts
long factorial (long n){
  long f=1;
  for(long i=1;i<=n;i++){
    f=f*i;
  }
  return f;
}

//main starts
int main() {
  cout << "Enter a number: \n";
  long n;
  cin>>n;
  cout<<"factorial is: "<<factorial(n);
  return 0;
}

/*
Input: 
Enter a number: 
3

Output:
factorial is: 6
*/
