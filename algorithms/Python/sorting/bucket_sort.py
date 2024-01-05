def bucket_sort(arr):
    # Find the maximum value in the array
    max_val = max(arr)
    
    # Create buckets
    buckets = [[] for _ in range(max_val + 1)]
    
    # Place each element in its respective bucket
    for num in arr:
        buckets[num].append(num)
    
    # Concatenate the buckets to get the sorted array
    sorted_arr = []
    for bucket in buckets:
        sorted_arr.extend(bucket)
    
    return sorted_arr

# Example:
arr = [5, 2, 9, 1, 5, 6]
sorted_arr = bucket_sort(arr)
print("Bucket Sort:", sorted_arr)
