"""
Algorithm Type : Array Traversal
Time Complexity : O(n)  -> previously O(n^2)
Space Complexity : O(n) -> previously O(1)
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
    seen = []
    index = 0
    l = len(values)
    while(index < l):
        
        if (values[index] not in seen):

            seen.append(values[index])
        
        index += 1

    return seen


if __name__ == "__main__":
    print(make_distinct(sample_case))

