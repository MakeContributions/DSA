#include <iostream>
using namespace std;
int main ()
{
  int a = 0, t, n, s, r, p, i, sum = 0;
  cin >> n;
  t = n;
  while (t > 0)
    {
      t /= 10;
      a++;
    }
  s = n;
  while (s > 0)
    {
      r = s % 10;
      p = r;
      for (i = 1; i < a; i++)
    {
      p *= r;
    }
      sum += p;
      s /= 10;
    }
  if (sum == n)
    cout << n << " is an armstrong number.";
  else
    cout << n << " is not an armstrong number.";
  return 0;
}
