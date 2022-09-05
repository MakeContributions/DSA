#include <stdio.h>
int fibo(int);   //function prototyped

int main() {
   int n, j=0, i;
   printf("Enter how many terms you want for fibonacci series: ");  
   scanf("%d", &n);    //Getting the nth term
   printf("The fibonacci series upto '%d' term is: ", n);
   for (i = 1; i <= n; i++){        //Starting from 1 to less than equals to n, since we have 0 as our first number always upto the last term.
      printf("%d ", fibo(j));    //calculating and printing all the values for fibonacci.
      j++;     //incrementing j to get the next term.
   }
   printf("\n");
   return 0;
}

int fibo(int x){
   if(x == 0 || x == 1){  //base cases
      return x;
   }
   return fibo(x-1)+fibo(x-2);    //Recursive formula for printing the series
}

//Time Complexity of this program :-  (Golden Ratio)^n  i.e., (1.6180)^n  [Here n is the no. of terms]
