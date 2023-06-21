#  An optimal approach to generate all prime numbers less than given value

def sieveOfEratosthens(R):

    if R == 1:
        return []

    answer = [2]  # initialize the array with first prime number

    for i in range(3,R,2): #we run a for loop from 3 to range because all prime numbers after 2 are odd
        result = True
        for j in answer: # we check if current number has any prime factors which are less tha itself
            if j % i == 0:
                result = False #if we find any number having factor we mark it false

        if result: # if something is not marked false then
            answer.append(i) # add the value to prime numbers because it has no prime factors

    return answer

# Time Complexity: O(n*log(log(n)))
# Auxiliary Space: O(n)

# to use this function use below approach where you pass range till which you want prime number
# print(sieveOfEratosthens(20)) -> [2, 3, 5, 7, 9, 11, 13, 15, 17, 19]
# print(sieveOfEratosthens(40)) -> [2, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39]




