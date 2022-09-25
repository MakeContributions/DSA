// algorithm to calculate factorial of positive integer n
// Time complexity: O(n)

function factorial(n) {
  // Error handling
  // if n is negative or not an integer return string with error message
  if (n < 0) return 'Only positive numbers allowed';
  if (!Number.isInteger(n)) return 'Only integers allowed';
  // if n is a positive integer
  // base case: we reach 0, return 1
  if (n === 0) return 1;
  // until we reach 0 we keep multiplying n by the factorial of n - 1
  return n * factorial(n - 1);
}

console.log(factorial(5));
// output: 120
