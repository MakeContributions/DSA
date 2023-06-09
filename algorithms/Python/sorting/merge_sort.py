# Implementation of merge sort
# The algorithm divides the array in two halves, sorts them and then merges them
# Time Complexity: O(nlogn)
# Space Complexity: O(n)


# function to merge two arrays
# a and b are two sorted arrays
# c is the resultant array
# i, j and k are the indices of a, b and c respectively
# time complexity of merge function is O(n)

def merge(a, b):
    c = [0] * (len(a) + len(b))
    i = j = k = 0
    # Traverse both arrays
    # Compare each element with each other
    # Add the smaller element to the resultant array
    # Increment the index of the array from which the element is added
    # If an array is completely traversed, add all the remaining elements of the other array to the resultant array
    while i < len(a) and j < len(b):
        if a[i] <= b[j]:
            c[k] = a[i]
            i += 1
        else:
            c[k] = b[j]
            j += 1
        k += 1

    while i < len(a):
        c[k] = a[i]
        i += 1
        k += 1

    while j < len(b):
        c[k] = b[j]
        j += 1
        k += 1
    return c


def merge_sort(arr):
    if len(arr) <= 1:
        return arr
    else:
        mid = len(arr) // 2
        a1 = merge_sort(arr[:mid])  # This sorts the left half of the array
        a2 = merge_sort(arr[mid:])  # This sorts the right half of the array
        return merge(a1, a2)


# main#
if __name__ == '__main__':
    arr = [10, 1, 6, 256, 2, 53, 235, 53, 1, 7, 0, -23, 23]
    print("Sorted Array:", merge_sort(arr))
