# https://practice.geeksforgeeks.org/problems/good-or-bad-string1417/1/

from string import ascii_lowercase

vowels = "aeiou"
constants = "".join(c for c in ascii_lowercase if c not in vowels)


def is_good_str(s: str) -> bool:
    """
    >>> is_good_str("aeioup??")
    True
    >>> is_good_str("bcdaeiou??")
    False
    """
    s = list(s.lower())
    for i, char in enumerate(s):
        if char in constants:
            s[i] = "c"
        elif char in vowels:
            s[i] = "v"
    s = "".join(s)
    return not "c" * 4 in s.replace("?", "c") and (
        not "v" * 6 in s.replace("?", "v")
    )
    

if __name__ == "__main__":
    print(is_good_str("aeioup??"))
    print(is_good_str("bcdaeiou??"))
