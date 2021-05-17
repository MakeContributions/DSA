"""
Algorithm Type: Array Traversal
Time Complexity: O(n)
"""
numbers = [1, 2, 4, 3, 6, 7, 9, 8, 10]
n = 10

def missing_number(numbers, n):
    s = sum(numbers)
    expected_s = (n*(n+1))//2 #for C++ or similar, keep in mind expected_s can overflow MAX INT limit.
    return expected_s - s


if __name__ == "__main__":
  print(missing_number(numbers, n))
