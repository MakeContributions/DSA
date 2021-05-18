"""
Remove all duplicates from a string

I/P: "bbaaccdefabafaz"
O/P: "bacdefz"
Time Complexity: O(n)
Space Complexity: O(26) (constant)
"""

string = "bbaaccdefabafaz"  # Constraint: only smallcase letters are there

def remove_duplicate(string):
    alphabet = "0" * 26 # instead of going for classic use of sets, dictionaries we can use string containing bits. Either way is fine.
    ans_string = ""
    for letter in string:
        index = ord(letter)-ord('a')
        if index < 0 or index > 25:
            return ("Invalid")
        if alphabet[index] == "1":
            pass
        else:
            index = ord(letter)-ord('a')
            if index == 0:
                alphabet = "1" + alphabet[1:]
            else:
                alphabet = alphabet[0:index] + "1" + alphabet[index+1:]
            ans_string += letter
    return ans_string

if __name__ == "__main__":
    print(remove_duplicate(string))
