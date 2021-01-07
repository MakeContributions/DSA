def bubbleSort(arr): 
	n = len(arr) 

	for i in range(n-1): 
		for j in range(0, n-i-1): 
			if arr[j] > arr[j+1] : 
				arr[j], arr[j+1] = arr[j+1], arr[j] 

arr = [23, 34, 25, 12, 54, 11, 90] 

bubbleSort(arr) 

print ("Sorted array is:") 
for i in range(len(arr)): 
	print (arr[i]) 