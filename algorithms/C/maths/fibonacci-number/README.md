# Fibonacci Number
Fibonacci numbers form a Fibonacci sequence where given any number (excluding first 2 terms) is a sum of its two preceding numbers. Usually, the sequence is either start with 0 and 1 or 1 and 1. Below is a Fibonacci sequence starting from 0 and 1:

$$
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, \dots
$$

The problem is to calculate the n-th term Fibonacci number given two starting numbers.

## Prerequisites
- C compiler (or IDE)
- MAKE software (optional if you compile the source files manually)


## Instructions
- using makefile
  ```bash
   make # or mingw32-make
  ```
- compile using gcc
  ```
  cd <path>\fibonacci-number
  gcc .\src\main.c
  ```
## Note
The sequence can be described by a recurrent function as below:

$$
\begin{align*}
  F(0) &= 0 \\
  F(1) &= 1 \\
  F(n) &= F(n-1) + F(n-2)
\end{align*}
$$

- This provides a direct recursive implementation. The time complexity is $O(2^n)$. It can be improved through memomization.
- It can done iteratively using 2 more states variables. The time complexity is $O(n)$.
- There exists a clever logarithmic algorithm $O(\log{n})$ in computing n-th term Fibonacci number. The computations can be in form of matrix multiplication, then we can devise some form of Ancient Egyptian multiplication (i.e.: double and squaring) to improve the algorithm. [reference](https://rybczak.net/2015/11/01/calculation-of-fibonacci-numbers-in-logarithmic-number-of-steps/)
- Lastly, there also exist a formula to approximate n-term Fibonacci number $O(1)$. [reference](https://mathworld.wolfram.com/BinetsFibonacciNumberFormula.html)

The given implementations shall assume that the Fibonacci sequence is starting from 0 and 1. The reader may try to generalize it to certain extent as a practice.

## Test Cases & Output

1. Example output of calling function:
```
/* some code */
printf("%d", iter_fib(7));
printf("%d\n", memo_fib(7));
/* some code */
```

```
13
13
```
2. The code should yield the same output as other version.

3. The sum of even Fibonacci numbers below 4000000 should be 4613732. [Adapted from Project Euler.net](https://projecteuler.net/problem=2)
