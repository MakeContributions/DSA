# This function takes in two binary strings and returns their sum as a binary string

def addBinary(a, b):
    result = ""
    i = len(a) - 1
    j = len(b) - 1

    carry = 0
    while i >= 0 or j >= 0:
        sum = carry
        if i >= 0:
            sum += ord(a[i]) - ord('0')
        if j >= 0:

            sum += ord(b[j]) - ord('0')
        i = i - 1
        j = j - 1
        carry = 1 if sum > 1 else 0
        result += str(sum % 2)

    if carry != 0:
        result += str(carry)
    return result[::-1]


if __name__ == '__main__':
    print(addBinary("11", "1"))
    print(addBinary("1010", "1011"))

