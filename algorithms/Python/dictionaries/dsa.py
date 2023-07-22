def two_sum(nums, target):
    # Create a dictionary to store the elements and their indices
    num_dict = {}

    # Traverse the array
    for i, num in enumerate(nums):
        # Calculate the complement required to reach the target
        complement = target - num

        # Check if the complement exists in the dictionary
        if complement in num_dict:
            # Return the indices of the two numbers that add up to the target
            return [num_dict[complement], i]
        
        # Store the current element and its index in the dictionary
        num_dict[num] = i

    # If no pair is found, return [-1, -1]
    return [-1, -1]

# Test example
nums = [2, 7, 11, 15]
target = 9
result = two_sum(nums, target)
print(result)  # Output: [0, 1] (Because nums[0] + nums[1] = 2 + 7 = 9)
