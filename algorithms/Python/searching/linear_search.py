def linear_search(a, x):
    for i in range(len(a)):
        if a[i] == x:
            return i
    return -1
    
a = [1,4,7,9,14,17,39,56]    
x = 8
y = 39

print(linear_search(a,x))
print(linear_search(a,y))
