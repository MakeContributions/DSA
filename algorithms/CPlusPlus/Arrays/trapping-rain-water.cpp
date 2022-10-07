/* Discription : Given an array of N non-negative integers arr[] representing an elevation map where the width of   each bar is 1, compute how much water it is able to trap after raining.
*/

#include <bits/stdc++.h>
using namespace std;

// Function to return the maximum water that can be stored
int maxWater_method_1(int arr[], int n)
{
    // To store the maximum water that can be stored
    int res = 0;

    // For every element of the array
    for (int i = 1; i < n - 1; i++)
    {

        // Find the maximum element on its left
        int left = arr[i];
        for (int j = 0; j < i; j++)
            left = max(left, arr[j]);

        // Find the maximum element on its right
        int right = arr[i];
        for (int j = i + 1; j < n; j++)
            right = max(right, arr[j]);

        // Update the maximum water
        res = res + (min(left, right) - arr[i]);
    }

    return res;
}

int maxWater_method_2(int arr[], int n)
{
    // left[i] contains height of tallest bar to the left of i'th bar including itself
    int left[n];

    // Right [i] contains height of tallest bar to the right of ith bar including itself
    int right[n];

    // Initialize result
    int water = 0;

    // Fill left array
    left[0] = arr[0];
    for (int i = 1; i < n; i++)
        left[i] = max(left[i - 1], arr[i]);

    // Fill right array
    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        right[i] = max(right[i + 1], arr[i]);

    // Calculate the accumulated water element by element consider the amount of water on i'th bar, the amount of water accumulated on this particular bar will be equal to min(left[i], right[i]) - arr[i].
    for (int i = 1; i < n - 1; i++)
    {
        int var = min(left[i - 1], right[i + 1]);
        if (var > arr[i])
        {
            water += var - arr[i];
        }
    }

    return water;
}

int maxWater_method_3(int height[], int n)
{
    // Stores the indices of the bars
    stack<int> st;

    // Stores the final result
    int ans = 0;

    // Loop through the each bar
    for (int i = 0; i < n; i++)
    {

        // Remove bars from the stack until the condition holds
        while ((!st.empty()) && (height[st.top()] < height[i]))
        {

            // Store the height of the top and pop it.
            int pop_height = height[st.top()];
            st.pop();

            // If the stack does not have any bars or the popped bar has no left boundary
            if (st.empty())
                break;

            // Get the distance between the left and right boundary of popped bar
            int distance = i - st.top() - 1;

            // Calculate the min. height
            int min_height = min(height[st.top()], height[i]) - pop_height;

            ans += distance * min_height;
        }

        // If the stack is either empty or height of the current bar is less than or equal to the top bar of stack
        st.push(i);
    }
    return ans;
}

int maxWater_method_4(int arr[], int n)
{
    // Indices to traverse the array
    int left = 0;
    int right = n - 1;

    // To store Left max and right max for two pointers left and right
    int l_max = 0;
    int r_max = 0;

    // To store the total amount of rain water trapped
    int result = 0;
    while (left <= right)
    {

        // We need check for minimum of left and right max for each element
        if (r_max <= l_max)
        {

            // Add the difference between current value and right max at index r
            result += max(0, r_max - arr[right]);

            // Update right max
            r_max = max(r_max, arr[right]);

            // Update right pointer
            right -= 1;
        }
        else
        {

            // Add the difference between
            // current value and left max at index l
            result += max(0, l_max - arr[left]);

            // Update left max
            l_max = max(l_max, arr[left]);

            // Update left pointer
            left += 1;
        }
    }
    return result;
}

int main()
{
    int n; // Take the size of the array as input from the user
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; ++i) 
		cin >> arr[i]; // Take the elements of the array as input from the user

    //this is brute force approach time complexity=O(n^2) || space complexity=O(1);
    cout << maxWater_method_1(arr, n) << endl; 

    //this is precalculation approach time complexity=O(n) || space complexity=O(n);
    cout << maxWater_method_2(arr, n) << endl;

    //this is using stack approach time complexity=O(n) || space complexity=O(n);
    cout << maxWater_method_3(arr, n) << endl;

    //this is two-pointer approach time complexity=O(n) || space complexity=O(1);
    cout << maxWater_method_4(arr, n) << endl;
    return 0;
}


//Example test case:
// input : 0 1 0 2 1 0 1 3 2 1 2 1
// output : 6