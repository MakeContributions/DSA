#include<iostream>
using namespace std;

/*
The idea is to half the power on every iteration
Computes the power in log(n) operations

On every iteration:
Square the base, half the power

Special case - if power is odd:
Multiply the ans with a
Because the ODD-NUMBER % 2 == 1

Note: There will always be one iteration where power is odd
*/

long binpow(long a, long b){
	long ans=1;
	// while b is greater than zero, we continue the binary exponentiation
	while(b>0){
		// if b is odd, multiply result with base 
		if(b&1)
			ans *= a;
		// square the base
		a *= a;
		// half the power
		b /= 2;
	}
	return ans;
}

// source: @angshudas
long binpow_rec(long a, long b){
	// a^0 = 1 [for any a]
	if(b==0)
		return 1;
	// recursive call for a^(b/2)
	long ans = binpow_rec(a, b/2);
	// square the result
	ans *= ans;
	// if b is odd, times by a
	// to cover for 
	if(b&1)
		ans *= a;
	
	return ans;
}

int main(){
	long base, power;
	cout<<"Enter the base and power: "<<endl;
	cin>>base>>power;
	cout<<base<<" ^ "<<power<<" = "<<binpow(base, power)<<endl;
	return 0;
}
