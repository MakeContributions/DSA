"""
Algorithm Type: Array Traversal
Time Complexity: O(n)
"""
numbers = [2, 2, 5, 6, 2, 6, 2, 10, 2]

def majority_element(numbers):
    m = float("inf")
    cnt = 0
    for num in numbers:
        if cnt == 0:
            m = num
            cnt += 1
        elif m == num:
            cnt += 1
        else:
            cnt -= 1
    # to verify the most frequent number is greater than length of aaray//2
    recheck_cnt = 0
    for num in numbers:
        if num == m:
            recheck_cnt += 1
    return m if recheck_cnt > len(numbers)//2 else None

if __name__ == "__main__":
  print(majority_element(numbers))
