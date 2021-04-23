"""
Jump search algorithm iterates through a sorted list with a step of n^(1/2),
until the element compared is bigger than the one searched.If the item is not
in the particular step, it shifts the entire step.
It will then perform a linear search on the step until it matches the target.
If not found, it returns -1.
Time Complexity: O(√n)
Space Complexity: O(1)
"""

import math

arr = [0, 1, 2, 8, 13, 17, 19, 25, 31, 32, 42]
target = 25

def jump_search(arr: list, x: int) -> int:
    """
    >>> jump_search(arr, target) == (arr.index(target) if target in arr else -1)
    True
    """
    n = len(arr)
    step = int(math.floor(math.sqrt(n)))
    prev = 0
    while arr[min(step, n) - 1] < x:
        prev = step
        step += int(math.floor(math.sqrt(n)))
        if prev >= n:
            return -1
    while arr[prev] < x:
        prev = prev + 1
        if prev == min(step, n):
            return -1
    if arr[prev] == x:
        return prev
    return -1

def check_sort(test: list) -> bool:
    """checks whether the given list is sorted or not."""
    if sorted(test) == test:
        return True
    else:
        return False


if __name__ == "__main__":
    if check_sort(arr):
        res = jump_search(arr, target)
        if res == -1:
            print("Number not found!")
        else:
            print(f"Number {target} is at index {res}")
    else:
        print("Given list is not sorted!")
