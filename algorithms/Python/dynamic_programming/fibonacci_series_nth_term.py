# Find the nth term of fibonacci series using dynamic approach
# Fibonacci series starts from 0th term

"""
Output:

The term 10 of the fibonacci series is:  55

"""

key = 10

if key < 0:
    print("Please enter a valid term.")
    exit()

d = {0: 0, 1: 1}

if key < 2:
    print(f"The term {key} of the fibonacci series is: ", d[key])
    exit()


def fibo(n):
    if n in d.keys():
        return d[n]
    else:
        d[n] = fibo(n - 1) + fibo(n - 2)
        return d[n]


fibo(key)

print(f"The term {key} of the fibonacci series is: ", d[key])