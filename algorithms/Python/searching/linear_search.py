arr = [1, 4, 7, 9, 14, 17, 39, 56]
targets = (8, 39)


def linear_search(arr, target):
    """
    >>> all(linear_search(arr, x) == arr.index(x) if x in arr else -1 for x in targets)
    True
    """
    for i, item in enumerate(arr):
        if item == target:
            return i
    return -1


for target in targets:
    print(f"linear_search({arr}, {target}) = {linear_search(arr, target)}")
