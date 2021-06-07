/* 
   Description : To check whether a string is anagram or not.
   Anagram: An anagram is a word or phrase formed by rearranging the letters in another word or phrase
   Approach:Using characters as array index
*/
#include<bits/stdc++.h>
using namespace std;

bool isAnagram(string s1, string s2) {
    int temp[256] = { 0 };
    for (int i = 0; i < s1.length(); i++) {         //Idea : Here we are using characters of the string as indexes.
        temp[s1[i]]++;                              //Each character(except same) will have different position allocated in the temp array      
        temp[s2[i]]--;                              //Here, characters of first string are incrementing the count at s1[i] position and characters
                                                    //of second string are decrementing the count at s2[i] position
    }
    for (int i = 0; i < 256; i++) {
        if (temp[i] > 0) {                         //If we found any index in temp array with value greater than 0 then the
            return false;                          //strings are not anagram
        }
    }
    return true;                                   //If values at all the indexes of temp array is zero, this will indicate that all characters
}                                                  //in second array cancelled the count of characters in the first array
int main() {
    string s1 ;
    string s2 ;
    cin>>s1;
    cin>>s2;
    string ans = isAnagram(s1, s2) ? "YES" : "NO";
    cout << ans << endl;
    return 0;
    //Ex :  s1= "abc" s2="abd" 
    //Output : NO
    //Time Complexity : O(n), where  n is the length of string
}
