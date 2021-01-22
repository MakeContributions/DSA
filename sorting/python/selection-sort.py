'''
Find the largest element and place that element at the bottom
of the list. Repeat for each sub-array. 

O(n^2) time complexity. 
'''
def selectionSort(A):
	N = len(A)

	for i in range(N - 1, 1, -1):
		k = 0

		for j in range(1, i):
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


A = [12, 3, 7, 22, -12, 100, 1]
selectionSort(A)

print("Sorted array: ")
for ele in A:
	print("\t" + str(ele))