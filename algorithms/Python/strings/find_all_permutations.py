"""
Find all the permutations of a given string
"""

def permutation(head, left, permutations):
    if len(left) == 0:
        permutations.append(head)
    else:
        for i in range(len(left)):
            permutation(head+left[i], left[:i]+left[i+1:], permutations)

def find_all_permutations(string):
    permutations = []
    permutation('', string, permutations)
    return permutations

if __name__ == "__main__": 
    print(find_all_permutations('AB'))