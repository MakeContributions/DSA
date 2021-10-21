"""
Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

You must solve the problem without using any built-in library for handling large integers (such as BigInteger). 

You must also not convert the inputs to integers directly.

Time: O(max(len(num1), len(num2)))
Space: O(max(len(num1), len(num2)) + 1)

Key points: Traverse reversely of both strings
"""

def add_string(num1, num2):
    carry = 0
    ptr1, ptr2 = len(num1) - 1, len(num2) - 1
    result = ""
    
    while ptr1 >= 0 or ptr2 >= 0 or carry:
        if ptr1 >= 0:
            carry += (ord(num1[ptr1]) - ord("0"))
            ptr1 -= 1
        if ptr2 >= 0:
            carry += (ord(num2[ptr2]) - ord('0'))
            ptr2 -= 1
        
        result = str(carry % 10) + result
        carry //= 10
    return result


if __name__ == "__main__": 
    num1 = "11"
    num2 = "123"
    result = add_string(num1, num2) #expected result  "134"

    print("First test: ",result)

    num1 = "456"
    num2 = "77"
    result = add_string(num1, num2) #expected result  "533"    
    print("Second test: ",result)