# Python implementation of Bingo Sort.
# This algorithm is derived from simple
# Selection Sort, but runs on  average and worst case
# O(m * n) where m=number of distinct elements and N
# is the size of the array or list. Performs best when
# repetition of every element is high in the array.
# Peforms better than quick sort, merge and heap sort
# if m < log n. 

# Function to print the Array
def printArray(arr):
	print("Sorted Array: ",end="")
	for ele in arr:
		print(ele, end=" ")
	print()

# function for Sorting the Array
def bingoSort(arr, size):

	# Finding the smallest element From the Array
	bingo = min(arr)
	
	# Finding the largest element from the Array
	largest = max(arr)
	nextBingo = largest
	nextPos = 0
	while bingo < nextBingo:
	
		# Will keep the track of the element position to
		# shifted to their correct position
		startPos = nextPos
		for i in range(startPos, size):
			if arr[i] == bingo:
				arr[i], arr[nextPos] = arr[nextPos], arr[i]
				nextPos += 1
				
			# Here we are finding the next Bingo Element
			# for the next pass
			elif arr[i] < nextBingo:
				nextBingo = arr[i]
		bingo = nextBingo
		nextBingo = largest
	
	# Printing the ELements of the Sorted Array
	printArray(arr)
		
arr = [ 5, 4, 8, 5, 4, 8, 5, 4, 4, 4 ]
bingoSort(arr, size = len(arr))

arr2 = [ 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 ]
bingoSort(arr2, size = len(arr2))

arr3 = [ 0, 1, 0, 1, 0, 1 ]
bingoSort(arr3, size = len(arr3))


