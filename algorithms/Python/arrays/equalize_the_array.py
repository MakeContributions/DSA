# Given an array of integers, determine the minimum number of elements to delete to leave only elements of equal value.
# Example
# arr=[1,2,2,3]
# Delete the  2 elements 1 and 3 leaving arr=[2,2]. If both twos plus either the 1 or the 3 are deleted, it takes 3 deletions to leave either [3] or [1]. The minimum number of deletions is 2.

#!/bin/python3

import math
import os
import random
import re
import sys

def equalizeArray(arr):
    
    hash_table={}
    for i in arr:
        if i in hash_table:
            hash_table[i]+=1
        else:
            hash_table[i]=1
    max_hash_table=0
    max_key=0
    for i in hash_table:
        if hash_table[i]>max_hash_table:
            max_hash_table=hash_table[i]
            max_key=i
    deletion=0
    for i in hash_table:
        if hash_table[i]<=max_hash_table and i!=max_key:
            deletion+=hash_table[i]
    return deletion

    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    result = equalizeArray(arr)

    fptr.write(str(result) + '\n')

    fptr.close()
