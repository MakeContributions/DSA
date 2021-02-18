"""
Algorithm Type: Divide & Conquer
Time Complexity: O(n*log(n))
"""

def count_split_inv(arr, left, right):
  split_inv = ridx = lidx = 0
  size = len(arr)
  lsize = len(left)
  rsize = len(right)
  for i in range(size):
    if lidx != lsize and ridx != rsize:
      if right[ridx] <= left[lidx]:
        arr[i] = right[ridx]
        ridx += 1
        split_inv += lsize - lidx
      else:
        arr[i] = left[lidx]
        lidx += 1
    elif lidx == lsize:
      arr[i] = right[ridx]
      ridx += 1
    elif ridx == rsize:
      arr[i] = left[lidx]
      lidx += 1
  return split_inv;

def count_inversions(arr):
  size = len(arr)
  if size == 1:
    return 0
  mid = int(size/2)
  left = arr[:mid]
  right = arr[mid:]
  l_inv = count_inversions(left)
  r_inv = count_inversions(right)
  split_inv = count_split_inv(arr, left, right)

  return l_inv + r_inv + split_inv

with open("inp.txt") as f:
  lines = f.readlines()
  numbers = [int(line) for line in lines]

print(count_inversions(numbers))
