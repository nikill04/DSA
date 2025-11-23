/* COIN CHANGE : https://leetcode.com/problems/coin-change/description/


You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0                                          */





class Solution {
public:
    #define INF INT_MAX - 1  
    // Defining infinity.

    int coinChange(vector<int>& coins, int amount) {
        return helper(coins, amount);
    }

    int helper(vector<int> & coins, int amount) {
        int mat[coins.size() + 1][amount + 1];

        for(int i = 0; i <= coins.size(); i++) {
            mat[i][0] = 0;   // as no coins requried to make sum "0". even if we have any no. of any denomination coins.
        }

        for(int j = 1; j <= amount; j++) {
            mat[0][j] = INF;  // That means with a coin 0, how much we try, we can't make that j. So. let's assume we reach that sum at infinite coin.
        }

        for(int j = 1; j <= amount; j++) {
            if(j % coins[0] == 0) mat[1][j] = j / coins[0];
            else mat[1][j] = INF;
        }

        for(int i = 2; i <= coins.size(); i++) {
            for(int j = 1; j <= amount; j++) {
                if(coins[i - 1] <= j) {
                    mat[i][j] = min(1 + mat[i][j - coins[i - 1]], mat[i - 1][j]); // either taking one coin of that denomination and staying there again or either rejecting that coin.
                    // Here we are doing "+ 1" in the first part, that's why we took INF as INT_MAX - 1, if we have taken as INT_MAX when doing "+ 1", it will go out of bounds and gives wrong output.
                }
                else {
                    mat[i][j] = mat[i - 1][j];
                }
            }
        }

        if(mat[coins.size()][amount] == INF) return -1; 
        else return mat[coins.size()][amount];
    }
};