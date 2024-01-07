#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 10;
int hshp[N];
int hshn[N];

int main()
{
    int q;
    int x;
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {

        cin >> a[i];
        if (a[i] < 0)
        {
            hshn[abs(a[i])]++;
        }
        else
        {
            hshp[a[i]]++;
        }
    }
    cin >> q;
    while (q--)

    {
        cin >> x;
        if (x < 0)
        {
            cout << hshn[abs(x)];
        }
        else
        {
            cout << hshp[x] << endl;
        }
    }
}

// hash array
