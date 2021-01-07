def binary_search(array: list, target: int) -> bool:
    """ searches through a sorted list to find a target integer """
    mid = len(array) // 2
    if len(array) < 1:
        return False
    if len(array) == 1:
        return array[0] == target
    if array[mid] < target:
        return binary_search(array[mid:], target)
    elif array[mid] > target:
        return binary_search(array[:mid], target)
    else:
        return True

if __name__ == "__main__":
    print(binary_search([1, 2, 3, 4, 5], 1))
    print(binary_search([0, 4, 10, 1000], 10))
    print(binary_search([], -2))
