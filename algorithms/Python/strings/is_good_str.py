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
    c_or_v = ""
    for char in s.lower():
        if char in constants:
            c_or_v += "c"
        else:
            c_or_v += "v" if char in vowels else char
    return not "c" * 4 in c_or_v.replace("?", "c") and (
        not "v" * 6 in c_or_v.replace("?", "v")
    )
    

if __name__ == "__main__":
    print(is_good_str("aeioup??"))
    print(is_good_str("bcdaeiou??"))
