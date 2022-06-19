/**
 * Computes the nth term of fibonacci sequence using memoization technique
 * @param {*} n - index term you want to get from the sequence
 * @param {*} cache - Memoize object that stores the previously calculated fib term
 * @returns {number} nth term
 */
const fib = (n, cache = {}) => {
    if (cache[n]) return cache[n];
    if (n <= 2) return 1;

    cache[n] = fib(n-1, cache) + fib(n-2, cache);
    return cache[n]
};
console.log(fib(12));
// Output: 144