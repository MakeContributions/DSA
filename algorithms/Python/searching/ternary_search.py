"""
    TERNARY SEARCH
    Time Complexity: O(log3 N)
    Working: Similar to binary search but here we have two searc point (mid)
    Steps:
        1. Compare with elements at mid1 and mid2. Stop if found
        2. If more than mid1 and less than mid2 - working field is the second part
        3. If less than mid1 - working field is the first part
        4. If more than mid2 - working field is the third part
"""
arr = [10, 13, 46, 51, 139, 467]
targets = [2, 467]

def ternarySearch(arr, target):
    left, right = 0, len(arr) - 1
    index = -1

    while(left <= right):
        mid1, mid2 = left + (right - left) // 3, right - (right - left) // 3

        # checking for condition 1
        if target == arr[mid1]:
            index = mid1
            break
        if target == arr[mid2]:
            index = mid2
            break

        # checking for condition 2
        if target > arr[mid1] and target < arr[mid2]:
            left, right = mid1 + 1, mid2 - 1

        # checking for condition 3
        elif target < arr[mid1]:
            right = mid1 - 1

        # checking for condition 4
        else:
            left = mid2 + 1
    return index

for target in targets:
    result = ternarySearch(arr, target)
    if result == -1:
        print(target, "is not present in", arr)
    else:
        print(target, "is present in the position:", result + 1)
