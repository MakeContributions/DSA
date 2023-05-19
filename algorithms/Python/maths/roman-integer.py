# Topic - Maths
# Language - Python
# Problem - Convert integer to roman number and vice-versa.

class RomanNumeralConverter:
    def __init__(self):
        self.integer_to_roman_mapping = [
            (1000, 'M'),
            (900, 'CM'),
            (500, 'D'),
            (400, 'CD'),
            (100, 'C'),
            (90, 'XC'),
            (50, 'L'),
            (40, 'XL'),
            (10, 'X'),
            (9, 'IX'),
            (5, 'V'),
            (4, 'IV'),
            (1, 'I')
        ]

    def integer_to_roman(self, num):
        roman = ''
        for value, symbol in self.integer_to_roman_mapping:
            while num >= value:
                roman += symbol
                num -= value
        return roman

    def roman_to_integer(self, roman):
        integer = 0
        i = 0
        while i < len(roman):
            current_symbol = roman[i]
            for value, symbol in self.integer_to_roman_mapping:
                if roman[i:i+len(symbol)] == symbol:
                    integer += value
                    i += len(symbol)
                    break
        return integer


converter = RomanNumeralConverter()

# Convert integer to Roman numeral
integer = 123
roman = converter.integer_to_roman(integer)
print(f"Roman numeral for {integer}: {roman}")

# Convert Roman numeral to integer
roman_numeral = "XXVII"
converted_integer = converter.roman_to_integer(roman_numeral)
print(f"Integer for {roman_numeral}: {converted_integer}")
