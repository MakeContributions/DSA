"""
Function that uses a recursive approach to check  
if a string is a palindrome 
Time Complexity: O(N) where N is the length of the
string
"""

def recursive_is_palindrome(s: str) -> bool:
  if len(s) <= 1:
    return True
  if s[0] != s[-1]:
    return False
  return recursive_is_palindrome(s[1:-1])


# test cases
print(recursive_is_palindrome("abba") is True)
print(recursive_is_palindrome("abba") is True)
print(recursive_is_palindrome("") is True)
print(recursive_is_palindrome("abcd") is False)