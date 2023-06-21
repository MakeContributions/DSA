'''
Output the correct Roman numerals for a given number.

Input: 1994
Output: MCMXCIV
        MDCD

Time Complexity: ???
Space Complexity: ???
'''


def int_to_roman(num):
  reference = [("M", 1000), ("CM", 900), ("D", 500), ("CD", 400), ("C", 100), ("XC", 90), ("L", 50), ("XL", 40), ("X", 10), ("IX", 9), ("V", 5), ("IV", 4), ("I", 1)]

  for numeral in range(len(reference)):
    if numeral[1]:
      ...

if __name__ == "__main__":
  
  print(int_to_roman(1994))
  # MCMXCIV