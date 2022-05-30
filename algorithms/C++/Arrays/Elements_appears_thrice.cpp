// elements with frequency = (3) in a given array
//time complexity : O(n) || space complexity : O(1)

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{ // main function begins here
    int size;
    cout << "Enter the size of the array : ";
    cin >> size;

    int *arr = new int[size];
    map<int, int> mp;

    for (int i = 0; i < size; i++)
    {
        cout << "Enter " << i << " th element of array : ";
        cin >> arr[i];
        mp[arr[i]]++; // this simply stores the frequency of each element in this array
    }

    map<int, int>::iterator it; // this is an iterator which is used to iterate all over the map

    int count = 0;

    for (it = mp.begin(); it != mp.end(); it++)
    {
        if ((*it).second == 3) // checks whether element frequency is 3 or not
        {
            count++; // just check how many elements are there which have frequency 3
            if (count == 1)
            {
                cout << "The elements whose frequency is 3 are: ";
            }
            cout << (*it).first << " "; // print the element which satisfy the above condition
        }
    }
    if (count == 0)
    {
        cout << "There is no elements in this array whose frequency is 3."; // special print if there is no such elements
    }

    cout << endl;
    return 0;
}