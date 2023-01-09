"""
This program converts a string that represents a valid roman number to its decimal equivalent.
If the string is not a valid roman number, raises a ValueError exception.
Time Complexity : O(n)
Space Complexity : O(1)
"""

equivalence = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}

def is_valid_roman_string(roman_number: str) -> bool:
    """Returns True if all characters of the given string are valid roman numbers"""
    return set(roman_number).issubset(equivalence.keys())


def conversion(roman_number: str) -> int:
    """Traverses a given roman number and returns its decimal equivalent"""
    digits = len(roman_number)
    result = 0

    for i, char in enumerate(roman_number):
        if i < digits - 1 and equivalence[char] < equivalence[roman_number[i + 1]]:
            result -= equivalence[char]
        else:
            result += equivalence[char]

    return result


def roman_to_int(roman_number: str) -> int | ValueError:
    """Main function"""
    if not is_valid_roman_string(roman_number):
        raise ValueError(f'The string must contain only valid roman numbers: {equivalence.keys()}')

    return conversion(roman_number)


if __name__ == '__main__':
    print(roman_to_int('MCMXCIV'))
    # 1994
    print(roman_to_int('abc'))
    # ValueError: The string must contain only valid roman numbers: dict_keys(['I', 'V', 'X', 'L', 'C', 'D', 'M'])
