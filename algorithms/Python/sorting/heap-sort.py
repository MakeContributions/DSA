# Heap sort in python
from typing import Callable

test_arr = [10, 1, 6, 256, 2, 53, 235, 53, 1, 7, 0, -23, 23]

def heap_data(nums, index, heap_size):
    largest_num = index
    left_index = 2 * index + 1
    right_index = 2 * index + 2
    if left_index < heap_size and nums[left_index] > nums[largest_num]:
        largest_num = left_index

    if right_index < heap_size and nums[right_index] > nums[largest_num]:
        largest_num = right_index
    if largest_num != index:
        nums[largest_num], nums[index] = nums[index], nums[largest_num]
        heap_data(nums, largest_num, heap_size)
        
        
def heap_sort(nums):
    n = len(nums)
    for i in range(n // 2 - 1, -1, -1):
        heap_data(nums, i, n)
    for i in range(n - 1, 0, -1):
        nums[0], nums[i] = nums[i], nums[0]
        heap_data(nums, 0, i)
    return nums


if __name__ == "__main__":
    print("Sorted Array:", heap_sort(test_arr))
    

# Runtime Test Cases:-
# Test case 1.
# Enter the list of numbers: -1
# Sorted list: [-1]
# Time complexity : Best case = Avg case = Worst case = O(n logn)
# Test case 2.
# Enter the list of numbers: 10  5  0  -3  -1
# Sorted list: [-3  -1  0  5  10]
# Time complexity : Best case = Avg case = Worst case = O(n logn)
