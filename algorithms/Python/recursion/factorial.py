""" This is the update of factorial.py to provide standard of the clean codes."""

def factorial_nonrecursion(number):
    """
    >>> factorial_nonrecursion(3)
    6
    >>> factorial_nonrecursion(5)
    120
    >>> factorial_nonrecursion(0)
    1
    >>> factorial_nonrecursion(1)
    1
    """
    if isinstance(number, float):
        raise ValueError("Non integer number is not allowed")
    if number < 0:
        raise ValueError("Negative number is not allowed") # Raise an error here
    if number in {0,1}:
        return 1

    result = 1
    for i in range(1, number+1):
        result = result * i
    return result

def factorial_recursion(number):
    """
    >>> factorial_recursion(3)
    6
    >>> factorial_recursion(5)
    120
    >>> factorial_recursion(0)
    1
    >>> factorial_recursion(1)
    1
    """
    if isinstance(number, float) is True:
        raise ValueError("Non integer number is not allowed")
    if number < 0:
        raise ValueError("Negative number is not allowed")
    if number in {0,1}:
        return 1

    return number * factorial_recursion(number-1)

def main():
    """ main function for factorial """
    test_factorial = factorial_nonrecursion(5)
    print(test_factorial)

    test_recursion = factorial_recursion(4)
    print(test_recursion)

if __name__ == "__main__":
    main()
