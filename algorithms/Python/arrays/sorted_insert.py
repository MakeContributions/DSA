"""
Algorithm Type : Array Insertion
Time Complexity : O(log n)
Space Complexity : O(1)
"""

import math

# find the insertion position of an element in a sorted list
def sortedIndex(a: list, item):
  start = 0
  end = len(a)
  depth = math.log(len(a) + 1, 2) # the depth of the binary tree
  i = 0
  while i <= math.ceil(depth): # iterative binary search
    mid = (start + end) // 2
    if start >= end:
      break
    if item == a[mid]:
      return mid # returns the index of the duplicate element
    elif item > a[mid]:
      start = mid + 1
    else:
      end = mid
    i += 1
  return mid # returns the insertion position for new element

def sortedInsert(a: list, item):
  a.insert(sortedIndex(a, item), item)
  return a

if __name__ == "__main__":
  print(sortedIndex(['a', 'b', 'c', 'd'], 'b')) # 1
  print(sortedIndex([0, 1, 2, 3], 1.5)) # 2
  print(sortedInsert([0, 1, 2, 3], 1.5)) # [0, 1, 1.5, 2, 3]