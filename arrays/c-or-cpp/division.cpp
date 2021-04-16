#include <iostream>
using namespace std;

int main() {
	int divisor, dividend,quotient,remainder;
	
	cout << "Enter dividend:" ;
	cin  >> dividend;
	
	cout << "Enter divisor:";
	cin >> divisor;
	
	quotient =dividend/divisor;
	remainder=dividend%divisor;
	
	cout << "Quotien =" <<quotient << endl;
	cout << "remainder=" <<remainder ;
	
	
	return 0;
}
