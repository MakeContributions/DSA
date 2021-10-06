// This program is used to calculate palindrome number in C
// a palindrome number is a number which is same on reversing that number

#include <stdio.h>		//header
int main ()				//main function
{
  int num, rev = 0, r, s;	//define variables
  printf (" enter the number: ");
  scanf ("%d", &num);		// taking input
  s = num;			//assigning num to s
  while (s > 0)
    {				// loop starts
      r = s % 10;
      rev = rev * 10 + r;	// calculating reverse
      s = s / 10;
    }
  if (num == rev)
    {				// checking if condition
      printf ("Palindrome");	//printing if number is palindrome
    }
  else
    {
      printf ("Non-palindrome");	//printing if number is not palindrome
    }
  return 0;			//returning main function
}

//      sample input    ||      sample output
//          121         ||      Palindrome
//          438         ||      Non-palindrome
//          787         ||      Palindrome
//          975         ||      Non-Palindrome

// This program is having time complexity of O(N).
