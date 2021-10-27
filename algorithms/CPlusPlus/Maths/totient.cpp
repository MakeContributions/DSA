/*
Program Description:
Euler's totient function (also called the Phi function) counts the number of positive integers less than n that 
are coprime to n. That is, totient(n) is the number of m∈N such that 1≤m<n and gcd(m,n)=1.
You are given an integer N and are supposed to find the value of Euler toient function for N.

Constraints:
1 <= N <= 10^9

Approach:
totient(N) = N*(1 - 1/p1)*(1 - 1/p2)...*(1 - 1/pn).
where, p1,p2...pn are prime factors of n.
So, we can write the above function as,
totient(N) = N*[(p1-1)(p2-1)...(pn-1)/(p1*p2*p3...*pn)]
1)Calculate all the primefactors of N.
2)Calculate the numerator and denominator i.e N*(p1-1)(p2-1)...(pn-1) and (p1*p2*p3...*pn)
3)Divide numerator by denominator.

Time Complexity: O(NloglogN)
*/

#include<iostream>
#include<vector>
using namespace std;


vector<int>getPrimeFactors(int n) {
    vector<int>factors;
    if (n % 2 == 0) {
        factors.push_back(2);
        while (n % 2 == 0)n /= 2;
    }
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            factors.push_back(i);
            while (n % i == 0)n /= i;
        }
    }
    if (n > 1)factors.push_back(n);
    return factors;
}
long long totient(int n) {
    vector<int>primefactors = getPrimeFactors(n);
    long long numerator = 1, denominator = 1;
    for (auto p : primefactors) {
        numerator *= (long long)(p - 1);
        denominator *= (long long)p;
    }
    return ((long long)n * numerator) / denominator;
}
int main() {

    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Number of coprime integers are: " << totient(n) << "\n";
    return 0;
}
