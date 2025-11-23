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
        
        // int count = 0;
        // helper(arr, target, count, arr.size());
        // return count;
        
        
        
        int count1 = helper1(arr, target, arr.size());
        return count1;
        
    }
    
    int helper1(vector<int> & arr, int target, int n) {
        int mat[n + 1][target + 1];
        
        for(int j = 0; j <= target; j++) {
            mat[0][j] = 0;  // i.e., when array is empty, you want to achieve the target with the array elements, not possible, so '0'.
        }
        
        mat[0][0] = 1;
        
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= target; j++) {
                if(arr[i - 1] <= j) {
                    mat[i][j] = mat[i - 1][j - arr[i - 1]] + mat[i - 1][j];
                }
                else {
                    mat[i][j] = mat[i - 1][j];
                }
            }
        }
        
        return mat[n][target];
    }
    
    
    
    // void helper(vector<int> & arr, int target, int & count, int n) {
    //     if(n<0){
    //         return;
    //     }
    //     if(n==0){
    //         if(target==0){
    //             count++;
    //         }
    //     }
        
        
    //     // This below works fine, if there are no zeroes in the input array.
    //     /* 
    //     if(target == 0) {
    //         count++;
    //         return;
    //     }
    //     if(n <= 0) {
    //         return;
    //     }     */
        
        
    //     if(arr[n - 1] <= target) {
    //         helper(arr, target - arr[n - 1], count, n - 1);
    //         helper(arr, target, count, n - 1);
    //     }
    //     else {
    //         helper(arr, target, count, n - 1);
    //     }
    // }
};