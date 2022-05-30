/*
Description: A program to segregate the array of 0s and 1s

Approach: Counting the number of 0s present in the array and 
saving it in variable z. For the first z indexes, putting 0 and 
for the remaining indexes putting 1.

Time complexity: O(n)
*/

#include <iostream>
#include <vector>
using namespace std;

void segregate0and1(vector<int> &v, int n)
{

  int z = 0;
  for (int i = 0; i < n; i++)
  {
    //counting the number of 0s and storing it the variable z
    if (v[i] == 0)
    {
      z++;
    }
  }
  //for z indexes, putting 0 in the vector
  //for remaining indexes putting 1 in the vector
  for (int j = 0; j < n; j++)
  {
    if (j < z)
    {
      v[j] = 0;
    }
    else
    {
      v[j] = 1;
    }
  }
}
int main()
{
  int n;
  cout << "Enter number of array elements\n";
  cin >> n;
  vector<int> v(n);
  cout << "Enter the array elements (only 0 and 1)\n";

  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
  }
  //calling the function
  segregate0and1(v, n);

  cout << "After segregating, the array is: \n";
  for (int j = 0; j < n; j++)
  {
    cout << v[j] << " ";
  }
}
