# Returns the nth smallest value in an unordered list
# The idea is the following:
# 1. Choose a pivot value (here the middle element)
# 2. Split the list in 3 parts. The first part contains all the elements smaller than the pivot value, the second part contains all the elements equal to the pivot value and the third part contains all the elements greater than the pivot value.
# 3. If n is smaller than the length of the first part, then the nth smallest element is in the first part. Do the same for the second part and third part.
def nth_min(arr, n):
    if n > len(arr) or n < 1:
        return None
    v = arr[len(arr)//2]  # get the middle element
    arr_left = []
    arr_right = []
    arr_v = []
    for i in range(len(arr)):
        if arr[i] < v:
            arr_left.append(arr[i])
        elif arr[i] > v:
            arr_right.append(arr[i])
        else:
            arr_v.append(arr[i])
    if n <= len(arr_left):
        return nth_min(arr_left, n)
    elif n > len(arr_left) and n <= len(arr_left) + len(arr_v):
        return arr_v[0]
    else:
        return nth_min(arr_right, n - len(arr_left) - len(arr_v))


l = [5, 6, 4, 8, 3, 7, 2, 1, 9]
print(nth_min(l, 12))
print(nth_min(l, 5))
