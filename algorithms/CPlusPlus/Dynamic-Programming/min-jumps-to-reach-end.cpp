/**
 * Problem : Given an array arr[] where each element represents the max       number of steps that can be made forward from that index. The task is to find the minimum number of jumps to reach the end of the array starting from index 0. If the end isn’t reachable, return -1.
 *
 *
 * Example :
 *  Input: arr[] = {1, 3, 5, 8, 9, 2}
    Output: 3 (1-> 3 -> 9 -> 2)
    Explanation: Jump from 1st element to 2nd element as there is only 1 step.
    Now there are three options 5, 8 or 9.
 *
 * Time Complexity : O(n^2)
 * Auxilary Space : O(n)
 * where n is the size of input array.
 */

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int minJumps(vector<int> &arr, int n)
{
    // jumps[n-1] will hold the result
    int *jumps = new int[n];
    int i, j;

    if (n == 0 || arr[0] == 0)
        return INT_MAX;

    jumps[0] = 0;

    // Find the minimum number of jumps to reach arr[i]
    // from arr[0], and assign this value to jumps[i]
    for (i = 1; i < n; i++)
    {
        jumps[i] = INT_MAX;
        for (j = 0; j < i; j++)
        {
            if (i <= j + arr[j] && jumps[j] != INT_MAX)
            {
                jumps[i] = min(jumps[i], jumps[j] + 1);
                break;
            }
        }
    }
    return jumps[n - 1];
}

int main()
{
    int n;
    cout << "Enter size of array : ";
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter " << i + 1 << " Element : ";
        cin >> arr[i];
    }
    cout << "Minimum number of jumps to reach end is " << minJumps(arr, n);
    return 0;
}

// arr[] = { 1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9 };
// Minimum number of jumps to reach end is 3 (1 -> 3 -> 9 -> 9).