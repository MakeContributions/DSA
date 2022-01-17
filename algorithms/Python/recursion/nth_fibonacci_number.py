"""
Function for nth fibonacci number - Using recursion
Taking 1st two fibonacci numbers as 0 and 1
"""

FibArray = [1]
def fibonacci(n_val):
    """Fibonacci Number Main Function"""
    if n_val < 0:
        sol = "Incorrect input"
    elif n_val == 0:
        sol = 0
    elif n_val <= len(FibArray):
        sol = FibArray[n_val-1]
    else:
        temp_fib = fibonacci(n_val-1)+fibonacci(n_val-2)
        FibArray.append(temp_fib)
        sol = temp_fib
    return sol
# Driver Program
print(fibonacci(100))
