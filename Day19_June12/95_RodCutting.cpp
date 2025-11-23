/* ROD CUTTING : https://www.geeksforgeeks.org/problems/rod-cutting0840/1


Given a rod of length n inches and an array price[], where price[i] denotes the value of a piece of length i. Your task is to determine the maximum value obtainable by cutting up the rod and selling the pieces.

Note: n = size of price, and price[] is 1-indexed array.

Example:

Input: price[] = [1, 5, 8, 9, 10, 17, 17, 20]
Output: 22
Explanation: The maximum obtainable value is 22 by cutting in two pieces of lengths 2 and 6, i.e., 5 + 17 = 22.
Input: price[] = [3, 5, 8, 9, 10, 17, 17, 20]
Output: 24
Explanation: The maximum obtainable value is 24 by cutting the rod into 8 pieces of length 1, i.e, 8*price[1] = 8*3 = 24.
Input: price[] = [3]
Output: 3
Explanation: There is only 1 way to pick a piece of length 1.                        */






// User function Template for C++

class Solution {
  public:
    int cutRod(vector<int> &price) {
        // code here
        
        return helper(price);
        
    }
    
    int helper(const vector<int> &price) {

         int numLengths = price.size();   // total available piece lengths
        int rodLength = price.size();    // total rod length
        
        int pieceLengths[rodLength]; // Length array, it’s not required (we could use i directly), just for the sake of understanding purpose.
        for(int i = 0; i < rodLength; i++) 
            pieceLengths[i] = i + 1;
        
        int dp[numLengths + 1][rodLength + 1];
        /* Rows (i) → represent how many types of pieces you can use (1..i)
           Columns (j) → represent rod length you want to achieve (0..n)
        👉 dp[i][j] = maximum value you can get using pieces up to length i to make rod length j. */
        
        for (int j = 0; j <= rodLength; j++) {
            dp[0][j] = 0;
        }
        
        for (int i = 0; i <= numLengths; i++) {
            dp[i][0] = 0;
        }
        
        // dp[0][0] = 1;   No.
        /* dp[0][0]:   When i = 0, it means no pieces are available.
                        When j = 0, it means rod length = 0.

           👉  So, if you have no rod and no pieces, the maximum obtainable value is 0, not 1. There’s nothing to sell or cut — hence profit/value = 0. */
        
        for (int i = 1; i <= numLengths; i++) {
            for (int j = 1; j <= rodLength; j++) {
                if (pieceLengths[i - 1] <= j) {        // Which is nothing but "i <= j". This line means whether the current piece fits in the remaining rod of length j.
                    dp[i][j] = max(price[i - 1] + dp[i][j - pieceLengths[i - 1]], dp[i - 1][j]);
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        return dp[numLengths][rodLength];
    }
};