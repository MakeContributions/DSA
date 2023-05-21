#include<iostream>

/*
	Following code uses recursion to evaluate taylor series for
	e^x , cosine(x) and sine(x).

*/

double e_taylor(double x, int n_terms);
double cos_taylor(double x, int n_terms);
double sin_taylor(double x, int n_terms);
double factorial(double n);

int main() {
	
	int n_terms{ 7 };
	double x{ 4 };

	// Call to function for series calculation
	double r = sin_taylor(x, n_terms);

	
	std::cout << r << "\n";
}

// Calculate factorial of a number
double factorial(double n) {
	
	if (n == 0 || n == 1) {
		return 1;
	}
	else {
		
		return n * factorial(n - 1);
	}
}

// Calculate e^x using Taylor series
double e_taylor(double x, int n_terms) {
	static double p{ 1 }; // Previous power of x
	static double f{ 1 }; // Factorial

	
	if (n_terms == 0) {
		return 1;
	}
	else {
		
		double r = e_taylor(x, n_terms - 1);
		p = p * x; // Calculate next power of x
		f = f * n_terms; // Calculate next factorial
		return r + p / f; // Calculate and return the result
	}
}

// Calculate cosine using Taylor series
double cos_taylor(double x, int n_terms) {
	static double p{ 1 }; // Previous power of x
	static double f{ 1 }; // Factorial

	
	if (n_terms == 0) {
		return 1;
	}
	else {
		
		double r = cos_taylor(x, n_terms - 1);
		p = p * (x * x); // Calculate next power of x
		f = factorial(2 * (static_cast<double>(n_terms))); // Calculate next factorial

		// Alternate addition and subtraction for even and odd terms
		if (n_terms % 2 == 0) {
			return r + p / f;
		}
		else {
			return r - p / f;
		}
	}
}

// Calculate sine using Taylor series
double sin_taylor(double x, int n_terms) {
	static double p{ x }; // Previous power of x
	static double f{ 1 }; // Factorial

	
	if (n_terms == 0) {
		return x;
	}
	else {
		
		double r = sin_taylor(x, n_terms - 1);

		// Calculate next power of x based on term number
		p = p * (x * x);

		f = factorial((2 * (static_cast<double>(n_terms))) + 1); // Calculate next factorial

		// Alternate addition and subtraction for even and odd terms
		if (n_terms % 2 != 0) {
			return r - p / f;
		}
		else {
			return r + p / f;
		}
	}
}
