// It is a prime number program in c language.
// it is used to check whether a given number is prime or not

#include <iostream>	//header

using namespace std;
int main() { //main function
  int num, i, a = 0; //define variable
  cin >> num; //taking input from user

  for (i = 2; i <= num / 2; i++) { //for loop started
    if (num % i == 0) { //if condition
      a++;
    }
  }
  if (num < 2) {
    a++;
  }
  if (a == 0) {
    cout << "Prime"; // printing if the number is prime
  } else {
    cout << "Non-Prime"; // printing if the number is non-prime
  }
  return 0; // returning from main function
}

//	sample input   ||	sample output
//	      1        ||        Nom-Prime
//	      2        ||          Prime
//            3        ||          Prime
//	      4        ||        Non-Prime
//	      5        || 	   Prime

// time complexity of this program is O(n).