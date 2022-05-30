#include<bits/stdc++.h>
using namespace std;
//Function to check whether a number is prime or not.
bool isPrime(int num) {
    if (num == 1)
        return false;
    if (num == 2 || num == 3)
        return true;
    if (num % 2 == 0 || num % 3 == 0)
        return false; //Multiples of prime numbers are not prime
    for (int i = 6; i * i <= num; i += 5) {
        //If number is a composite  number then it must have one multiple greater(or equal) 
        //to sqrt(num) and one multiple less(or equal) to sqrt(num).
        //If the num doesn't satisfy the above conditions then the number is said to be a prime number
        //Also prime number appear in the form of 6n-1 and 6n+1 where n is a natural number
        if ((num % (i - 1) == 0) || (num % (i + 1) == 0))
            return false;
    }
    return true;
}
int main() {
    int num;
    cin >> num; //Taking input from user
    string result = isPrime(num) ? "Prime" : "Not Prime"; //Evaluating string based on result from isPrime function
    cout << result; //Printing result
    //Ex : num = 11 , result will print "Prime"
    //Time Complexity :O(sqrt(num))
    return 0;
}
