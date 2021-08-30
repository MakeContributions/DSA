// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <iostream>
using namespace std;


int minSwap(int *arr, int n, int k) {
    //good elements are the elements less than k
    int good=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<=k)
        {
            good++;
        }
    }
    //bad elements are those who are greater than k
    int bad = 0;
    for (int i = 0; i < good; ++i)
        if (arr[i] > k)
            ++bad;
      
    // Initialize answer with 'bad' value of
    // current window
    int ans = bad;
    for (int i = 0, j = good; j < n; ++i, ++j) {
          
        // Decrement count of previous window
        if (arr[i] > k)
            --bad;
          
        // Increment count of current window
        if (arr[j] > k)
            ++bad;
          
        // Update ans if count of 'bad'
        // is less in current window
        ans = min(ans, bad);
    }
    return ans;
    
}

int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        cout << minSwap(arr, n, k) << "\n";
    }
	return 0;
}



