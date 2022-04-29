// algorithm to generate first n numbers of fibonacci series
// Time complexity: O(n)

function fibonacci(n) {
  // Initialize array 'series'
  // with the first two numbers of the fibonacci series [0, 1]
  const series = [0, 1];
  for (let i = 3; i <= n; i++) {
    // starting from the third number, and stopping at number n
    const num1 = series[series.length - 1];
    // num1 is the last number of the series
    const num2 = series[series.length - 2];
    // num2 is the second-to-last number of the series
    const next = num1 + num2;
    // next number is the sum of the last two
    series.push(next);
    // add number to list
  }
  // return list
  return series;
}

console.log(fibonacci(10));
// output: [0, 1,  1,  2,  3, 5, 8, 13, 21, 34]
