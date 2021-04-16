"""
Analogizing this algorithm with inserting a playing 
card into your hand, we distinguish the "key" as
the inserting card and find the position of that 
card among the previous j - 1 cards. 

O(n^2) runtime (the deck is sorted in descending order).
"""
arr = [12, 3, 7, 22, -12, 100, 1]


def insertion_sort(arr):
	"""
	>>> insertion_sort(arr)
	>>> arr
	[-12, 1, 3, 7, 12, 22, 100]
	"""
	for j in range(1, len(arr)):
		key = arr[j]
		# insert the key into the sorted sequence arr[1, ... , j - 1]
		i = j - 1
		while i >= 0 and arr[i] > key:
			arr[i + 1] = arr[i]
			i -= 1
		arr[i + 1] = key


if __name__ == "__main__":
	insertion_sort(arr)
	print("Sorted array: ")
	for ele in arr:
		print(f"\t{ele}")
