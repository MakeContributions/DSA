#include <iostream>
using namespace std;
<<<<<<< HEAD
int
main ()
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
=======
int main() {
    int num, i=0,r,sum=0,s;
    //cout <<"enter a number to check it is Armstrong no. or not ";
    cin>>num; 
    s=num;
    while (i<num)
    {
        r=num%10;
        sum =sum+(r*r*r);
        num =num/10;
    }
    if(sum==s)
    cout <<"it is a Armstrong number ";
    else 
    cout <<"it is not a Armstrong number ";
    return 1;
>>>>>>> 463635d6858dc412e2bcaa4a2c7a19d95ab2677a
}