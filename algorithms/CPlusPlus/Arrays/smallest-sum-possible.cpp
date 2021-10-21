/* 
    Description
    Given an array X of positive integers, its elements are to be transformed by running the following operation on them as many times as required:

    if X[i] > X[j] then X[i] = X[i] - X[j]

    When no more transformations are possible, return its sum ("smallest possible sum").

    For instance, the successive transformation of the elements of input X = [6, 9, 21] is detailed below:

    X_1 = [6, 9, 12] # -> X_1[2] = X[2] - X[1] = 21 - 9
    X_2 = [6, 9, 6]  # -> X_2[2] = X_1[2] - X_1[0] = 12 - 6
    X_3 = [6, 3, 6]  # -> X_3[1] = X_2[1] - X_2[0] = 9 - 6
    X_4 = [6, 3, 3]  # -> X_4[2] = X_3[2] - X_3[1] = 6 - 3
    X_5 = [3, 3, 3]  # -> X_5[1] = X_4[0] - X_4[1] = 6 - 3
    The returning output is the sum of the final transformation (here 9).

    Example
    solution([6, 9, 21]) #-> 9
*/

/* 
    ~~~~~~~ NOTE ~~~~~~~~~
    There are performance tests consisted of very big numbers and arrays of size at least 30000. Please write an efficient algorithm to prevent timeout.
    Your IDE may not show timeout, but timeout can occur in standard coding competetions.
*/


#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;

unsigned long long solution(const vector<unsigned long long>& arr){
    unsigned long long prev_gcd = arr[0];
    for (auto i : arr){
        prev_gcd = gcd(i, prev_gcd);       // finding gcd of the array.
    }
    return arr.size()*prev_gcd;
}

int main() {
    const vector<unsigned long long> vec = {9, 6, 12};
    cout << solution(vec);
}

/*
    Testcases : 
    solution({1,21,55}) // --> 3
    solution({3,13,23,7,83}) // --> 5
    solution({4,16,24}) // --> 12
    solution({30,12}) // --> 12
    solution({60,12,96,48,60,24,72,36,72,72,48}) // --> 132 
    solution({71,71,71,71,71,71,71,71,71,71,71,71,71}) // --> 923
    solution({11,22}) // --> 22
    solution({9}) // --> 9
    solution({1}) // --> 1
    solution({9, 9}) // --> 18
*/
