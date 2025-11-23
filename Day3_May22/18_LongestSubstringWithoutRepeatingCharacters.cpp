/*
LONGEST SUBSTRING WITHOUT REPEATING CHARACTERS: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

Given a string s, find the length of the longest substring without duplicate characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.                     */



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxi = 0;
        unordered_set<char> uset;
        int i = 0;
        for(int j = 0; j < s.size(); j++) {
            if(uset.find(s[j]) != uset.end()) {
                while(s[i] != s[j]) {
                    uset.erase(s[i]);                    
                    i++;
                }
                uset.erase(s[i]);
                i++;
            }
            // while (uset.find(s[j]) != uset.end()) {
            //     uset.erase(s[i]);
            //     i++;
            // }


            
            uset.insert(s[j]);
            maxi = max(maxi, j - i + 1);
        } 
        return maxi;
    }
};



/* 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int n = s.length();   //n holds a value that is equal to the length of string s
      int maxLen = 0;   //initializing a variable that will hold the max length value
      vector<int> charIndex(128, -1); //allows for 128 integers all set to -1
      int left = 0; //counts how many characters are to the left of the current index

      for(int right = 0; right < n; right++){
        //counts how many characters are left until reaching the entire length of the string
        //the right variable acts as an iterator

        if(charIndex[s[right]] >= left){
            //left checks to see if the current character has already occurred by comparing to the current index
            left = charIndex[s[right]] + 1;
            //if the character has occurred, update charIndex
        }

        charIndex[s[right]] = right;
        maxLen = max(maxLen, right - left + 1);
      }  

      return maxLen;
    }
};                    */