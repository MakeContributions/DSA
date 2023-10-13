#include<iostream>
#include<vector>

/*
This code snippet utilizes memoization to reduce the time complexity
of calculating fibonacci upto n terms. Time complexity O(n).
*/

int fib(int n);

int main() {

	int n{ 8 };

	int r = fib(n);
	std::cout << r << "\n";

	return 0;
}

int fib(int n) {
	static std::vector<int> a_mem (n + 1);

	if (n <= 1) {
		a_mem[n] = n;
		return n;
	}
	else {
		if (a_mem[n - 1] == 0) {
			a_mem[n - 1] = fib(n - 1);
		}
		if (a_mem[n - 2] == 0){
			a_mem[n - 2] = fib(n - 2);
		}
		
		a_mem[n] = a_mem[n - 2] + a_mem[n - 1];
		return a_mem[n];
		
	}
}
