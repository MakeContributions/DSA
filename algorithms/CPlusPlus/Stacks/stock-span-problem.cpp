/*The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to calculate span of stock’s price for all n days.*/
/*The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the current day is less than its price on the given day.*/
// C++ linear time solution for stock span problem

#include <bits/stdc++.h>
using namespace std;

// A stack based efficient method to calculate
// stock span values
void calculateSpan(const vector<int> price, const int priceSize,vector<int>& stockSpan)
{
    stack<int> spanStack;
    spanStack.push(0);

    // Span value of first element is always 1
    stockSpan.push_back(1);

    // Calculate span values for rest of the elements
    for (int priceIt = 1; priceIt < priceSize; priceIt++) {
        while (!spanStack.empty() && (price[spanStack.top()] < price[priceIt]) )
            spanStack.pop();

        // If stack becomes empty, then price[i] is
        // greater than all elements on left of it,
        // i.e., price[0], price[1], ..price[priceSize-1].  Else
        // price[priceSize] is greater than elements after
        // top of stack
        stockSpan.push_back( (spanStack.empty()) ? (priceIt + 1) : (priceIt - spanStack.top()) );

        spanStack.push(priceIt);
    }
}

//Print elements of array
void printArray(const vector<int>& arr,const int arrSize)
{
    for (int arrIt = 0; arrIt < arrSize; arrIt++)
        cout << arr[arrIt] << " ";
}

//Return the price vector from user input
vector<int> getPrice()
{
    vector<int> price;
    int priceSize;
    cin>>priceSize;
    for(int sizeIt = 0 ; sizeIt < priceSize ; sizeIt++)
     {
         int priceEntry;
         cin>>priceEntry;
         price.push_back(priceEntry);
     }
     return price;
}

// Driver program to test above function
int main()
{
    vector<int> price = getPrice();
    vector<int> stockSpan;
    calculateSpan(price, price.size(), stockSpan);

    printArray(stockSpan, price.size());

    return 0;
}
