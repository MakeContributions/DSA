# Print the fibonacci series up to term n using dynamic approach
# Fibonacci series starts from 0th term

"""
Output:

The fibonacci series up to term 20:  0  1    1   2   3   5   8   13      21      34      55  
   89      144     233     377     610     987     1597    2584    4181    6765

"""

key = 20

if key < 0:
    print("Please enter a valid term.")
    exit()

d = {0: 0, 1: 1}

print(f"The fibonacci series up to term {key}: ", end=" ")

if key == 0:
    print(0)
    exit()
if key == 1:
    print(0, "\t", 1)
    exit()

print(0, "\t", 1, sep="", end="")


def fibo(n):
    if n in d.keys():
        return d[n]
    else:
        d[n] = fibo(n - 1) + fibo(n - 2)
        print("\t", d[n], end=" ")
        return d[n]


fibo(key)

print()