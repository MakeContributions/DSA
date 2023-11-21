# counts the positive integers up to a given integer n that are relatively prime to n

def euler_totient(n):
    result = n
    p = 2

    while p * p <= n:
        if n % p == 0:
            while n % p == 0:
                n //= p
            result *= (1.0 - (1.0 / float(p)))
        p += 1

    if n > 1:
        result *= (1.0 - (1.0 / float(n)))

    return int(result)
# TIME COMPLEXITY - O(sqrt(N))

# Example usage
#number = 10 ———> 4


