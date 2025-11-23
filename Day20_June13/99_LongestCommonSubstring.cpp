/* LONGEST COMMON SUBSTRING : https://www.geeksforgeeks.org/problems/longest-common-substring1452/1

You are given two strings s1 and s2. Your task is to find the length of the longest common substring among the given strings.

Examples:

Input: s1 = "ABCDGH", s2 = "ACDGHR"
Output: 4
Explanation: The longest common substring is "CDGH" with a length of 4.
Input: s1 = "abc", s2 = "acb"
Output: 1
Explanation: The longest common substrings are "a", "b", "c" all having length 1.
Input: s1 = "YZ", s2 = "yz"
Output: 0
Constraints:
1 <= s1.size(), s2.size() <= 103
Both strings may contain upper and lower case alphabets.                     */






class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        return tabulation(s1, s2);
    }
    
    int tabulation(string &s1, string &s2) {
        int maximum = 0;
        
        int mat[s1.size() + 1][s2.size() + 1];
        
        for(int j = 0; j <= s2.size(); j++) {
            mat[0][j] = 0;
        }
        
        for(int i = 1; i <= s1.size(); i++) {
            mat[i][0] = 0;
        }
        
        for(int i = 1; i <= s1.size(); i++) {
            for(int j = 1; j <= s2.size(); j++) {
                if(s1[i - 1] == s2[j - 1]) {
                    mat[i][j] = 1 + mat[i - 1][j - 1];
                    maximum = max(maximum, mat[i][j]);
                }
                else {
                    mat[i][j] = 0;
                }
            }
        }
        
        return maximum;
    }
};