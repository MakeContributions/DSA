/**
Problem Statement: Given two strings s and t, find they are anagrams or not
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1: Input: s="anagram" t="nagaram"
		   Output: true

Example 2: Input: s="rat" t="car"
		   Output: false

Time complexity: O(n), n=length of string s
Space complexity: O(1)

**/

package strings

import "fmt"

func RunIsAnagram() {
	fmt.Println("Enter first string")
	var first string
	fmt.Scanln(&first)
	fmt.Println("Enter second string")
	var second string
	fmt.Scanln(&second)
	ans := isAnagram(first, second)
	if ans == true {
		fmt.Println("They are anagrams")
	} else {
		fmt.Println("They are not anagrams")
	}
}

func isAnagram(s string, t string) bool {
	var count [256]int

	for i := 0; i < len(s); i++ {
		count[s[i]]++
	}
	for i := 0; i < len(t); i++ {
		count[t[i]]--
	}
	for i := 0; i < len(count); i++ {
		if count[i] != 0 {
			return false
		}
	}
	return true
}
