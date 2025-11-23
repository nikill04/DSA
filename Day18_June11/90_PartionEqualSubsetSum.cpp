/*
SUBSET SUM PROBLEM : https://www.geeksforgeeks.org/problems/subset-sum-problem2014/1

Given an array arr[], determine if it can be partitioned into two subsets such that the sum of elements in both parts is the same.

Note: Each element must be in exactly one subset.

Examples:

Input: arr = [1, 5, 11, 5]
Output: true
Explanation: The two parts are [1, 5, 5] and [11].
Input: arr = [1, 3, 5]
Output: false
Explanation: This array can never be partitioned into two such parts.
Constraints:
1 ≤ arr.size ≤ 100
1 ≤ arr[i] ≤ 200           */





class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        // code here
        
        // first if the total sum of the array is odd then it can't be divided into two subsets, so we have to check when the total sum is even otherwise not.
        // and then if we check for the totalSUM / 2 is present then definitely other subset will also have the same sum. 
        // so, basically it is SUBSET SUM PROBLEM only.
        
        int sum = 0;
        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i];
        }
        
        if(sum % 2 != 0) return false;
        
        return helper(arr, sum / 2, arr.size());
    }
    
    bool helper(vector<int> & arr, int sum, int n) {
        bool matrix[n + 1][sum + 1];
        
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= sum; j++) {
                if(i == 0) matrix[i][j] = false;
                if(j == 0) matrix[i][j] = true;
                
                else if(i != 0 && j != 0) {
                    if(arr[i - 1] <= j) {
                        matrix[i][j] = (matrix[i - 1][j - arr[i - 1]] || matrix[i - 1][j]);
                    } 
                    else {
                        matrix[i][j] = matrix[i - 1][j];
                    }
                }
            }
        }
        
        return matrix[n][sum];
    }
};