/* COIN CHANGE : https://www.geeksforgeeks.org/problems/coin-change2448/1



Given an integer array coins[ ] representing different denominations of currency and an integer sum, find the number of ways you can make sum by using different combinations from coins[ ]. 
Note: Assume that you have an infinite supply of each type of coin. Therefore, you can use any coin as many times as you want.
Answers are guaranteed to fit into a 32-bit integer. 

Examples:

Input: coins[] = [1, 2, 3], sum = 4
Output: 4
Explanation: Four Possible ways are: [1, 1, 1, 1], [1, 1, 2], [2, 2], [1, 3].
Input: coins[] = [2, 5, 3, 6], sum = 10
Output: 5
Explanation: Five Possible ways are: [2, 2, 2, 2, 2], [2, 2, 3, 3], [2, 2, 6], [2, 3, 5] and [5, 5].
Input: coins[] = [5, 10], sum = 3
Output: 0
Explanation: Since all coin denominations are greater than sum, no combination can make the target sum.           */






class Solution {
  public:
    int count(vector<int>& coins, int sum) {
        // code here.
        
        return helper(coins, sum);
    }
    
    int helper(vector<int> & coins, int sum) {
        int mat[coins.size() + 1][sum + 1];
        
        for(int j = 1; j <= sum; j++) {
            mat[0][j] = 0;
        }
        
        for(int i = 0; i <= coins.size(); i++) {
            mat[i][0] = 1;
        }
    
        for(int i = 1; i <= coins.size(); i++) {
            for(int j = 1; j <= sum; j++) {
                if(coins[i - 1] <= j) {
                    mat[i][j] = mat[i][j - coins[i - 1]] + mat[i - 1][j];
                }
                else {
                    mat[i][j] = mat[i - 1][j];
                }
            }
        }
        
        return mat[coins.size()][sum];
    }
};