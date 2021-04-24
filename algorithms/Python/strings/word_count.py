import re

test_string = '"the" is the most used word in the English language'


def word_count(s: str) -> int:
    """
    >>> word_count(test_string)
    10
    """
    s = re.sub('[^A-Za-z0-9 ]+', '', s)
    return len(s.lower().split())


def unique_word_count(s: str) -> int:
    """
    >>> unique_word_count(test_string)
    8
    """
    s = re.sub('[^A-Za-z0-9 ]+', '', s)
    return len(set(s.lower().split()))


for s in ("The Matrix", "To Be or Not to Be", "Kiss Kiss Bang Bang", test_string):
    print(s, word_count(s), unique_word_count(s))
