/* IS SUBSEQUENCE : https://leetcode.com/problems/is-subsequence/description/

Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

 

Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false
 

Constraints:

0 <= s.length <= 100
0 <= t.length <= 104
s and t consist only of lowercase English letters.
 

Follow up: Suppose there are lots of incoming s, say s1, s2, ..., sk where k >= 109, and you want to check one by one to see if t has its subsequence. In this scenario, how would you change your code?            */




class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(t.size() < s.size()) return false;

        // return helper(s, t) == s.size();

        // Can also be simply done using two pointer approach
        return helper2(s, t);
    }

    bool helper2(string & s, string & t) {
        int n = s.size();
        int m = t.size();

        int j = 0; 

        int k = 0; // Just for remembering the index the big string, from where we have to start in the next iteration(i.e., for next character in small string).
        /* Simple example for the above: 
        s = "abc"
        t - "dbeazc" ,
        t also contains s, but in wrong order, if we start from 0 every time j for loop, we will get wrong answer*/

        for(int i = 0; i < n; i++) {
            for(j = k; j < m; j++) {
                if(s[i] == t[j]) {
                    k = j + 1;
                    break;
                }
            }
            if(j == m || s[i] != t[j]) return false;
        }

        return true;
    }

    // int helper(string & s, string & t) {
    //     int n = s.size();
    //     int m = t.size();

    //     vector<vector<int>> mat(n + 1, vector<int>(m + 1, 0));

    //     for(int i = 1; i <= n; i++) {
    //         for(int j = 1; j <= m; j++) {
    //             if(s[i - 1] == t[j - 1]) {
    //                 mat[i][j] = 1 + mat[i - 1][j - 1];
    //             }
    //             else {
    //                 mat[i][j] = max(mat[i - 1][j], mat[i][j - 1]);
    //             }
    //         }
    //     }

    //     return mat[n][m];
    // }
};