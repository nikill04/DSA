/* PALINDROME PARTITIONING II : https://leetcode.com/problems/palindrome-partitioning-ii/description/

Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

 

Example 1:

Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
Example 2:

Input: s = "a"
Output: 0
Example 3:

Input: s = "ab"
Output: 1
 

Constraints:

1 <= s.length <= 2000
s consists of lowercase English letters only.              */






class Solution {
public:
    int minCut(string s) {

        vector<int> dp(s.size(), -1);

        return helper(s, 0, dp);
    }

    int helper(string & s, int start, vector<int> & dp) {
        if(isPalindrome(start, s.size() - 1, s)) return 0;

        if(dp[start] != -1) return dp[start];

        int ans = INT_MAX;

        for(int i = start; i < s.size() - 1; i++) {
            int noOfCuts = INT_MAX;

            if(isPalindrome(start, i, s)) {
                noOfCuts = 1 + helper(s, i + 1, dp  );
            }

            ans = min(noOfCuts, ans);
        }

        return dp[start] = ans;
    }

    bool isPalindrome(int start, int end, string & s) {

        while(start < end) {
            if(s[start++] != s[end--]) return false;
        }

        return true;
    }
};