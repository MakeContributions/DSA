#include<bits/stdc++.h>
using namespace std;

/*
  RECURSIVE SOLUTION :-
    Space Complexity - O( log(N) )
    Time Complexity - O( log(N) )
*/
long power_recursion(long base ,long expo){
  // if exponent is equal to 0 then return 1
  // as a^0 = 1 for all numbers
  if (expo==0) 
    return 1;
  
  // storing the value of a^(x/2) to minimize recursive call
  long ans= power(base , expo/2);

  if (expo%2) return base*ans*ans;
  else return ans*ans;
}


/*
    ITERATIVE SOLUTION :-
      Space Complexity -> O(1)
      Time Complexity -> O( log(N) )
*/
long power_iterative( long base, long expo ){
  long res = 1; // inititalise result with 1
  while( expo!=0 ){ // run loop while exponent is not 0

    if( expo&1 ) // if least significant bit is 1 then update result 
      res = res * expo;
    
    base = base * base;
    expo>>=1;
    // update base and right shift exponent by 1

  }


  // after loop is exited return result
  return res;
}


int main()
{
  int a,n; cin>>a>>n;
  cout << power_recursion(a,n)<<endl;
  cout<< power_iterative(a,n)<<endl;
  return 0;
}
