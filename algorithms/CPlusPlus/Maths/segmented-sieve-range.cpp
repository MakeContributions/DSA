/*
Problem: finding all prime numbers in a range [L,R], where R <= 1e12 and (R-L+1) <= 1e7.
*/

#include <bits/stdc++.h>
using namespace std;

//function to find prime numbers between L and R
void segmented_sieve_range(long int L, long int R){

    // generate all primes up to sqrt(R)
    long int e = sqrt(R);

    // vector to store whether ith element is visited or not
    vector<bool> check(e + 1, false);

    //stores all primes till sqrt(R)
    vector<long int> primes;
    
    for (long int i = 2; i <= e; ++i) {
        if (!check[i]) {

            //i is a prime number
            primes.push_back(i);
            for (long int j = i*i; j <= e; j += i){
                check[j] = true;
            }
        }
    }

    vector<bool> isPrime(R - L + 1, true);

    //edge case
    if(L == 1){
        isPrime[0] = false;
    }

    for (long int i = 0; i < primes.size() ; i++){

        //current Prime
        long int cur = primes[i];
        long int product = cur*cur;

        for(long int start = max(product, (L + cur -1)/product); start <= R ; start += cur){
            isPrime[start - L] = false;
        }
    }


    //Printing all primes in the range L to R 
    for(long int i = 0; i < isPrime.size(); i++){
        if(isPrime[i]){
            //current index element is a prime number
            cout<< L + i << " ";
        }
    } 

    cout << endl;
}

//main starts
int main()
{
    long int L, R;
    cin >> L >> R;

    segmented_sieve_range(L, R);

    return 0;
}

/*
Time Complexity - O((R−L+1)log(R) + √R)

Input: 
30 50
Output:
31 37 41 43 47

Input: 
10 20
Output: 
11 13 17 19
*/