'''
Comb sort is a comparison based sorting algorithm and is an improved from of bubble sort. 

Best case time complexity Θ(n log n)
Worst case time complexity O(n^2)
'''

arr = [12, 3, 7, 22, -12, 100, 1]


def combSort(arr):
    """
    >>> combSort(arr)
    [-12, 1, 3, 7, 12, 22, 100]
    """
    gap = len(arr)
    shrink = int(gap * 10 / 13)
    sorted = False
    while gap > 1 or sorted == False:
        gap = int(gap / shrink)
        if gap <= 1:
            gap = 1
            sorted = True
        for i in range(len(arr)-gap):
            if arr[i] > arr[i+gap]:
                arr[i], arr[i+gap] = arr[i+gap], arr[i]
                sorted = False
    return arr


combSort(arr)
print("Sorted array is : ")
for ele in arr:
    print(ele)
