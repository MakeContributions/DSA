"""
Problem:
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to
target. You can not use the same element twice.
You can return any one of the answers in any order, if not found return [-1, -1].


Solution:
In this solution we check if each element's complement i.e. difference between the target and the element
(target−nums[i]) exists in the dictionary. If it does exist, we return current element's index and its complement's
index else we store the complement in the dictionary.
Beware that the complement must not be nums[i] itself, because we can not use the same element twice.

Complexity Analysis:
Time complexity: O(n). We traverse the list containing nn elements only once. Each lookup in the dictionary costs only
O(1) time.
Space complexity: O(n). The extra space required depends on the number of items stored in the dictionary,
which stores at most nn elements.
"""


def twoSum(nums, target):
    dictionary = {}
    # using enumerate to iterate through the list keeping track of both index and element
    for i, val in enumerate(nums):
        diff = target - val
        if diff in dictionary:
            return [dictionary[diff], i]
        dictionary[val] = i
    return [-1, -1]


def main():
    try:
        arr = list(map(int, input("Enter space-seperated integers: ").split()))
        tar = int(input("Enter target: "))
    except ValueError:
        arr = [2, 7, 11, 15]
        tar = 9
    print(twoSum(arr, tar))


if __name__ == "__main__":
    main()
