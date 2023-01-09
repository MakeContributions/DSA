/* Code contributed by Devang Shah to MakeContributions/DSA GitHub repository

Below CPlusPlus code displays all possible solutions for a N-Queens problem.
Problem: Given a N x N chess board, arrange N queens in a way such that no two queens attack each other. Two queens are attacking each other if they are in same row, same column or diagonal
Input: N
Output: All solutions ( in grid format {Q - Queen, * - empty cell} ) of the N-queens problem
Time Complexity: O(N!)
*/

#include <iostream>
using namespace std;

int a[30];

int place(int pos)
{
    int i;
    for (i = 1; i < pos; i++)
    {
        if ((a[i] == a[pos]) || ((abs(a[i] - a[pos]) == abs(i - pos))))
            return 0;
    }
    return 1;
}

void print_sol(int n)
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (a[i] == j)
                cout << "Q\t";
            else
                cout << "*\t";
        }
        cout << "\n";
    }
}

void queen(int n)
{
    int k = 1;
    a[k] = 0;
    int count = 0;
    while (k != 0)
    {
        a[k] = a[k] + 1;
        while ((a[k] <= n) && !place(k))
            a[k]++;
        if (a[k] <= n)
        {
            if (k == n)
            {
                count++;
                cout << "Solution #" << count << "\n";
                print_sol(n);
            }
            else
            {
                k++;
                a[k] = 0;
            }
        }
        else
            k--;
    }
    cout << "\nTotal solutions=" << count;
}

int main()
{
    unsigned int n;
    cin >> n;
    if (n < 15)
        queen(n);
    else
        cout << "Invalid input. Program crashed";
    return 0;
}
