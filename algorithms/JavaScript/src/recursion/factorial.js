// algorithm to calculate factorial of positive integer n
// Time complexity: O(n)

function factorial(n) {
  // base case: we reach 0, return 1
  if (n === 0) return 1;
  // until we reach 0 we keep multiplying n by the factorial of n - 1
  return n * factorial(n - 1);
}

console.log(factorial(5));
// output: 120
