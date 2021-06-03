# A dynamic programming based function to find nth
# Catalan number

"""
Output: 
The first 10 terms of Catalan sequence are :
1 1 2 5 14 42 132 429 1430 4862
"""


def catalan(n):
    """
    >>> catalan(2)
    2
    >>> catalan(5)
    42
    >>> catalan(-1)
    Traceback (most recent call last):
        ...
    IndexError: list assignment index out of range
    """
    # Base Case
    if n == 0 or n == 1:
        return 1

    # To store the result of subproblems

    cat_num = [0] * (n + 1)

    cat_num[0] = 1
    cat_num[1] = 1

    for i in range(2, n + 1):
        for j in range(i):
            cat_num[i] += cat_num[j] * cat_num[i - j - 1]
    return cat_num[n]


n = 10

if n<0:
    print("Please add a valid number")
    exit()

print(f"The first {n} terms of Catalan sequence are : ")
for i in range(n):
    print(catalan(i), end=" ")
