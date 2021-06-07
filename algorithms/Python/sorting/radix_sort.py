"""
Radix Sort
Time Complexity: O(nk + n). 
n is the size of input list and k is the digit length of the number.
"""

def radix_sort(arr, simulation=False):
    position = 1
    max_number = max(arr)

    iteration = 0
    if simulation:
        print("iteration", iteration, ":", *arr)

    while position <= max_number:
        queue_list = [list() for _ in range(10)]

        for num in arr:
            digit_number = num // position % 10
            queue_list[digit_number].append(num)

        index = 0
        for numbers in queue_list:
            for num in numbers:
                arr[index] = num
                index += 1

        if simulation:
            iteration = iteration + 1
            print("iteration", iteration, ":", *arr)

        position *= 10
    return arr

arr = [142, 34, 6, 17, 113, 2, 261, 72]

if __name__ == "__main__":
    print("Sorted Array:", radix_sort(arr))
    
# Runtime Test Cases:-
# Test case 1.
# Enter the list of numbers: 12 7 56 42
# Sorted list: [7 12 42 56]
# Test case 2.
# Enter the list of numbers: 142 34 6 17 113 2 261 72 
# Sorted list: [2 6 17 34 72 113 142 261]
# For radix sort, Best = Worst = Average Time Complexity is O(nk+n).
