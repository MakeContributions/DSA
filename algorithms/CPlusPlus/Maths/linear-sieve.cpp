//Linear Sieve
//Finding primes in linear time

//Every composite q must have atleast 1 prime factor
//Let the smallest prime factor be p
//We can say q = p*(i)

//When we loop for every i, all primes not exceeding i is already stored in primes
//We can pick out each composite exactly once by looping and breaking out when the element divides i

#include<bits/stdc++.h>
using namespace std;

vector<int> primes;
bool check[INT_MAX];


void LinearSieve(int n) {
    fill(check, check+n, false);    
    for(int i=2;i<n;i++){
        if(!check[i]) primes.push_back(i);
        for(int j=0;j<primes.size() && i*primes[j] < n;j++){ //Executed only once for each composite
            check[i*primes[j]] = true;
            if(i%primes[j]==0) break; //Breaks when p divides i
        }
    }                             
}
int main() {
    int n;
    cin >> n;
    LinearSieve(n); //Call the function
    return 0;     //Time complexity : O(n*log(log(n))), Auxiliary Space: O(1)
    //Example : n=10 , Output: 2 3 5 7   
}