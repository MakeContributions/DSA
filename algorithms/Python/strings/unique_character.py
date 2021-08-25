"""
    Algorithm Type : Find the all the characters in the given strings are unique
    Time Complexity:    O(n)
"""
s = 'abcd'

def is_unique(s: str) -> bool:
    """
    >>> is_unique('ABCDE')
    True
    """
    """
    >>> is_unique('programmer')
    False
    """
    
    
    arr = [False for _ in range(128)] #creating hashtable with False input
    for character in s:        #iterate throughout the string
        char_value = ord(character)
        if arr[char_value]:
            return False
        else:
            arr[char_value] = True
    return True
    
if __name__ == "__main__": 
    print(is_unique(s))
    print(is_unique('ABCDEDD'))
    print(is_unique('programmer'))