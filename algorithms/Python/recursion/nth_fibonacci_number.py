"""
Function for nth fibonacci number - Using recursion
Taking 1st fibonacci numbers as 0
"""
def fibonacci(n):
    if n == 0 or n == 1:
        return n
    else:
        return fibonacci(n - 1) + fibonacci(n - 2)


if __name__ == '__main__':
    num = int(input("Enter the number of elements of Fibonacci series: "))
    x = 0
    if num <= 0:
        print("Enter Positive number")
    else:
        print("Fibonacci Series: ")
        for i in range(num):
            print(fibonacci(x), end=" ")
            x = x + 1

"""
OUTPUT:
Enter the number of elements of Fibonacci series: 16
Fibonacci Series: 
0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 

OUTPUT:
Enter the number of elements of Fibonacci series: 0
Enter Positive number

OUTPUT:
Enter the number of elements of Fibonacci series: -1
Enter Positive number
"""
