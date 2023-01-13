/*
Given a string s, return true if we can have a palindrome from the permutation of the input
A palindrome is a word, number, phrase, or other sequence of characters which reads the same backward as forward, such as madam or racecar.

	Time: O(n)
	Space: O(n)
*/
package strings

import( 
    "strings"  
	"fmt"
)


func canPermutePalindrome(s string) bool {
    a := strings.Split(s,"")
    dictionary := make(map[string] int)
    for _, char := range(a){
        dictionary[char]++
    }
    
    odd := 0
    for _, value := range dictionary{
        if value % 2 != 0{
            odd++
        }
    }
    return odd <= 1
}


//You are welcome to play around with the test cases
func RunPermutationCheck(){
	input1 := "carerac"

	fmt.Printf("%t for input %s \n", canPermutePalindrome(input1), input1)	//should print true

	input2 := "code"
	fmt.Printf("%t for input %s \n", canPermutePalindrome(input2), input2)	//should print false

}