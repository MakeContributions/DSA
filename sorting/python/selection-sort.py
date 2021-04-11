'''
Find the largest element and place that element at the bottom
of the list. Repeat for each sub-array. 

O(n^2) time complexity. 
'''
from string import ascii_letters

arrays = (
	[12, 3, 7, 22, -12, 100, 1],
	[10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0],
	[4, 1, 3, 9, 7],
	[0, -1.5, 1.5, 1.3, -1.3, -1.01, 1.01],
	list(reversed(ascii_letters)),
)


def selection_sort(arr):
	"""
	>>> all(selection_sort(arr) or arr == sorted(arr) for arr in arrays)
	True
	"""
	for i in range(len(arr) - 1, 0, -1):
		k = 0
		for j in range(1, i + 1):
			if arr[j] > arr[k]:
				k = j
		arr[i], arr[k] = arr[k], arr[i]  # swap


if __name__ == "__main__":
	for arr in arrays:
		selection_sort(arr)
		print("Sorted array: ")
		for ele in arr:  # type: ignore
			print(f"\t{ele}")
