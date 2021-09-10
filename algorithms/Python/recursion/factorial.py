def FactorialNonRecursion(number):
    """
    >>> FactorialNonRecursion(3)
    6
    >>> FactorialNonRecursion(5)
    120
    >>> FactorialNonRecursion(0)
    1
    >>> FactorialNonRecursion(1)
    1
    """
    if isinstance(number, float):
        raise ValueError("Non integer number is not allowed")
    if number < 0:
        raise ValueError("Negative number is not allowed") # Raise an error here
    if number == 0 or number == 1:
        return 1

    result = 1
    for i in range(1, number+1):
        result = result * i
    return result

def FactorialRecursion(number):
    """
    >>> FactorialRecursion(3)
    6
    >>> FactorialRecursion(5)
    120
    >>> FactorialRecursion(0)
    1
    >>> FactorialRecursion(1)
    1
    """
    if isinstance(number, float) is True:
        raise ValueError("Non integer number is not allowed")
    if number < 0:
        raise ValueError("Negative number is not allowed")
    if number == 0 or number == 1:
        return 1

    return number * FactorialRecursion(number-1)

def main():
    testFactorial = FactorialNonRecursion(5)
    print(testFactorial)

    testRecursion = FactorialRecursion(4)
    print(testRecursion)

if __name__ == "__main__":
    main()
