#Pigeonhole sort is a sorting algorithm that is suitable for sorting lists of elements where the number n of elements and the length N of the range of possible key values are approximately# the same.[1] It requires O(n + N) time. It is similar to counting sort, but differs in that it "moves items twice: once to the bucket array and again to the final destination [whereas] c#ounting sort builds an auxiliary array then uses the array to compute each item's final destination and move the item there.
#The pigeonhole algorithm works as follows:

#    Given an array of values to be sorted, set up an auxiliary array of initially empty "pigeonholes", one pigeonhole for each key in the range of the keys in the original array.
#    Going over the original array, put each value into the pigeonhole corresponding to its key, such that each pigeonhole eventually contains a list of all values with that key.
#    Iterate over the pigeonhole array in increasing order of keys, and for each pigeonhole, put its elements into the original array in increasing order.


def pigeonhole_sort(array):
    my_min=min(array)
    my_max=max(array)
    size=my_max - my_min + 1

    holes=[0] * size

    for x in array:
        assert type(x) is int,"integers only please"
        holes[x - my_min] += 1

    i = 0
    for count in range(size):
        while holes[count] > 0:
            holes[count] -= 1
            array[i] = count + my_min
            i += 1

a=[2,1,7,5,93,67,34,21]
print("Sorted order is ",end= " ")
pigeonhole_sort(a)
for i in range(0,len(a)):
    print(a[i],end=" ")
    
               
        
