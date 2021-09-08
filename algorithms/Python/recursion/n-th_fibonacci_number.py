# Function for nth fibonacci number - Using recursion
# Taking 1st two fibonacci numbers as 0 and 1
 
FibArray = [0, 1]
def fibonacci(n):
    if n<0:
        print("Incorrect input")
    if n == 0:
        return 0
    elif n<= len(FibArray):
        return FibArray[n-1]
    else:
        temp_fib = fibonacci(n-1)+fibonacci(n-2)
        FibArray.append(temp_fib)
        return temp_fib
 
# Driver Program
print(fibonacci(100))
