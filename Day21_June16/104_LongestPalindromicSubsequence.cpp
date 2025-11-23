/* LONGEST PALINDROMIC SUBSEQUENCE : https://leetcode.com/problems/longest-palindromic-subsequence/description/

Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
 

Constraints:

1 <= s.length <= 1000
s consists only of lowercase English letters.                               */





class Solution {
public:
    // Palindrome means starting should be same as end. So, if we LCS of a string and it's reverse string we can find longest palindrome
    int longestPalindromeSubseq(string s) {
        return LCS(s);
    }

    int LCS(string s) {
        string s1 = s;
        reverse(s.begin(), s.end());

        int n = s.size();
        vector<vector<int>> mat(n + 1, vector<int>(n + 1, 0));

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(s1[i - 1] == s[j - 1]) {
                    mat[i][j] = 1 + mat[i - 1][j - 1];
                }
                else {
                    mat[i][j] = max(mat[i - 1][j], mat[i][j - 1]);
                }
            }
        }

        return mat[n][n];
    }
};