#include <bits/stdc++.h>
using namespace std;
void KthBit(int n, int k)
{
    if(n&(1<<(k-1))!=0)
    {
        cout<<"Yes"<<endl;
    }
    else
    cout<<"No"<<endl;
}
int main()
{
    int n, k;
    cin >> n >> k;
    KthBit(n, k);
    return 0;
}