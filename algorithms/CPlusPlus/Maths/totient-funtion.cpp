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
int totient(int n) {
    vector<int>primefactors = getPrimeFactors(n);
    int numerator = 1, denominator = 1;
    for (auto p : primefactors) {
        numerator *= (p - 1);
        denominator *= p;
    }
    return (n * numerator) / denominator;
}
int main() {

    int n;
    cin >> n;
    cout << totient(n) << "\n";
    return 0;
}

//definition : Totient function provides number of positive integers that are less than the given number n and coprime with n.