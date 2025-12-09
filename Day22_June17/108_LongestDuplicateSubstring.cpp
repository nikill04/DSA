/* LONGEST DUPLICATE SUBSTRING : https://leetcode.com/problems/longest-duplicate-substring/description/

Given a string s, consider all duplicated substrings: (contiguous) substrings of s that occur 2 or more times. The occurrences may overlap.

Return any duplicated substring that has the longest possible length. If s does not have a duplicated substring, the answer is "".

 

Example 1:

Input: s = "banana"
Output: "ana"
Example 2:

Input: s = "abcd"
Output: ""
 

Constraints:

2 <= s.length <= 3 * 104
s consists of lowercase English letters.                    */




class Solution {
public:
    string longestDupSubstring(string s) {
        // the below helper is correct, not the optimal approach. We have to optimise it, it is taking O(n ^ 3).
        return helper(s);
    }

    string helper(string & s1) {
        string s2 = s1;
        int n = s1.size();
        
        pair<int, int> best = {0, 0};    // starting index of biggest repeated substring until now and it's length.
       
        for(int i = 0; i < n; i++) {
            if(n - i < best.second) break;

            for(int j = i + 1; j < n; j++) {
                int len = 0;

                while(j + len < n && s1[i + len] == s2[j + len]) {
                    len++;
                }

                if(len > best.second) {
                    best.first = i;
                    best.second = len;
                }
            }
        }

        return s1.substr(best.first, best.second);
    }
};