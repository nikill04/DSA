/* BURST BALLOONS : https://leetcode.com/problems/burst-balloons/description/

You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.

 

Example 1:

Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
Example 2:

Input: nums = [1,5]
Output: 10
 

Constraints:

n == nums.length
1 <= n <= 300
0 <= nums[i] <= 100                    */





class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> mat(n + 1, vector<int>(n + 1, -1));

        return dp(nums, mat, 1, n);
    }

    int dp(vector<int> & nums, vector<vector<int>> & mat, int start, int end) {
        if(start > end) return 0;

        if(mat[start][end] != -1) return mat[start][end];

        int maxi = 0;

        for(int i = start; i <= end; i++) {  // We are choosing which balloon to burst last
            
            int coins = dp(nums, mat, start, i - 1)
                      + dp(nums, mat, i + 1, end)
                      + nums[start - 1] * nums[i] * nums[end + 1];

            maxi = max(maxi, coins);
        }

        mat[start][end] = maxi;
        return maxi;
    }
};