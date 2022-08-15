#TO CHECK WHETHER A NUMBER IS PRIME OR NOT


N = int(input())

PRIME = True

for i in range(2, int(N**0.5+1)):
	if N%i==0:
		PRIME = False 
		break 

if PRIME:
	print(f"{N} is prime")
else:
	print(f"{N} is not prime")