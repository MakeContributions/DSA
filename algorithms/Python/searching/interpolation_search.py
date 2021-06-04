def interpolation_search(array, x):
    """
    Use interpolation search to find a specified integer
    """
    if isinstance(x, int) and isinstance(array, list): # check that x is integer and array is list
        if len(array) < 1: # if array length is less than 1 print message
            return False
        elif len(array) == 1 and x in array: # if x is only element of array return index 0
            return 0
        elif len(array) > 1 and x in array: # search if array length > 1 and x is in the array
            min = 0
            max = len(array) - 1
            while min <= max:
                if array[min] == array[max] == x:
                    return min
                elif array[min] == array[max] != x:
                    return False
                else:
                    p = int(min + (x-array[min])*(max-min) / (array[max]-array[min]))
                    if array[p] == x:
                        return p
                    elif x < array[p]:
                        max = p - 1
                        continue
                    elif x > array[p]:
                        min = p + 1
                        continue
        else:
            return False # if x is not in array return false
    else:
        raise Exception('Please make sure x is an integer and array is a list.')


if __name__ == '__main__':
    tests = [
    ([1,4,7,10,13,16], 13),
    ([1,4,7,10,13,16], 11),
    ([1,1,1,1,1,1], 1),
    ([0,0,0,1,1,1,1,1,1,2,3,4,5], 1),
    ([24], 24),
    ([], 24)
    ]

    for test in tests:
        print(interpolation_search(test[0], test[1]))
