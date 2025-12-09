/* MINIMUM INSERTION STEPS TO MAKE A STRING PALINDROME : https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/

Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

 

Example 1:

Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we do not need any insertions.
Example 2:

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".
Example 3:

Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".
 

Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.                        */




class Solution {
public:
    // This problem is nothing but no. of deletions to make string a plaindrome problem. For that we have found that the LCS of string and it's reverse string. And total string length subtracted by the LCS length gave use the no. of operations(delete) to make a string palindrome. Here also it is quite same, just instead of delete that many insertion operations are required to make a string palindrome i.e., string size - length of LCS of string and it's reverse.
    int minInsertions(string s) {
        return s.size() - LCS(s);
    }

    int LCS(string & s) {
        string s1 = s;
        reverse(s1.begin(), s1.end());

        int n = s.size();

        vector<vector<int>> mat(n + 1, vector<int>(n + 1, 0));

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(s[i - 1] == s1[j - 1]) {
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