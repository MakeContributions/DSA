
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

    
    
                        
   
               
  
    
      



                         
