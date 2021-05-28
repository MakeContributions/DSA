# Print the fibonacci series upto term n using dynamic approach
# Fibonacci series starts from 0th term


key = int(input("Enter the term: "))

if key < 0:
    print("Please enter a valid term.")
    exit()

d = {}

print(f"The fibonacci series upto term {key}: ", end=" ")

d[0] = 0
d[1] = 1

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