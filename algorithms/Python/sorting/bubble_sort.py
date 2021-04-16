arr = [23, 34, 25, 12, 54, 11, 90]


def bubbleSort(arr):
    """
    >>> bubbleSort(arr)
    [11, 12, 23, 25, 34, 54, 90]
    """
    n = len(arr)
    for i in range(n-1):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
    return arr


bubbleSort(arr)

print("Sorted array is:")
for item in arr:
    print(item)
