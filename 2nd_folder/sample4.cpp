/*
Given an integer x, return true if x is a palindrome, and false otherwise.

 

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 

Constraints:

-2^31 <= x <= 2^31 - 1          */



class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        else {
            vector<int> vec1;
            int y;
            int same = 1;
            for(int i = 1; x > 0; i++) {
                y = x % 10;
                vec1.push_back(y);
                x = x / 10;
            }
            y = vec1.size() / 2;
            for(auto it = vec1.end() - 1; y > 0; it--, y--) {
                if(*(vec1.begin()++) != *(it)) {
                    same = -1;
                    break;
                }
            }
            if(same == -1) return false;
            return true;
        }
    }
};