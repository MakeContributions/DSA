#include<iostream>
#include<vector>
using namespace std;


vector<int>getPrimeFactors(int n) {
    vector<int>v;
    if (n % 2 == 0) {
        v.push_back(2);
        while (n % 2 == 0)n /= 2;
    }
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            v.push_back(i);
            while (n % i == 0)n /= i;
        }
    }
    if (n > 1)v.push_back(n);
    return v;
}
int totient(int n) {
    vector<int>pf = getPrimeFactors(n);
    int num = 1, den = 1;
    for (auto p : pf) {
        num *= (p - 1);
        den *= p;
    }
    return (n * num) / den;
}
int main() {

    int n;
    cin >> n;
    cout << totient(n) << "\n";
    return 0;
}

//definition : Totient function provides number of positive integers that less than the given number n and coprime with n.