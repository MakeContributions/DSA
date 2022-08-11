#include<stdio.h>
#include"./fib.h" // NOLINT(build/include)

int main(){
	memomizing_fib(); // this is to initialize the memomized table
	int n = 15;
	printf("%d\n", recur_fib(n)); // it becomes slow as n get larger for recur_fib
	for(int i = 0; i <= 35; ++i){
		printf("n = %d\t", i);
		printf(" %d", iter_fib(i));
		printf(" %d", memo_fib(i));
		printf(" %d", log_fib(i));
		printf(" %d", binet_fib(i));
		printf(" %d\n", iter_log_fib(i));
	}
	int sum = 0;
	int bound = 4000000;
	for(int i = 0; memo_fib(i) < bound; ++i)
		if(memo_fib(i)%2 == 0)
			sum += memo_fib(i);
	printf("The sum of even Fibonacci number below %d = %d", bound, sum);
	return 0;
}
