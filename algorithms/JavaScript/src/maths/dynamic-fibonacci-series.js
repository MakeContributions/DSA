// dynamic programming approach of fibonacci series 
// time complexity: O(n)

function dynamicFibonacci() {
  let cache = {};
  
  // here is the concept of closure in javaScript
  const fib = (n) => {
      // check if already calculated for n
      if (n in cache) {
          return cache[n];
      } else if (n < 2) { // base case
          return n;
      } else {
          // store result in cache
          cache[n] = fib(n - 1) + fib(n - 2);
          return cache[n];
      }
  }
 console.log(fib(10));
}
dynamicFibonacci();
// output: 55







