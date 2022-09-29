#TO CHECK WHETHER A NUMBER IS PRIME OR NOT


def isPrime(N):
        if N<=1:
                return False
        
        for i in range(2, int(N**0.5) + 1):
                if N%i==0:
                        return False

        return True

# TIME COMPLEXITY - O(sqrt(N))

# EXAMPLES
# print(isPrime(3)) -> True
# print(isPrime(15)) -> False

# We are just checking till sqrt(N) as if their is any factor of a number
# greater than sqrt(N) then it's partner will be less than sqrt(N) as if a*b>N
# and a>=sqrt(N) then b<=sqrt(N) as if b>sqrt(N) then a*b>N.
