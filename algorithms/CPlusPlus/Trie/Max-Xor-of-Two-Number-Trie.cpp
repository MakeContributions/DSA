/**
 * 
one of the standard Brute force is O(n^2),but this is optimized version of this question
time complexity of inserting all element in Trie of array is O(31*n).
time complexity of finding Xor of each element in Trie of given array is O(31*n).
so the complexity  is O(31*n);
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define for0(i, n) for (int i = 0; i < n; i++)
#define vi vector<int>
#define pb push_back
#define sz(x) sizeof(x)
#define vec(n, x) vector<int> v(n, x)
const ll INF = 1e18;
const ll MOD = 1000000007;
#define hi        \
    ll tests;     \
    cin >> tests; \
    while (tests--)
#define all(x) x.begin(), x.end()
#define readv(vec)      \
    for (auto &x : vec) \
    {                   \
        cin >> x;       \
    }
#define PHI M_PI
#define graph                   \
    int V;                      \
    cin >> V;                   \
    vector<int> adj[V];         \
    int e;                      \
    for (int i = 0; i < e; i++) \
    {                           \
        int u, v;               \
        cin >> u >> v;          \
        adj[u].push_back(v);    \
        adj[v].push_back(u);    \
    }
#define printv(vec)       \
    for (auto x : vec)    \
    {                     \
        cout << x << ' '; \
    }                     \
    cout << endl;
#define sortasc(vec) sort(all(vec));
#define sortdes(vec) sort(vec.rbegin(), vec.rend());
#define setpre(x) cout << fixed << setprecision(10) << x << endl
#define kick cout << 'C' << 'a' << 's' << 'e' << ' ' << '#' << k << ':' << ' '
struct node
{
    node *left;
    node *right;
};
class Trie
{
public:
    node *root;
    Trie()
    {
        root = new node();
    }

    void insert(int x)
    {
        node *temp = root;
        int idx = 31;
        while (idx >= 0)
        {
            int mask = (1 << idx);
            if (x & mask)
            {
                // cout<<idx<<" ";
                if (temp->right == NULL)
                {
                    temp->right = new node();
                }
                temp = temp->right;
            }
            else
            {
                if (temp->left == NULL)
                {
                    temp->left = new node();
                }
                temp = temp->left;
            }
            idx--;
        }
    }
    int query(int x)
    {
        node *temp = root;
        int idx = 31;
        int sol = 0;
        while (idx >= 0)
        {
            int mask = (1 << idx);
            if ((mask & x))
            {
                // cout<<"jo";
                if (temp->right == NULL)
                {
                    temp = temp->left;
                }
                else
                {
                    sol |= mask;
                    temp = temp->right;
                }
            }
            else
            {
                if (temp->left == NULL)
                {
                    sol |= mask;
                    temp = temp->right;
                }
                else
                {
                    temp = temp->left;
                }
            }
            idx--;
        }
        return sol;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    Trie *t = new Trie();
    for (auto &i : nums)
    {
        cin>>i;
        t->insert(i);
    }
    int mx = 0;
    // cout<<res;
    for (auto i : nums)
    {
        int mask = INT_MAX;
        int req = mask ^ i;
        int res = t->query(req);
        // cout<<res<<" ";
        mx = max(mx, res ^ i);
    }
    cout << mx;
}
/**
sample input 
a = [1,2,3]
output 
3 (i.e. (2^1))
*/