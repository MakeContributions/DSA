#PRODUCT OF NUMBERS

def productNum(N):

	if N//10==0:
		return N  
	else:
		return N%10 * productNum(N//10)

# TIME COMPLEXITY - O(M) where M is length of digits of number N.
# SPACE COMPLECITY - O(M) where M is length of digits of number N.

# EXAMPLES 
# print(productNum(123)) -> 6 
# print(productNum(222)) -> 8
