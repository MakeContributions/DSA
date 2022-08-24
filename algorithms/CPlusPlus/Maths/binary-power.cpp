#include<bits/stdc++.h>
using namespace std;

// using recursion to find exponentiation
long power(long base ,long expo){
  // if exponent is equal to 0 then return 1
  // as a^0 = 1 for all numbers
  if (expo==0) 
    return 1;
  
  // storing the value of a^(x/2) to minimize recursive call
  long ans= power(base , expo/2);

  if (expo%2) return base*ans*ans;
  else return ans*ans;
}


int main()
{
  int a,n; cin>>a>>n;
  cout << power(a,n);
  return 0;
}
