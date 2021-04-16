from collections import namedtuple

TestData = namedtuple("TestData", "array target expected")

test_data = (
    TestData([1, 2, 3, 4, 5], 1, True),
    TestData([0, 4, 10, 1000], 10, True),
    TestData([], -2, False),
)


def binary_search(array: list, target: int) -> bool:
    """
    Search a sorted list to find a target integer

    >>> all(binary_search(x.array, x.target) == x.expected for x in test_data)
    True
    """
    if len(array) < 1:
        return False
    if len(array) == 1:
        return array[0] == target
    mid = len(array) // 2
    if array[mid] < target:
        return binary_search(array[mid:], target)
    elif array[mid] > target:
        return binary_search(array[:mid], target)
    else:
        return True


if __name__ == "__main__":
    for item in test_data:
        print(
            f"binary_search({item.array}, {item.target}) is "
            f"{binary_search(item.array, item.target)}"
        )
