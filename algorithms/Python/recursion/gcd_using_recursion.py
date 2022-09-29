#EUCLIDS ALGORITHM 

def gcd(a, b):
	if a<0:
		a = -a  
	if b<0:
		b = -b
	if b==0:
		return a  
	else:
		return gcd(b, a%b)


#TIME COMPLEXITY - O(log(min(a, b)))
#EXAMPLES
#print(gcd(10, 2)) -> 2
#print(gcd(30, 15)) -> 3
#print(gcd(-30, 15)) -> 3
#WORKING
#We are using the Euclidean Algorithm to calculate the GCD of a number
#it states that if a and b are two positive integers then GCD or greatest common
#divisors of these two numbers will be equal to the GCD of b and a%b or
#gcd(a, b) = gcd(b, a%b) till b reaches 0
