/*
LETTER CASE PERMUTATION: https://leetcode.com/problems/letter-case-permutation/description/

Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string.

Return a list of all possible strings we could create. Return the output in any order.

 

Example 1:

Input: s = "a1b2"
Output: ["a1b2","a1B2","A1b2","A1B2"]
Example 2:

Input: s = "3z4"
Output: ["3z4","3Z4"]
 

Constraints:

1 <= s.length <= 12
s consists of lowercase English letters, uppercase English letters, and digits.            */


class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> vec;
        if(s == "") return vec;

        string inputString = s;
        transform(inputString.begin(), inputString.end(), inputString.begin(), ::tolower);
        string outputString = "";

        solve(inputString, outputString, vec);
        return vec;
    }

    void solve(string inputString, string outputString, vector<string> &vec) {
        if(inputString == "") {
            vec.push_back(outputString);
            return;
        }
        char ch = inputString[0];
        inputString.erase(0, 1);

        solve(inputString, outputString + ch, vec);
        if(!(int(ch) >= 48 && int(ch) <= 57)) {  // Or simply you can use isdigit(ch)
            ch = (char)toupper(ch);
            solve(inputString, outputString + ch, vec);
        }
    }
};