def quickSort(arr):
    n = len(arr)
    if n == 1 or n == 0:
        return arr
    pi = 0
    left = [arr[i] for i in range(n) if arr[i] <= arr[pi] and i != pi]
    right = [arr[i] for i in range(n) if arr[i] > arr[pi]]
    return quickSort(left) + [arr[pi]] + quickSort(right)


arr = [10, 1, 6, 256, 2, 53, 235, 53, 1, 7, 23]
print("Sorted Array:", quickSort(arr))
