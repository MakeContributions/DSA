'''
Find the largest element and place that element at the bottom
of the list. Repeat for each sub-array. 

O(n^2) time complexity. 
'''
def selectionSort(A):
	N = len(A)

	for i in range(N - 1, 0, -1):
		k = 0

		for j in range(1, i + 1):
			if A[j] > A[k]:
				k = j
		swap(A, k, i)


def swap(A, k, i):
	"""
	Helper function for swapping elements of the array. 
	"""
	tmp = A[k] 
	A[k] = A[i]
	A[i] = tmp


# A = [12, 3, 7, 22, -12, 100, 1]
# A = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
# A = [4, 1, 3, 9, 7]
A = [5, 4, 3, 2, 1]

selectionSort(A)

print("Sorted array: ")
for ele in A:
	print("\t" + str(ele))