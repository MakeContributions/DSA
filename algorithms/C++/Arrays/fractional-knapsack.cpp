// Description : Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
// We can break items for maximizing the total value of knapsack/

// Algorithm Type: Divide & Conquer
// Time Complexity: O(n*log(n))
#include <bits/stdc++.h>
using namespace std;
struct Item
{
    int value, weight;
};
bool comp(Item a, Item b)
{
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}

//Function to get the maximum total value in the knapsack.
double fractionalKnapsack(int W, vector<Item> &arr, int n)
{

    sort(arr.begin(), arr.end(), comp);

    int curWeight = 0;
    double finalvalue = 0.0;

    for (int i = 0; i < n; i++)
    {

        if (curWeight + arr[i].weight <= W)
        {
            curWeight += arr[i].weight;
            finalvalue += arr[i].value;
        }

        else
        {
            int remain = W - curWeight;
            finalvalue += (arr[i].value / (double)arr[i].weight) * (double)remain;
            break;
        }
    }

    return finalvalue;
}
int main()
{
    int W; //    Weight of knapsack
    cout << "Enter the weight(W) of the knapsack" << endl;
    cin >> W;
    int n;
    cout << "Enter the total number(n) of {Value-Weight}pairs" << endl;
    cin >> n;
    vector<Item> arr(n);

    for (int i = 0; i < n; i++)
    {

        cout << "Enter value for pair " << i + 1 << endl;
        cin >> arr[i].value;
        cout << "Enter weight for pair " << i + 1 << endl;
        cin >> arr[i].weight;
    }

    // Function call
    cout << "Maximum value we can obtain = " << fractionalKnapsack(W, arr, n);
    return 0;
}
