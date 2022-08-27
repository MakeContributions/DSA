using System.Collections.Generic;

namespace Algorithms.Maths {
    public class fibonacci_series {
        // Fibonacci Series using Recursion and Memoization
        public static int[] FibonacciSeries(int n) {
            var memo = new Dictionary<int, int>();
            var result = new int[n];
            for (int i = 0; i < n; i++) {
                result[i] = Fibonacci(i, memo);
            }

            return result;
        }

        private static int Fibonacci(int n, Dictionary<int, int> memo) {
            if (n == 0 || n == 1) {
                return n;
            }

            if (memo.ContainsKey(n)) {
                return memo[n];
            }

            memo[n] = Fibonacci(n - 1, memo) + Fibonacci(n - 2, memo);
            return memo[n];
        }
    }

}