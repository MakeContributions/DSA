
#ifndef ALGORITHMS_C_MATHS_FIBONACCI_NUMBER_SRC_FIB_H_
#define ALGORITHMS_C_MATHS_FIBONACCI_NUMBER_SRC_FIB_H_

/**
 * fib(n) takes nonnegative number n
 * return n-th term fibonacci number.
 * The prefix highlights its algorithm used
 */

int recur_fib(int n);
int iter_fib(int n);

#define MAXSIZE 30
int memomized_fib[MAXSIZE];
void memomizing_fib(); // it should be called before using  the function memo_fib()

int memo_fib(int n);
int iter_log_fib(int n);
int log_fib(int n);
int binet_fib(int n);

#endif  // ALGORITHMS_C_MATHS_FIBONACCI_NUMBER_SRC_FIB_H_"
