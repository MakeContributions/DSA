"""
Analogizing this algorithm with inserting a playing 
card into your hand, we distinguish the "key" as
the inserting card and find the position of that 
card among the previous j - 1 cards. 

O(n^2) runtime (the deck is sorted in descending order).
"""

def insertionSort(A):
	N = len(A)

	for j in range(1, N):
		key = A[j]
		#insert the key into the sorted sequence A[1, ... , j - 1]
		i = j - 1
		while i >= 0 and A[i] > key:
			A[i + 1] = A[i]
			i -= 1

		A[i + 1] = key


A = [12, 3, 7, 22, -12, 100, 1]
insertionSort(A)

print("Sorted array: ")
for ele in A:
	print("\t" + str(ele))

