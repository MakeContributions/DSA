#include <bits/stdc++.h>

#define int long long int
#define pb push_back
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,left_rotation_val;
    cin>>n>>left_rotation_val;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    left_rotation_val = left_rotation_val % n;
    //Doing this we can get the place from where the rotation starts.
    // 5 4
    // 1 2 3 4 5
    // 1 2 3 4 5 -> 2 3 4 5 1(1 rotation) -> 3 4 5 1 2(2 rotation) -> 4 5 1 2 3(3 rotation) -> 5 1 2 3 4(4 rotation)

    for(int i = left_rotation_val; i<n; i++){
        cout<<arr[i]<<" ";
    }

    for(int i = 0;i<left_rotation_val;i++){
        cout<<arr[i]<<" ";
    }
    
}