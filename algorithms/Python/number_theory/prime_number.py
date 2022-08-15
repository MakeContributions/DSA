# PRIME NUMBER CHECKER

def isPrime(n):

	for i in range(2, int(n**0.5)+1):
		if n%i==0:
			return False  # Will return False if number is not prime and no further checks will be done.

	return True   # Will return True if False is not returned in the above loop, hence number will be Prime.


# TIME COMPLEXITY - O(sqrt(N))

# We just need to check till sqrt(N) if a number is prime or not as if any factor exists bigger than root n then it's counterpart 
# will also be present as a*b = n, suppose a>=sqrt(n) then b must be less than or equal to sqrt(n) as if it is bigger or b>sqrt(n) 
# then a*b>n as multiplication of two numbers both bigger than sqrt(n) will result in a number that is bigger than n.


# EXAMPLES 

# print(isPrime(2)) -> True
# print(isPrime(15)) -> False 