def gcd(a, b):

	if b==0:
		return a  
	else:
		return gcd(b, a%b)

#EUCLIDS ALGORITHMS 
#TIME COMPLEXITY - O(log(min(a, b)))
