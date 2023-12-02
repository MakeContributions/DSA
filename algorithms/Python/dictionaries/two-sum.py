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

def two_sum_indices(nums, target):
    """
    Find indices of two numbers in the given list that add up to the target.

    Parameters:
        nums (list): List of integers.
        target (int): Target sum.

    Returns:
        list: A list containing the indices of the two numbers that add up to the target.
              If no such pair is found, returns [-1, -1].
    """
    # Dictionary to store the complement of each element and its index
    complement_dict = {}

    # Iterate through the list with both index and element using enumerate
    for current_index, current_element in enumerate(nums):
        # Calculate the difference between the target and the current element
        complement = target - current_element

        # Check if the complement exists in the dictionary
        if complement in complement_dict:
            # Return the indices of the two numbers that add up to the target
            return [complement_dict[complement], current_index]

        # Store the current element and its index in the dictionary
        complement_dict[current_element] = current_index

    # If no such pair is found, return [-1, -1]
    return [-1, -1]


def main():
    try:
        # Get input from the user
        arr = list(map(int, input("Enter space-separated integers: ").split()))
        target = int(input("Enter target: "))
    except ValueError:
        # Use default values if invalid input is provided
        arr = [2, 7, 11, 15]
        target = 9

    # Call the function and print the result
    result = two_sum_indices(arr, target)
    print("Result:", result)


if __name__ == "__main__":
    main()
