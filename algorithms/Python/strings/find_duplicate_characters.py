"""
Problem:
Given a string, find all the characters that occur more than once, ignoring the case and whitespaces.
Given a string inp_str, return a list of strings containing characters that occur more than once, ignoring the case.
You can return characters in any order, if no duplicates are found return an empty list [].


Solution:
In this solution maintain a dictionary for the count of occurence of characters, ignoring the case. Dictionary 
will have the keys as the characters and their value as the count of occurrence in string.

We will iterate over the string the and will check whether chracter exists in dictionary or not.
If character exists, we will increment the count of charcter (value) by 1.
If character does not exists, we will add a new key in the dictionary with key as character and value as 1.

We will return the list of characters from the dictinary keys for whom value is greater than 1.

Complexity Analysis:
Time complexity: O(n). We traverse the string containing n elements only once. 
Space complexity: O(n). The extra space required depends on the number of items stored in the dictionary,
which stores at most n elements
"""


def duplicate_characters(inp_str):
    dictionary = {}
    for char in inp_str:
        if char in dictionary.keys():
            dictionary[char] += 1
        else:
            dictionary[char] = 1
    
    duplicates = []

    for char, count in dictionary.items():
        if count > 1:
            duplicates.append(char)

    return duplicates


def main():
    try:
        inp_str = input("Enter input string: ").strip().replace(" ","").lower()
    except ValueError:
        inp_str = 'testingstring'
    print(duplicate_characters(inp_str))


if __name__ == "__main__":
    main()
