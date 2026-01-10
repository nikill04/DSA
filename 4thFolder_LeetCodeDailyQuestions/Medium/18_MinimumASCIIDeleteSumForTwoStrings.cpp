/* MINIMUM ASCII DELETE SUM FOR TWO STRINGS : https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/submissions/1880722237/?envType=daily-question&envId=2026-01-10

Given two strings s1 and s2, return the lowest ASCII sum of deleted characters to make two strings equal.

 

Example 1:

Input: s1 = "sea", s2 = "eat"
Output: 231
Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
Deleting "t" from "eat" adds 116 to the sum.
At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.
Example 2:

Input: s1 = "delete", s2 = "leet"
Output: 403
Explanation: Deleting "dee" from "delete" to turn the string into "let",
adds 100[d] + 101[e] + 101[e] to the sum.
Deleting "e" from "leet" adds 101[e] to the sum.
At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.
 

Constraints:

1 <= s1.length, s2.length <= 1000
s1 and s2 consist of lowercase English letters.                   */






class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int ans = 0;
        string str = "";

        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> mat(n + 1, vector<int>(m + 1, 0));

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(s1[i - 1] == s2[j - 1]) {
                    mat[i][j] = s1[i - 1] + mat[i - 1][j - 1];
                    
                }
                else {
                    mat[i][j] = max(mat[i - 1][j], mat[i][j - 1]);
                }
            }
        }

        int sum1 = 0;
        int sum2 = 0;

        for(char c : s1) {
            sum1 += c;
        }
        for(char c : s2) {
            sum2 += c;
        }

        ans = (sum1 - mat[n][m]) + (sum2 - mat[n][m]);

        return ans;
    }
};