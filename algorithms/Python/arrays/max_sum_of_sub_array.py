def max_sub_arr_sum(arr):
    arr_size = len(arr)
    max_sum = arr[0]
    max_sum_curr = arr[0]
     
    for i in range(1, arr_size):
        max_sum_curr = max(arr[i], max_sum_curr + arr[i])
        max_sum = max(max_sum, max_sum_curr)
         
    return max_sum
    

print("Enter array of numbers (Ex: 1 2 3 4 for [1, 2, 3, 4])")
arr = list(map(int, input().split()))
print("Maximum Sub Array Sum is", max_sub_arr_sum(arr))
