l=[0,0]
for i in range(4):
    direction,value = input().split(" ")
    if direction=="UP":
        l+=int(value[1])
    elif direction=="DOWN":
        l-=int(value[1])
    elif direction=="RIGHT":
        l+=int(value[0])
    elif direction=="LEFT":
        l-=int(value[0])
d=(l[0]**2+l[1]**2)**0.5
print(d)
    
