/* CONSTRUCT THE MINIMUM BITWISE ARRAY II : https://leetcode.com/problems/construct-the-minimum-bitwise-array-ii/description/?envType=daily-question&envId=2026-01-21

You are given an array nums consisting of n prime integers.

You need to construct an array ans of length n, such that, for each index i, the bitwise OR of ans[i] and ans[i] + 1 is equal to nums[i], i.e. ans[i] OR (ans[i] + 1) == nums[i].

Additionally, you must minimize each value of ans[i] in the resulting array.

If it is not possible to find such a value for ans[i] that satisfies the condition, then set ans[i] = -1.

 

Example 1:

Input: nums = [2,3,5,7]

Output: [-1,1,4,3]

Explanation:

For i = 0, as there is no value for ans[0] that satisfies ans[0] OR (ans[0] + 1) = 2, so ans[0] = -1.
For i = 1, the smallest ans[1] that satisfies ans[1] OR (ans[1] + 1) = 3 is 1, because 1 OR (1 + 1) = 3.
For i = 2, the smallest ans[2] that satisfies ans[2] OR (ans[2] + 1) = 5 is 4, because 4 OR (4 + 1) = 5.
For i = 3, the smallest ans[3] that satisfies ans[3] OR (ans[3] + 1) = 7 is 3, because 3 OR (3 + 1) = 7.
Example 2:

Input: nums = [11,13,31]

Output: [9,12,15]

Explanation:

For i = 0, the smallest ans[0] that satisfies ans[0] OR (ans[0] + 1) = 11 is 9, because 9 OR (9 + 1) = 11.
For i = 1, the smallest ans[1] that satisfies ans[1] OR (ans[1] + 1) = 13 is 12, because 12 OR (12 + 1) = 13.
For i = 2, the smallest ans[2] that satisfies ans[2] OR (ans[2] + 1) = 31 is 15, because 15 OR (15 + 1) = 31.
 

Constraints:

1 <= nums.length <= 100
2 <= nums[i] <= 109
nums[i] is a prime number.                         */





class Solution {
    // If InCase you fall in doubt => https://www.youtube.com/watch?v=RnCZCzFivl8
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n, -1);

        for(int i = 0; i < n; i++) {
            int num = nums[i];
            if(num == 2) {  // Given all are prime numbers so all the numbers has LSB as 1, But in 2 as it is even the LSB is "0". So, now according to our logic, we have to set the 1 before this "0" as "1", which is not possible. So, we consider this as special case. as we can't do according to our logic for 2, there is no number possible as required to get "2". So, for "2" answer is "-1".
                ans[i] = -1;
                continue;
            }


            for(int j = 1; j < 32; j++) { // Assuming all our integers are 32 bit ones.
                if((num & (1 << j)) > 0) continue; // For finding the first zero, once test it, then you will understand the logic.

                ans[i] = (num ^ (1 << (j - 1)));   // This is for setting the "1" before first "0" as "0". Once test it, then you will understand the logic.
                break;
            }

        }

        return ans;
    }
};