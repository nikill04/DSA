/* SHORTEST COMMON SUPERSEQUENCE : https://leetcode.com/problems/shortest-common-supersequence/description/

Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

 

Example 1:

Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.
Example 2:

Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
Output: "aaaaaaaa"
 

Constraints:

1 <= str1.length, str2.length <= 1000
str1 and str2 consist of lowercase English letters.                        */






class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        return helper(str1, str2);
    }

    string helper(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> mat(n + 1, vector<int>(m + 1, 0));

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(str1[i - 1] == str2[j - 1]) {
                    mat[i][j] = 1 + mat[i - 1][j - 1];
                } 
                else {
                    mat[i][j] = max(mat[i - 1][j], mat[i][j - 1]);
                }
            }
        }

        string str = "";
        int i = n;
        int j = m;

        while(i > 0 && j > 0) {
            if(str1[i - 1] == str2[j - 1]) {
                str += str1[i - 1];
                i--;
                j--;
            }
            // The Longest Common Subsequence (LCS) tells us the characters that both strings already share in order.
            // If we follow that shared path while merging, we don’t repeat those letters twice.
            /*  When characters differ (str1[i-1] != str2[j-1]), we can:
                    1. skip a letter from str1 (move up → dp[i-1][j])
                    2. or skip a letter from str2 (move left → dp[i][j-1])
                Each direction brings us closer to the LCS path in a different way.
                    1. If dp[i-1][j] is bigger, that means:
                        "By moving up (skipping str1[i-1]), we get a longer LCS — so the better path is above."
                        So we take the character from str1 now (since we’ll lose it otherwise), and move up (i--).          */
            else if(mat[i - 1][j] > mat[i][j - 1]) {
                str += str1[--i];
            }
            else {
                str += str2[--j];
            }
        }

        while(i > 0) {
            str += str1[--i];
        }
        while(j > 0) {
            str += str2[--j];
        }

        reverse(str.begin(), str.end());

        return str;
    }
};