"""
Algorithm Type : Array Traversal
Time Complexity : O(n)
Space Complexity : O(1)
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
    length = len(values)
    for index in range(len(values)):
        # *index_position = 0 - 10*
        # *index_position = -10*
        index_position = index - length
        if values[index_position] in values[0:index_position]:
            values.remove(values[index_position])

    return values


if __name__ == "__main__":
    print(make_distinct(sample_case))

