//Description : To check whether a string is anagram or not.
//Anagram: An anagram is a word or phrase formed by rearranging the letters in another word or phrase
#include<bits/stdc++.h>
using namespace std;

bool isAnagram(string s1, string s2) {
    int temp[256] = { 0 };
    for (int i = 0; i < s1.length(); i++) {
        temp[s1[i]]++;
        temp[s2[i]]--;

    }
    for (int i = 0; i < 256; i++) {
        if (temp[i] > 0) {
            return false;
        }
    }
    return true;
}
int main() {
    string s1 = "aab";
    string s2 = "baa";
    string ans = isAnagram(s1, s2) ? "YES" : "NO";
    cout << ans << endl;
    return 0;
    //Ex :  s1= "abc" s2="abd" 
    //Output : NO
    //Time Complexity : O(n), where  n is the length of string
}
