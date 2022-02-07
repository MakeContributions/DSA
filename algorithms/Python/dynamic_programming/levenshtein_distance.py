# The Levenshtein distance (Edit distance) Problem

# Informally, the Levenshtein distance between two words is
# the minimum number of single-character edits (insertions, deletions or substitutions)
# required to change one word into the other.

# For example, the Levenshtein distance between kitten and sitting is 3.
# The minimal edit script that transforms the former into the latter is:

# kitten —> sitten (substitution of s for k)
# sitten —> sittin (substitution of i for e)
# sittin —> sitting (insertion of g at the end)

def levenshtein_distance(word_1, chars_1, word_2, chars_2):
    # base case if the strings are empty
    if chars_1 == 0:
        return chars_2
    if chars_2 == 0:
        return chars_1

    # if last characters of the string match, the cost of
    # operations is 0, i.e. no changes are made
    if word_1[chars_1 - 1] == word_2[chars_2 - 1]:
        cost = 0
    else:
        cost = 1

    # calculating the numbers of operations recursively
    deletion =  levenshtein_distance(word_1, chars_1 - 1, word_2, chars_2) + 1
    insertion = levenshtein_distance(word_1, chars_1, word_2, chars_2 - 1) + 1
    substitution = levenshtein_distance(word_1, chars_1 - 1, word_2, chars_2 - 1) + cost

    return min(deletion, insertion, substitution)

# driving script
if __name__ == '__main__':
    word_1 = 'plain'
    word_2 = 'plane'

    print('The Levenshtein distance is:')
    print(levenshtein_distance(word_1, len(word_1), word_2, len(word_2)))
