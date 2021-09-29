"""
Base Case: If array size is 1 or smaller, return.
Recursively sort first n-1 elements.
Insert last element at its correct position in sorted array.
"""

def insertionSort_rec(array, n):
    # base case
    if n <= 1:
        return
    # Sort first n-1 elements
    insertionSort_rec(array, n-1)
    '''Insert last element at its correct position
        in sorted array.'''
    end = array[n-1]
    j = n-2
    
    # Move elements of arr[0..i-1], that are
    # greater than key, to one position ahead
    # of their current position
    while (j >= 0 and array[j] > end):
        array[j+1] = array[j]
        j -= 1
    array[j+1] = end


arr = [6, 5, 2, 7, 12, 9, 1, 4]
insertionSort_rec(arr, len(arr))
print("Sorted array is:")
print(arr)
