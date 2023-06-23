'''
Output the correct Roman numerals for a given number.

This will only give accurate roman numerals up to 3,999. Anything higher starts to combine the addition method along with the traditional method.
Numbers higher than 3,999 need to show a line above a roman numeral to say that it is 1,000 times that number. ie: V(with the line above) would be 5,000. 

Input: 1994
Output: MCMXCIV

Time Complexity: O(1)
Space Complexity: O(1)
'''


def int_to_roman(num):
  reference = [("M", 1000), ("CM", 900), ("D", 500), ("CD", 400), ("C", 100), ("XC", 90), ("L", 50), ("XL", 40), ("X", 10), ("IX", 9), ("V", 5), ("IV", 4), ("I", 1)]
  remainder = num
  romans = ""

  for i in range(len(reference)):
    quotient = int(remainder / reference[i][1])
    remainder = remainder % reference[i][1]
    romans += reference[i][0] * quotient
  
  return romans


if __name__ == "__main__":
  
  print(int_to_roman(3999))
  # MMMDXLIX