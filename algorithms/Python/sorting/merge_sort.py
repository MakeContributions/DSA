## Implementation of merge sort 
## Merge Sort is a recursive algorithm which sorts the list by divide and conquer approach
def merge_sort(list):
    # if list size <= 1, the list is anyway sorted! :)
    if len(list)==1: return list
    #splitting the list into half 
    mid = len(list)//2 # integer division
    l = list[:mid]
    r = list[mid:]
    merge_sort(l) # recursive calling of left part of list 
    merge_sort(r) # recursive calling of right part of list
    #merging the left and right parts
    i=j=k=0
    while(i<len(l)and j<len(r)): 
        if l[i]<=r[j]:
            list[k]=l[i]
            i+=1
        else:
            list[k]=r[j]
            j+=1
        k+=1
    while(i<len(l)):
        list[k]=l[i]
        i+=1
        k+=1
    while(j<len(r)):
        list[k]=r[j]
        j+=1
        k+=1
    return list
##### main ###
if __name__ == '__main__':
    print("Enter the list: ")
    arr = [int(i) for i in input().split()] # Entered list will be in string format, so using list comprehensions, we are converting into a integer list
    arr = merge_sort(arr) 
    for i in arr:
        print(i,end=" ")
