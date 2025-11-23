/* 
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).


Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21
 */

class Solution {
public:
    int reverse(int x) {
        int x1;
        if(x >= 0) x1 = x;
        else x1 = -1 * x;
        int i, y;
        vector<int> vec;
        for(i = 1; x1 > 0; i++) {
            y = x1 % 10;
            vec.push_back(y);
            x1 = x1 / 10;
        }
        i = i - 2;
        int z = 0;
        for(auto it = vec.begin(); it != vec.end(); it++) {
            z += *(it) * pow(10, i);
            i--;
        }
        if(x < 0) z = -1 * z;
        return z;
    }
};