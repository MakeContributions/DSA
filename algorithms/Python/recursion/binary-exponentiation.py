"""
Binary Exponentiation:
a ^ n = (a ^ (n/2) ) ^ 2            |   if n is even
a ^ n = (a ^ ((n-1) / 2) ) ^ 2 * a  |   if n is odd

Now we can make recursive calls to the function, until the exponent, n, becomes 1
And we return, on the basis of the conditions specified above.

Refer to this article to understand more:
https://cp-algorithms.com/algebra/binary-exp.html#algorithm

[+] Time Complexity: logn 
[+] Space Complexity: Constant
"""

def pow(base: float, exponent: int):
    """
    Raises a base 'x' to the given exponent 'z' using binary exponentiation.

    Parameters:
    (float) base
    (int)   exponent

    Returns:
    (float) base ^ exponent (Mathematically) or base ** exponent.
    """

    if base == 0 and exponent < 0:
        raise ValueError("Base == 0 with a non-positive Exponent is not allowed")
    assert isinstance(base, float) or isinstance(base, int), "Base should be a float object"
    assert isinstance(exponent, int), "Exponent should be an int object"

    if exponent < 0:    # exponent is negative
        base = 1 / base
        exponent = -exponent

    if (exponent == 0):
        return 1
    
    ans = pow(base, exponent // 2)
    if exponent & 1:    # exponent is odd
        return base * ans * ans
    else:
        return ans * ans

def tests() -> None:
    """Driver Code"""
    
    print(pow(2.345, -64))
    print(pow(99, -99))

if __name__ == "__main__":
    tests()