/*
SUBSET SUM PROBLEM : https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

Given an array of positive integers arr[] and a value sum, determine if there is a subset of arr[] with sum equal to given sum. 

Examples:

Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 9
Output: true 
Explanation: Here there exists a subset with target sum = 9, 4+3+2 = 9.
Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 30
Output: false
Explanation: There is no subset with target sum 30.
Input: arr[] = [1, 2, 3], sum = 6
Output: true
Explanation: The entire array can be taken as a subset, giving 1 + 2 + 3 = 6.
Constraints:
1 <= arr.size() <= 200
1<= arr[i] <= 200
1<= sum <= 104                                    */






class Solution {
  public:
    
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        
        
        // return helper(arr, sum, arr.size());
        
        
        
        return helper2(arr, sum, arr.size());
    }
    
    
    // bool helper(vector<int> & arr, int sum, int n) {
    //     if(sum == 0) return true;
    //     if(n == 0) return false; 
        
    //     if(arr[n - 1] <= sum) {
    //         // bool val1 = helper(arr, sum - arr[n - 1], n - 1);
    //         // bool val2 = helper(arr, sum, n - 1);
            
    //         // if(val1 == true || val2 == true) return true;
            
    //         // Avoid the above way, only follow below way
            
    //         return (helper(arr, sum - arr[n - 1], n - 1) || helper(arr, sum, n - 1));
    //         // Advantage with this one is -> If the first recursive call (helper(arr, sum - arr[n - 1], n - 1)) returns true, the second call is never executed.This avoids exploring half of the recursion tree unnecessarily.
    //     } 
    //     else {
    //         return helper(arr, sum, n - 1);
    //     }
        
    //     return false;
    // }
    
    
    
    
    bool helper2(vector<int> & arr, int sum, int n) {
        bool matrix[n + 1][sum + 1];
        
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= sum; j++) {
                if(i == 0) matrix[i][j] = false;
                if(j == 0) matrix[i][j] = true;
                
                else if(i != 0 && j != 0) {
                    if(arr[i - 1] <= j) {
                        matrix[i][j] = matrix[i - 1][j - arr[i - 1]] || matrix[i - 1][j];
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