/*
PERFECT SUM PROBLEM : https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1

Given an array arr of non-negative integers and an integer target, the task is to count all subsets of the array whose sum is equal to the given target.

Examples:

Input: arr[] = [5, 2, 3, 10, 6, 8], target = 10
Output: 3
Explanation: The subsets {5, 2, 3}, {2, 8}, and {10} sum up to the target 10.
Input: arr[] = [2, 5, 1, 4, 3], target = 10
Output: 3
Explanation: The subsets {2, 1, 4, 3}, {5, 1, 4}, and {2, 5, 3} sum up to the target 10.
Input: arr[] = [5, 7, 8], target = 3
Output: 0
Explanation: There are no subsets of the array that sum up to the target 3.
Input: arr[] = [35, 2, 8, 22], target = 0
Output: 1
Explanation: The empty subset is the only subset with a sum of 0.                    */





    class Solution {
    public:
    
        int perfectSum(vector<int>& arr, int target) {
            // code here
            int n = arr.size();
            
            
        // APPROACH-1(BRUTE FORCE)
            // int count = 0;
            // helper(arr, target, count, n);
            // return count;
            
            
        // APPROACH-2(OPTIMAL(recursion))
            // vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
            // return helper2(arr, target, dp, n);
            
            
        // APPROACH-3(OPTIMAL(TABULATION))
            int count3 = helper3(arr, target, n);
            return count3;
            
        }
        
        int helper3(vector<int> & arr, int target, int n) {
            int mat[n + 1][target + 1];
            
            // mat[i][j] = Number of subsets that give sum = j using first i elements
            for(int j = 0; j <= target; j++) {
                mat[0][j] = 0;  // i.e., when array is empty, you want to achieve the target with the array elements, not possible, so '0'.
            }
            
            mat[0][0] = 1;
            
            for(int i = 1; i <= n; i++) {
                for(int j = 0; j <= target; j++) {
                    if(arr[i - 1] <= j) {
                        int take = mat[i - 1][j - arr[i - 1]];
                        int notTake = mat[i - 1][j];
                        mat[i][j] = take + notTake;
                    }
                    else {
                        mat[i][j] = mat[i - 1][j]; // Not Take
                    }
                }
            }
            
            return mat[n][target];
        }
        
        
        
        void helper(vector<int> & arr, int target, int & count, int n) {
            if(n<0){
                return;
            }
            if(n==0){
                if(target==0){
                    count++;
                }
            }
            
            
            // This below works fine, if there are no zeroes in the input array.
            /* 
            if(target == 0) {
                count++;
                return;
            }
            if(n <= 0) {
                return;
            }     */
            
            
            if(arr[n - 1] <= target) {
                helper(arr, target - arr[n - 1], count, n - 1);
                helper(arr, target, count, n - 1);
            }
            else {
                helper(arr, target, count, n - 1);
            }
        }
        
        int helper2(vector<int> & arr, int target, vector<vector<int>> & dp, int n) {
            if(n == 0) {
                if(target == 0) 
                    return 1;
                return 0;
            }
            
            if(dp[n][target] != -1) return dp[n][target];
            
            int a, b = 0;
            if(arr[n - 1] <= target) {
                a = helper2(arr, target, dp, n - 1);
                b = helper2(arr, target - arr[n - 1], dp, n - 1);
            }
            else {
                a = helper2(arr, target, dp, n - 1);
            }
        
            return dp[n][target] = a + b;
        }
    };