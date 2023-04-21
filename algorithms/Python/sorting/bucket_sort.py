#Bucket sort is a sorting algorithm that works by distributing the elements of
# an array into a number of buckets. Each bucket is then sorted individually,
# either using a different sorting# algorithm, or by recursively applying the
#bucket sorting algorithm. It is a distribution sort, a generalization of
# pigeonhole sort that allows multiple keys per bucket, and is a cousin of
#radix sort in the most-to-least significant digit flavor. Bucket sort can be
#implemented with comparisons and therefore can also be considered a comparison
#sort algorithm. The computational complexity depends on the algorithm used to
#sort each bucket, the number of buckets to use, and whether the input is
# uniformly distributed.  The average performance is O(n + n^2/#k + k) where k
# is the number of buckets:; O(n) when k approaches n.



def insertion_sort(bucket):
    for i in range(1,len(bucket)):
        val=bucket[i]

        j=i-1   

        while j >= 0 and bucket[j] >  val:
            bucket[j+1]=bucket[j]
            j-=1
            bucket[j+1] = val
        
def bucket_sort(input_list):
      max_value=max(input_list)
      size=max_value / len(input_list)

      buckets_list=[]
      for x in range(len(input_list)):
          buckets_list.append([])
                     
      for i in range(len(input_list)):
          j=int(input_list[i] /size)
          if j != len(input_list):
              buckets_list[j].append(input_list[i])
          else:
              buckets_list[len(input_list)-1].append(input_list[i])

          for z in range(len(input_list)):
              insertion_sort(buckets_list[z])

      final_output=[]
      for x in range(len(input_list)):
          final_output += buckets_list[x]
      print(final_output)


nums=[12,564,23,54,54,34,8,9,64,23,3,2,4,6]
bucket_sort(nums)

    
    
                        
   
               
  
    
      



                         
