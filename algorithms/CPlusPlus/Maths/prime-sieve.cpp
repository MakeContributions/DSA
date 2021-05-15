//Sieve of Eratosthenes
//Print all prime numbers within given range.

#include<bits/stdc++.h>
using namespace std;
void PrimeSieve(int n) {
    vector <int> sieve(n + 1);              //Create a vector array of size n+1
    fill(sieve.begin(), sieve.end(), 1);    //Fill the array with 1s, which means all numbers are intially assumed to be prime.
    sieve[0] = 0;                           //Exception:Zero is not a Prime
    sieve[1] = 0;                           //Exception:One  is not a Prime
    for (int i = 2; i * i <= n; i++) { 
        if (sieve[i] == 1) {               //This condition will only be executed if the sieve[i] is prime, mark all the multiples of Prime Numbers as non-prime. 
            for (int j = i * i; j <= n; j += i) {
                sieve[j] = 0;              
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (sieve[i] == 1) {
            cout << i << " ";
        }
    }
    return;                               //Time complexity : O(n*log(log(n))), Auxiliary Space: O(1)
}
int main() {
    int n;
    cin >> n;
    PrimeSieve(n); //Call the function
    return 0;
}
