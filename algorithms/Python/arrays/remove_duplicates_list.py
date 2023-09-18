"""
Algorithm Type : Array Traversal
Time Complexity : O(n)  -> previously O(n^2)
Space Complexity : O(n) -> previously O(1)
"""
"""
Note: The space complexity will be O(n) strictly in the worst case that is a unique scenario for real-world problems.
"""

sample_case = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]


def make_distinct(values: list) -> list:
    """
    Remove duplicate elements in an array inplace without creating new array.

    Here, we are iterating the list backwards instead of forward because if we
    remove elements in an array it will cause some issues.

    Note : Wrapped with * are sample.
    """
    # *length = 10*
    seen = []    # -> creating a list of n-elements to accomodate n unique elements
    index = 0
    l = len(values)
    while(index < l):    # exactly looping through the list at once
        
        if (values[index] not in seen):    # if value is unique

            seen.append(values[index])    # add value to unique list
        
        index += 1    # increment the value ro the next element

    return seen    # returning unique list that is created


if __name__ == "__main__":
    print(make_distinct(sample_case))

