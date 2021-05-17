"""
Algorithm Type: Array Traversal
Time Complexity: O(n)
"""
numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
k = 3

def rotate_array(numbers, k):
    n = len(numbers)
    k = k % n
    if k == 0:
        return numbers
    for i in range(n-k):
        if i>((n-k)//2):
            break
        numbers[i], numbers[n-k-(i+1)] = numbers[n-k-(i+1)], numbers[i]

    for i in range(k):
        if i>k//2:
            break
        numbers[-1-i], numbers[-k+i] = numbers[-k+i], numbers[-1-i]
    reversed_numbers = numbers[::-1]
    return reversed_numbers

if __name__ == "__main__":
  print(rotate_array(numbers, k))
