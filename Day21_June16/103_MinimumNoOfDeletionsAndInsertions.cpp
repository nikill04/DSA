/* MINIMUM NO OF DELETIONS AND INSERTIONS : https://www.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1

Given two strings s1 and s2. The task is to remove or insert the minimum number of characters from/in s1 to transform it into s2. It could be possible that the same character needs to be removed from one point of s1 and inserted into another point.

Examples :

Input: s1 = "heap", s2 = "pea"
Output: 3
Explanation: 'p' and 'h' deleted from heap. Then, 'p' is inserted at the beginning.
Input : s1 = "geeksforgeeks", s2 = "geeks"
Output: 8
Explanation: 8 deletions, i.e. remove all characters of the string "forgeeks".
Constraints:
1 ≤ s1.size(), s2.size() ≤ 1000
All the characters are lowercase English alphabets.                 */





class Solution {

  public:
    int minOperations(string &s1, string &s2) {
        // Your code goes here
        
        int LCSlength = LCS(s1, s2);
        
        int n1 = s1.size() - LCSlength; // This, i.e., n1 operations we have to minus
        int n2 = s2.size() - LCSlength; // This, i.e., n2 operations we have to add
        
        return n1 + n2;
    }
    
    int LCS(string & s1, string & s2) {
        int n = s1.size();
        int m = s2.size();
        
        vector<vector<int>> mat(n + 1, vector<int>(m + 1, 0));
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(s1[i - 1] == s2[j - 1]) {
                    mat[i][j] = 1 + mat[i - 1][j - 1];
                }
                else {
                    mat[i][j] = max(mat[i - 1][j], mat[i][j - 1]);
                }
            }
        }
        
        return mat[n][m];
    }
};