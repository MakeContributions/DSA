def recsum(n):
    if n<=1:
        return(n)
    else:
        return(n+recsum(n-1))

n= 15

if n<0:
    print("Enter a positive integer")
else:
    print("Sum =",recsum(n))
