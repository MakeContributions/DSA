//Description - Given two strings s and t, return true if t is an anagram of s, and false otherwise.

//Time complexity - O(n logn)

//Approach - we sort the given strings, and we compare each elements of both the strings. If we get elements which are not equal, we return false


    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        if(s.size()!=t.size()) return false;

        for(int i = 0; i<s.size();i++)
        {
            if(s[i]!=t[i]) return false;
        }
        return true;
    }
