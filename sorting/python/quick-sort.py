arr = [10, 1, 6, 256, 2, 53, 235, 53, 1, 7, 0, -23, 23]


def quicksort(arr):
    """
    >>> quicksort(arr)
    [-23, 0, 1, 1, 2, 6, 7, 10, 23, 53, 53, 235, 256]
    >>> from string import ascii_letters
    >>> quicksort(list(reversed(ascii_letters))) == sorted(ascii_letters)
    True
    """
    length = len(arr)
    if length in (0, 1):
        return arr
    pi = 0
    left = [arr[i] for i in range(length) if arr[i] <= arr[pi] and i != pi]
    right = [arr[i] for i in range(length) if arr[i] > arr[pi]]
    return quicksort(left) + [arr[pi]] + quicksort(right)


if __name__ == "__main__":
    print("Sorted Array:", quicksort(arr))
