/* LONGEST COMMON SUBSEQUENCE : http://leetcode.com/problems/longest-common-subsequence/description/

Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.                 

Constraints:

1 <= text1.length, text2.length <= 1000
text1 and text2 consist of only lowercase English characters.                     */





class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // The below two are recursive approaches, but one of the main problems in recursive approaches is, in the recursive tree, we will encounter repeated subproblems. i.e., eventhough we calculated for one subproblem, we will again see the same subproblem appear in the tree, for which we again calculate.
        // return recursion1(text1, text2);

        // return recursion2(text1, text1.size(), text2, text2.size());





        // Now Memorization Approach.
        // int mat[1001][1001];           // As constraint "1 <= text1.length, text2.length <= 1000"
        // // return memorization(text1, text1.size(), text2, text2.size(), mat);
        // for(int i = 0; i <= 1000; I++) {
        //     for(int j = 0; j <= 1000; j++) {
        //         mat[i][j] = -1;
        //     }
        // }
        // return memorization1(text1, text1.size(), text2, text2.size(), mat); 
        // // function arguments will be "int memorization1(string &str1, int n, string &str2, int m, int &(mat)[1001][1001]) { }"

        // vector<vector<int>> mat(text1.size() + 1, vector<int>(text2.size() + 1, -1));
        // memorization(text1, text1.size(), text2, text2.size(), mat);
        // return mat[text1.size()][text2.size()];




        // Now Tabulation Approach.
        return tabulation(text1, text2);
    }





    int tabulation(string & str1, string & str2) {
        int mat[str1.size() + 1][str2.size() + 1];

        for(int j = 0; j <= str2.size(); j++) {
            mat[0][j] = 0;  // i.e., with one of the strings being empty string, the longest common subsequence will also empty i.e., common subsequence length 0.
        }

        for(int i = 1; i <= str1.size(); i++) {
            mat[i][0] = 0;  // same as above reason.
        }

        for(int i = 1; i <= str1.size(); i++) {
            for(int j = 1; j <= str2.size(); j++) {
                if(str1[i - 1] == str2[j - 1]) {
                    mat[i][j] = 1 + mat[i - 1][j - 1];
                }
                else {
                    mat[i][j] = max(mat[i - 1][j], mat[i][j - 1]);
                }
            }
        }

        return mat[str1.size()][str2.size()];
    }






    // void memorization(string & str1, int n, string & str2, int m, vector<vector<int>> &mat) {
    //     if(n == 0 || m == 0) {
    //         mat[n][m] = 0;
    //         return;
    //     }

    //     if(mat[n][m] != -1) return;

    //     if(str1[n - 1] == str2[m - 1]) {
    //         memorization(str1, n - 1, str2, m - 1, mat);
    //         mat[n][m] = 1 + mat[n - 1][m - 1];
    //         return;
    //     }
    //     else {
    //         memorization(str1, n - 1, str2, m, mat);
    //         memorization(str1, n, str2, m - 1, mat);

    //         mat[n][m] = max(mat[n - 1][m], mat[n][m - 1]);
    //         return;
    //     }
    // }





    // int recursion2(string & str1, int n, string & str2, int m) {
    //     if(n == 0 || m == 0) return 0;

    //     if(str1[n - 1] == str2[m - 1]) {
    //         return (1 + recursion2(str1, n - 1, str2, m - 1));
    //     }
    //     else {
    //         return max(recursion2(str1, n - 1, str2, m), recursion2(str1, n, str2, m - 1));
    //     }
    // }






    // int recursion1(string text1, string text2) {
    //     if(text1.size() == 0 || text2.size() == 0) return 0;

    //     if(text1[text1.size() - 1] == text2[text2.size() - 1]) {
    //         text1.erase(text1.end() - 1);
    //         text2.erase(text2.end() - 1);

    //         return 1 + recursion1(text1, text2);
    //     }
    //     else {
    //         string str1 = text1.substr(0, text1.size() - 1);
    //         string str2 = text2.substr(0, text2.size() - 1);
    //         return max(recursion1(str1, text2), recursion1(text1, str2));
    //     }
    // }
};