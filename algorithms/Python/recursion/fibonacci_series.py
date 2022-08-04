# Recursive program to find fibonacci series

def fibonacci(n):
    if n == 0 or n == 1:
        return n
    else:
        return fibonacci(n - 1) + fibonacci(n - 2)


if __name__ == '__main__':
    num = int(input("Enter the number of elements of Fibonacci series: "))
    x = 0       # first element = 0
    if num <= 0:
        print("Enter positive number")
    else:
        print("Fibonacci Series: ")
        for i in range(num):
            print(fibonacci(x), end=" ")
            x += 1

            
"""
OUTPUT:
Enter the number of elements of Fibonacci series: 0
Enter positive number

OUTPUT:
Enter the number of elements of Fibonacci series: 6
Fibonacci Series: 
0 1 1 2 3 5 

OUTPUT:
Enter the number of elements of Fibonacci series: -6
Enter positive number
"""
