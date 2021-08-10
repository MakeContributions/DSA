/*******************
 * August 09, 2021
 * Leo Nugraha
 * Factorial problems via recursive or non-recursive methods
 * Run: g++ -std=c++11 factorial.cpp -o factorial
 ******************/
#include <iostream>

int FactorialNonRecursion(int number) {
  int result = 1;
  for (int i=1; i<number+1; ++i)
    result = result * i;
  return result;
}

int FactorialRecursion(int number) {
  if (number == 0 || number == 1) {
    return 1;
  }
  return number * FactorialRecursion(number-1);
}

int main(int argc, char *argv[]){

  int testNonRecursion = FactorialNonRecursion(5);
  std::cout << testNonRecursion << "\n";

  int testRecursion = FactorialRecursion(3);
  std::cout << testRecursion << "\n";

  return 0;
}
