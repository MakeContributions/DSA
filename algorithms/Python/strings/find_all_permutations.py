"""
Find all the permutations of a given string
Sample inut: 'ABC'
Expected output: ['ABC', 'ACB', 'BAC', 'BCA', 'CAB', 'CBA']
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
    input = 'ABC'
    output = find_all_permutations(input)

    expected = ['ABC', 'ACB', 'BAC', 'BCA', 'CAB', 'CBA']
    assert len(output) == len(expected), f"Expected 6 permutations, got: {len(expected)}"
    for perm in expected:
        assert perm in output, f"Expected permutation {perm} to be in output, missing"
