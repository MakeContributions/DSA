#Code in python for count sort 
def count_sort(a):
    max_element = int(max(a))
    min_element = int(min(a))
    range_of_elements = max_element - min_element + 1
    # Create a count array to store count of individual
    # elements and initialize count array as 0
    c= [0 for _ in range(range_of_elements)]
    o= [0 for _ in range(len(a))]
    for i in range(0, len(a)):
        c[a[i]-min_element] += 1
    for i in range(1, len(c)):
        c[i] += c[i-1]
    for i in range(len(a)-1, -1, -1):
        o[c[a[i] - min_element] - 1] = a[i]
        c[a[i] - min_element] -= 1
    for i in range(0, len(a)):
        a[i] = o[i]
 
    return a
a=[-1,-2,6,5,10]
ans = count_sort(a)
print("Sorted array is ")
print(ans)

#TIME COMPLEXITY
#O(n+k) where n is the number of elements in input array and k is the range of input 

