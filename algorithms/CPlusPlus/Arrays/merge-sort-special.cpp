//Merging two sorted arrays in C++ in special manners

//You're given two sorted arrays. You have to merge them in this manner that if there are some same elements in both of them the third merging array should have less number of same elements. For example:
//Arr1= 1 5 5 5 6 6 7 7
//Arr2= 2 5 5 6
//
//output= 1 2 5 5 6 7 7
//There are two 5's because in one array there are three 5's and in second array there are two 5's. So we should always take less number.

// Time Complexity: O(len_arr1 + len_arr2) (since we are iterating over all the elements of both arrays)
// Space Complexity: O(len_arr1 + len_arr2)
#include <bits/stdc++.h>

using namespace std;

vector<int> mergeSpecial(vector<int> &a, vector<int> &b)
{
    vector<int> final; // the final merged array
    int i = 0, j = 0;
    int lenA = a.size(), lenB = b.size();
    while (i < lenA && j < lenB)
    {
        if (a[i] == b[j]) // element is present in both and within the min limit
        {
            final.push_back(a[i]);
            i++;
            j++;
        }
        else if (a[i] < b[j])
        {
            if (final.size() == 0 || final[final.size() - 1] != a[i]) // this condition will be false if a has more number of an element than b hence dont add to final list
                final.push_back(a[i]);
            i++;
        }
        else
        {
            if (final.size() == 0 || final[final.size() - 1] != b[j])
                final.push_back(b[j]);
            j++;
        }
    }
    int lastElement = final[final.size() - 1]; // checking we don't push the last element more than it's minimum frequency in both array
    if (j < lenB) // swapping a and b if array b was big 
    {
        i = j;
        lenA = lenB;
        a = b;
    }
    while (i < lenA)
    {
        if (a[i] != lastElement)
            final.push_back(a[i]);
        i++;
    }
    return final;
}

int main()
{
    vector<int> a = {1, 5, 5, 5, 6, 6, 7, 7};
    vector<int> b = {2, 5, 5, 6};
    vector<int> output = mergeSpecial(a, b);
    for (int i : output)
        cout << i << " ";
    return 0;
}