"""
Output the first character which occurred once in the string
I/P: "abcbadabfaa"
O/P: "c" (-1 if no such character is there)

Time Complexity: O(n)
Space Complexity: O(26) => O(1)
"""
string = "abcbadabfaa"  # Constraint: only smallcase letters are there

def first_non_repeating_character(string):
    """
    One way to do this is to have two dictionaries one which keeps the count of character,
    other dictionary will keep the first appearance of the character (index).
    After a traversal. Look in first dictionary for characters occurring once and output the one which
    has the first appearance as per second dictionary.

    Since in this case we have special constraint in mind. We will go with a cleverer way by reducing more stack space.
    """
    n = len(string)
    occurrence = [n]*26
    for i in range(len(string)):
        index = ord(string[i])-ord('a')
        if index < 0 or index > 25:
            return ("Invalid")
        if occurrence[index] == n:
            occurrence[index] = i
        else:
            occurrence[index] += n
    return string[min(occurrence)] if min(occurrence) < n else -1

if __name__ == "__main__":
    print(first_non_repeating_character(string))
