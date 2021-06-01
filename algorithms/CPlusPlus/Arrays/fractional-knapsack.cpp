// Description : Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
// We can break items for maximizing the total value of knapsack/

// Algorithm Type: Divide & Conquer
// Time Complexity: O(n*log(n))
#include <bits/stdc++.h>
using namespace std;
class Item
{
public:
    int value, weight;

    // Constructor
    Item(int value, int weight)
    {
        this->value = value;
        this->weight = weight;
    }
};
bool comp(Item a, Item b)
{
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}

//Function to get the maximum total value in the knapsack.
double fractionalKnapsack(int W, Item arr[], int n)
{

    sort(arr, arr + n, comp);

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
    int W = 50;                                    //    Weight of knapsack
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}}; //    {Value-Weight}pairs

    int n = sizeof(arr) / sizeof(arr[0]); // size of item array

    // Function call
    cout << "Maximum value we can obtain = " << fractionalKnapsack(W, arr, n);
    return 0;
}
