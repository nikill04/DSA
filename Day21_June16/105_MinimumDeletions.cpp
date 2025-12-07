/* MINIMUM DELETIONS : https://www.geeksforgeeks.org/problems/minimum-deletitions1648/1 

Given a string s, write a program to delete the minimum number of characters from the string so that the resultant string is a palindrome, while maintaining the order of characters.

Examples:

Input: s = "aebcbda"
Output: 2
Explanation: Remove characters 'e' and 'd'.
Input: s = "geeksforgeeks"
Output: 8
Explanation: To make "geeksforgeeks" a palindrome, the longest palindromic subsequence is "eefee" (length 5). The minimum deletions are:
13 (length of s) - 5 = 8.
Constraints:
1 ≤ s.size() ≤ 103                           */





class Solution {
  public:
    // Palindrome means starting should be same as end. So, if we LCS of a string and it's reverse string we can find longest palindrome
    int minDeletions(string s) {
        // code here
        int LCSlength = LCS(s);
        
        return s.size() - LCSlength;
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