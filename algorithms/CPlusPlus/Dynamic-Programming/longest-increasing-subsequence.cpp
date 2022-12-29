/* ---problem Defintation---
 *
 * find the length of the longest subsequence of a given sequence
 * such that all elements of the subsequence are sorted in increasing order
 *
 * ---approche---
 * this problem has a lot of similarities with the 0/1 knapsack problem
 * that we can pick an element that make the sequence in increasing order or leave it
 * So we need to save our prviouse choice to help us predict our future
 *
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3; // max length of the array given

int dp[MAX][MAX]; // dp arrary to memeraize our choices

int length; // length of the array given
vector<int> given; // the given array

int lis(int idx,int prv_idx){
    // base case if the idx out of bounds
    if (idx >= length)
        return 0;

    // insted of dealing with (dp[idx][prv_idx]) we take a reverence from it for short
    auto &ret = dp[idx][prv_idx];
    // we know in binary representation (-1) all of it's bits is (1)
    // and this (~) is a bitwise not in c++ whice convert each bit one to zero and vice versa
    // so if we have calculated this answer we don't need to recalculate it again so we return it
    if (~ret)
        return ret;

    int choice1 = lis(idx+1,prv_idx); // leave
    int choice2 = 0;

    // if it's the first element or it can be in the sequence we take it
    if (prv_idx == length || given[idx] > given[prv_idx])
        choice2 = 1 + lis(idx+1,idx); // take


    return ret = max(choice1,choice2);
}

int main() {

    cin >> length;
    given.resize(length);
    for (int i = 0; i < length; i++)
        cin >> given[i];
    // initialize dp table with -1
    memset(dp,-1, sizeof(dp));
    // make prv_idx == length to indcaite this is our first element in the sequence
    cout << lis(0,length);
}

/*
 * ---complexity analysis---
 *  time:  O(n^2)
 *  memeory:  O(n^2)
 *
 *
 *  sample
 *  input:
 *  5
 *  2 1 5 3 4
 *
 *  output: 3
*/