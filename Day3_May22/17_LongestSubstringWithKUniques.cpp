/*
LONGEST SUBSTRING WITH K UNIQUES: https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

Given a string s, you need to print the size of the longest possible substring with exactly k unique characters. If no possible substring exists, print -1.

Examples:

Input: s = "aabacbebebe", k = 3
Output: 7
Explanation: "cbebebe" is the longest substring with 3 distinct characters.
Input: s = "aaaa", k = 2
Output: -1
Explanation: There's no substring with 2 distinct characters.
Input: s = "aabaaab", k = 2
Output: 7
Explanation: "aabaaab" is the longest substring with 2 distinct characters.
Constraints:
1 ≤ s.size() ≤ 105
1 ≤ k ≤ 26
All characters are lowercase letters                     */


// User function template for C++

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // your code here
        int maxi = -1;
        unordered_map <char, int> ump;
        int i = 0, j = 0;
        for(int j = 0; j < s.size(); j++) {
            ump[s[j]]++;
            while(ump.size() > k) {
                ump[s[i]]--;
                if(ump[s[i]] == 0) ump.erase(s[i]);
                i++;
            }
            if(ump.size() == k) {
                // if(j - i + 1 > max) max = j - i + 1;
                maxi = max(maxi, j - i + 1);
            }
        }
        if(maxi == 0) return -1;
        else return maxi;
    }
};