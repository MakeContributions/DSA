#include<iostream>				//header
using namespace std;
int main() {					//main function
	int num, i, a = 0;			//define variable
	cin >> num;					//taking input from user
	if(num == 2) {				//checking if condition for 2
		cout << "Prime";
	}
	else{						//begin else
		for(i = 2; i <= num/2; i++) { //for loop started
			if (num % i == 0){			//if condition
				a++;
			}
		}
	}
	if(a == 0){
		cout << "Prime";			// printing if the number is prime
	}
	else {
		cout << "Non-Prime";		// printing if the number is non-prime
	}
	return 0;						// returning from main function
}