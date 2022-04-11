"""
Algorithm Type: Array sorting with 0s,1s and 2s in a single pass
Explain: To separate three different groups
Time Complexity: O(n)
Space Complexity: O(1)

    0 0 1 1 1 ? ? ? ? 2 2
        |     |     |
        v     v     v
       Low   Mid   High

   To goal of the algo is to shrink this '?' region
   wrapped by Mid and High

   > Low starts at 1
"""

numbers = [2, 0, 1, 1, 2, 0, 1, 2]


def DNFS(numbers: list) -> list:
    length = len(numbers)
    low = 0
    high = length - 1
    mid = 0
    while mid <= high:
        if numbers[mid] == 0:
            numbers[low], numbers[mid] = numbers[mid], numbers[low]
            low = low + 1
            mid = mid + 1
        elif numbers[mid] == 1:
            mid = mid + 1
        else:
            numbers[mid], numbers[high] = numbers[high], numbers[mid]
            high = high - 1
    return numbers

if __name__ == "__main__":
    print(DNFS(numbers))
