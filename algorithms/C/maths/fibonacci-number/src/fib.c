#include"./fib.h" // NOLINT(build/include)
#include<math.h> // sqrt, pow are used in binet_fib

int recur_fib(int n){
	if(n == 0 || n == 1)
		return n;
	else
		return recur_fib(n-1) + recur_fib(n-2);
}
int iter_fib(int n){
	if(n == 0 || n == 1)
		return n;
	int prev2 = 0;
	int prev1 = 1;
	int res = prev1 + prev2;
	for(n = n - 2; n > 0; --n){
		prev2 = prev1;
		prev1 = res;
		res = prev1 + prev2;
	}
	return res;
}

// it should be called before using  the function memo_fib()
void memomizing_fib(){ 
	memomized_fib[0] = 0;
	memomized_fib[1] = 1;
	for(int i = 2; i < MAXSIZE; ++i)
		memomized_fib[i] = memomized_fib[i-1]+memomized_fib[i-2];
}

// return memomized value if exists, or else compute it as usual
int memo_fib(int n){ 
	if(n < MAXSIZE && n >= 0)
		return memomized_fib[n];
	else
		return memo_fib(n-1) + memo_fib(n-2);
}
/**
 *  fibonacci based linear transformation (linear algebra)
 *  reference: https://rybczak.net/2015/11/01/calculation-of-fibonacci-numbers-in-logarithmic-number-of-steps/
*/
int iter_log_fib(int n){
	int a = 0;
	int b = 1;
	int p = 0;
	int q = 1;
	while(n > 0){
		if(n%2 == 0){
			int prev_p = p;
			int prev_q = q;
			p = prev_p*prev_p + prev_q*prev_q;
			q = (2*prev_p + prev_q)*prev_q;
			n = n/2;
		}
		else{
			int prev_a = a;
			int prev_b = b;
			--n;
			a = p*prev_a + q*prev_b;
			b = q*prev_a + (p+q)*prev_b;
		}
	}
	return a;
}

/**
 *  fibonacci based linear transformation (linear algebra)
 * 	reference: https://rybczak.net/2015/11/01/calculation-of-fibonacci-numbers-in-logarithmic-number-of-steps/
*/
int log_fib_helper(int n, int a, int b, int p, int q){
	if(n == 0)
		return a;
	else if(n%2 == 0)
		return log_fib_helper(n/2, a, b, p*p+q*q, (2*p+q)*q);
	else
		return log_fib_helper(n-1, p*a + q*b, q*a+(p+q)*b, p, q);
}

int log_fib(int n){
	return log_fib_helper(n,0,1,0,1);
}
/**
 * Closed form formula
 * reference: https://mathworld.wolfram.com/BinetsFibonacciNumberFormula.html
*/
int binet_fib(int n){ 
	const double golden_ratio = (1+sqrt(5))/2;
	const double conjugate_golden_ratio = 1-golden_ratio;
	double res = (pow(golden_ratio,n) - pow(conjugate_golden_ratio, n))/sqrt(5);
	return round(res);
}
