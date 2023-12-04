"""
Algorithm name: Group Anagrams
Algorithm Type: grouping values in an array
Explain: Given an array of strings strs, group the anagrams together.
    An Anagram is a word or phrase formed by rearranging the letters
    of a different word or phrase, typically using all the original
    letters exactly once.
Time Complexity: O(m*n) where m is the number of strings given
                        and n is the average len of each string

Example 1:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Example 2:
Input: strs = [""]
Output: [[""]]

Example 3:
Input: strs = ["a"]
Output: [["a"]]

[Leetcode question #49](https://leetcode.com/problems/group-anagrams/)
[Neetcode Solution](https://youtu.be/vzdNOK2oB2E?si=S2hFg0sbMiRx7JRc)
"""

from collections import defaultdict
strs = ["eat", "tea", "tan", "ate", "nat", "bat"]


def groupAnagrams(strs):
    res = defaultdict(list)

    for s in strs:
        count = [0] * 26  # a ... z
        for c in s:
            count[ord(c) - ord("a")] = + 1

        res[tuple(count)].append(s)

    return res.values()


if __name__ == "__main__":
    print(groupAnagrams(strs))
