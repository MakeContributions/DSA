#include <iostream>
using namespace std;

// Variable declaration
extern int a,b;
extern int c;
extern float f;

int main(){
	 //Variable definition
	 int a,b;
	 int c;
	 float f;
	 
	 //actual initialization
	 a=10;
	 b=20;
	 c= a + b;
	 
	 cout << c << endl ;
	 
	 f=70.0/3.0;
	 cout << f << endl;
	 
	 return 0;
}
