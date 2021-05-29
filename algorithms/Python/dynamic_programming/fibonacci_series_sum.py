# Find the sum up to nth term of fibonacci series using dynamic approach
# Fibonacci series starts from 0th term

"""
Output:

Sum up to term 10 of fibonacci series is:  143

"""

key = 10

if key < 0:
    print("Please enter a valid term.")
    exit()

d = {0: 0, 1: 1}

if key == 0:
    print(f"Sum up to term {key} of fibonacci series: ", 0)
    exit()

if key == 1:
    print(f"Sum up to term {key} of fibonacci series: ", 1)
    exit()

sum = 1


def fibo(n):
    if n in d.keys():
        return d[n]
    else:
        d[n] = fibo(n - 1) + fibo(n - 2)
        global sum
        sum += d[n]
        return d[n]


fibo(key)

print(f"Sum up to term {key} of fibonacci series is: ", sum)