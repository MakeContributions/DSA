# Interpolation Search Algorithm

**Interpolation search** is an efficient searching algorithm used for finding a target element in a sorted array. It improves upon binary search by estimating the position of the target element based on its value and the distribution of values in the array.

1. Time Complexity: O(log(log n)) on average, O(n) in the worst case.
2. Space Complexity: O(1).
3. Applications: Used in scenarios where data is uniformly distributed and binary search is not optimal.
4. Founder's Name: Jon Louis Bentley.


## Steps:
1. Initialization: Set low to the index of the first element and high to the index of the last element in the sorted array.
2. Calculate Probe Position: Estimate the position of the probe using the formula:
   mid = low + ((target - array[low]) * (high - low)) / (array[high] - array[low])
3. Check if Target Found:
	If array[mid] equals the target, return mid.
	If array[mid] is less than the target, update low = mid + 1 and repeat step 2.
	If array[mid] is greater than the target, update high = mid - 1 and repeat step 2.
4. Repeat or Return: Continue steps 2 and 3 until the target is found or low is greater than high. If low becomes greater than high, the target is not in the array.

## Example:
Suppose we have a sorted array: [10, 20, 30, 40, 50, 60, 70, 80, 90, 100], and we want to search for the element 60.

1. Initialization:

	low = 0
	high = 9
2. Calculate Probe Position:

mid = 0 + ((60 - 10) * (9 - 0)) / (100 - 10)
    = 0 + (50 * 9) / 90
    = 0 + 450 / 90
    = 5
3. Check if Target Found:
	array[mid] = array[5] = 60 (match found)

4. Return index 5 as the position of the target element 60 in the array.

## Implementation

I will add it

## Video URL 

[Watch Interpolation Search Algorithm](https://www.youtube.com/watch?v=YSVS5GG1JuI)

## Others 

Interpolation search performs well when the elements in the array are uniformly distributed. However, it may not perform optimally if the array has irregularly spaced elements or is heavily weighted towards one end. In such cases, binary search or other algorithms might be more suitable.


## Generated using chatGPT
