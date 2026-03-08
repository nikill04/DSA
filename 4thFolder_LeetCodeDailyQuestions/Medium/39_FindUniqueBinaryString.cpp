/* FIND UNIQUE BINARY STRING : https://leetcode.com/problems/find-unique-binary-string/description/?envType=daily-question&envId=2026-03-08

Given an array of strings nums containing n unique binary strings each of length n, return a binary string of length n that does not appear in nums. If there are multiple answers, you may return any of them.

 

Example 1:

Input: nums = ["01","10"]
Output: "11"
Explanation: "11" does not appear in nums. "00" would also be correct.
Example 2:

Input: nums = ["00","01"]
Output: "11"
Explanation: "11" does not appear in nums. "10" would also be correct.
Example 3:

Input: nums = ["111","011","001"]
Output: "101"
Explanation: "101" does not appear in nums. "000", "010", "100", and "110" would also be correct.
 

Constraints:

n == nums.length
1 <= n <= 16
nums[i].length == n
nums[i] is either '0' or '1'.
All the strings of nums are unique.                       */






class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        int stringSize = nums[0].size();

        int n1 = pow(2, stringSize);

        vector<int> vec(n1, -1);

        for(int i = 0; i < n; i++) {
            int value = 0;

            int placeValue = 0;
            for(int j = stringSize - 1; j >= 0; j--) {
                if(nums[i][j] != '0') value += pow(2, placeValue);
                placeValue++;
            }

            vec[value] = 1;
        }

        string answer(stringSize, '0');
        for(int i = 0; i < n1; i++) {
            if(vec[i] == -1) {
                if(i == 0) {
                    return answer;
                }

                int pos = stringSize - 1;
                while(i >= 1) {
                    answer[pos--] = (i % 2) + '0';
                    i = i / 2;
                }

                break;
            }
        }

        return answer;
    }
};