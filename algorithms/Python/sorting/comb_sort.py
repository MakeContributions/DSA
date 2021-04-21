
"""
Read three integers and sort them in ascending order.
After, print these values in ascending order, a blank line and then the values in the sequence as they were readed.

"""
# Solotion
arr = [12, 3, 7, 22, -12, 100, 1]


def comb_sort(arr):
    """


    """
    gap = len(arr)
    shrink = int(gap * 10 / 13)
    sorted = False
    while(gap > 1 or sorted == False):
        gap = int(gap / shrink)
        if(gap <= 1):
            gap = 1
            sorted = True
        for i in range(len(arr)-gap):
            if(arr[i] > arr[i+gap]):
                arr[i], arr[i+gap] = arr[i+gap], arr[i]
                sorted = False
    return arr


comb_sort(arr)
print("Sorted  list : ")
for ele in arr:
    print(ele)
