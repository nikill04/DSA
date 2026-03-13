/* HOUSE ROBBER : https://www.hackerrank.com/contests/iiits-ytp2026-1303/challenges/house-robber-42/problem

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Input Format

The first line contains an integer n — the number of houses.
The second line contains n space-separated integers representing nums[i], the amount of money in each house.
Constraints

1 <= nums.length <= 100
0 <= nums[i] <= 400
Output Format

Print a single integer representing the maximum amount of money that can be robbed without robbing two adjacent houses.
Sample Input 0

4
1 2 3 1
Sample Output 0

4
Sample Input 1

5
2 7 9 3 1
Sample Output 1

12                                              */






// void calculate(vector<int> & nums, int sum, int & ans, int ind) {
//     int n = nums.size();
//     if(ind >= n) {
//         ans = max(ans, sum);
//         return;
//     }
    
//     calculate(nums, sum, ans, ind + 1);
//     calculate(nums, sum + nums[ind], ans, ind + 2);
    
//     return;
// }

int calculate2(vector<int> & nums, vector<int> & dp, int ind) {
    
    int n = nums.size();
    
    if(ind >= n) return 0;
    
    if(dp[ind] != -1) return dp[ind];
    
    int skip = calculate2(nums, dp, ind + 1);
    int take = nums[ind] + calculate2(nums, dp, ind + 2);
    
    return dp[ind] = max(skip, take);
}


int rob(vector<int> nums) {
// BRUTE FORCE APPROACH 
//     int ans = 0;
    
//     calculate(nums, 0, ans, 0);
    
//     return ans;
    
    
// OPTIMAL APPROACH(DP)
    vector<int> dp(nums.size(), -1);
    
    return calculate2(nums, dp, 0);
    
}