/*
MINIMUM SUM PARTITION : https://www.geeksforgeeks.org/problems/minimum-sum-partition3317/1

Given an array arr[]  containing non-negative integers, the task is to divide it into two sets set1 and set2 such that the absolute difference between their sums is minimum and find the minimum difference.

Examples:

Input: arr[] = [1, 6, 11, 5]
Output: 1
Explanation: 
Subset1 = {1, 5, 6}, sum of Subset1 = 12 
Subset2 = {11}, sum of Subset2 = 11 
Hence, minimum difference is 1.  
Input: arr[] = [1, 4]
Output: 3
Explanation: 
Subset1 = {1}, sum of Subset1 = 1
Subset2 = {4}, sum of Subset2 = 4
Hence, minimum difference is 3.
Input: arr[] = [1]
Output: 1
Explanation: 
Subset1 = {1}, sum of Subset1 = 1
Subset2 = {}, sum of Subset2 = 0
Hence, minimum difference is 1.                           */






class Solution {

  public:
    int minDifference(vector<int>& arr) {
        // Your code goes here
        
        // int mini = INT_MAX;
        // helper(arr, arr.size() - 1, mini, 0, 0);
        // return mini;
        
        int diff = helper1(arr);
        return diff;
    }
    
    int helper1(vector<int> & arr) {
        /*First we don't need to check for two subsets, if we consider one it is enough. Let's say total sum of the array is "Range" and sum of the two subsets are S1 and S2 respectively. 
        Now, 
        S1 + S2 = Range;
        S1 = Range - S2;
        by the question abs(S1 - S2) should be max.
        So, S1 - S2 = Range - S2 - S2;
                    = Range - 2S2             --> 1
        or Similary it can be = 2S1 - Range;  --> 2
        so, one subset or possible total sum values of one subset is enough.  Let's take equation 2. i.e., S1
        
        Now, possible S1 values ranges from [0, Range], but not all values in that interval.
        we have to get to know what values are S1 can take. For, that we will do tabulation.
        */
        int mini = INT_MAX;
        int Range = accumulate(arr.begin(), arr.end(), 0);
        bool mat[arr.size() + 1][Range + 1];
        
        for(int j = 1; j <= Range; j++) {
            mat[0][j] = false;
        }
        
        for(int i = 0; i <= arr.size(); i++) {
            mat[i][0] = true;
        }
        
        for(int i = 1; i <= arr.size(); i++) {
            for(int j = 1; j <= Range; j++) {
                if(arr[i - 1] <= j) {
                    mat[i][j] = mat[i - 1][j - arr[i - 1]] || mat[i - 1][j]; // include or exclude
                }
                else {
                    mat[i][j] = mat[i - 1][j]; // exclude
                }
            }
        }
        
        /* Now, we need to consider the last row of "mat", for what sum values are possible a subset or
        here S1, but we don't need to take all possible values from 0 to Range, only possible
        values from 0 to Range / 2 are sufficient. 
        Beacuse think, if 0 is possible, Range is possible, 
                       if 1 is possible, Range - 1 is possible.
                       like that if here one value is possible from 0, the Range - S1 is also automatically
                       possible as it automatically present in S2. 
        So, only checking from 0 to half the Range values is sufficient.
        */
        
        for(int j = 0; j <= Range / 2 + 1; j++) {
            if(mat[arr.size()][j] == true) mini = min(mini, abs(2 * j - Range));
        }
        
        return mini;
    }
    
    // void helper(vector<int>& arr, int n, int &mini, int sum1, int sum2) {
    //     if(n < 0) {
    //         mini = min(mini, abs(sum1 - sum2));
    //         return;
    //     } 
        
    //     helper(arr, n - 1, mini, sum1 + arr[n], sum2);
        
    //     helper(arr, n - 1, mini, sum1, sum2 + arr[n]);
    // }
};
