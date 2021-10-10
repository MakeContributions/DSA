package Strings;

import java.util.HashMap;


//Given two equal-size strings s and t. In one step you can choose any character of t and replace it with another character.
//Return the minimum number of steps to make t an anagram of s.
//An Anagram of a string is a string that contains the same characters with a different (or the same) ordering.

public class anagram {
    public static void main(String[] args) {
        String s = "leetcode";
        String t = "practice";
        System.out.println(minSteps(s, t));
        System.out.println(minSteps2(s, t));

    }


    //1st solution
    private static int minSteps(String s, String t) {
        HashMap<Integer, Character> map = new HashMap<>();
        char[] charS = s.toCharArray();
        char[] charT = t.toCharArray();

        for (int i = 0; i < charT.length; i++) {
            map.put(i, charT[i]);
        }

        for (char aChar : charS) {
            if (map.containsValue(aChar)) {
                map.values().remove(aChar);
            }
        }

        return map.size();
    }

    //2nd solution better and fast
    private static int minSteps2(String s, String t) {
        int n = s.length();
        int ans = 0;
        int[] count = new int[26];//always keep in mind (26) when doing a string question
        for (int i = 0; i < n; i++) {
            count[s.charAt(i) - 'a']++;
            count[t.charAt(i) - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0)
                ans += count[i];
        }
        return ans;
    }
}

