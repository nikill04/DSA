/* Count Square Submatrices with All Ones : https://leetcode.com/problems/count-square-submatrices-with-all-ones/description/

Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

 

Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.
Example 2:

Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.
 

Constraints:

1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1                       */





class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        // int n = matrix.size();
        // int m = matrix[0].size();

        // int mini = min(n, m);

        // int ans = 0;

        // for(int i = 1; i <= mini; i++) {

        //     for(int a = 0; a <= n - i; a++) {
        //         for(int b = 0; b <= m - i; b++) {

        //             bool isBreaked = false;
        //             for(int p = a; p < a + i; p++) {
        //                 for(int q = b; q < b + i; q++) {
        //                     if(matrix[p][q] == 0) {
        //                         isBreaked = true;
        //                         break;
        //                     }
        //                 }
        //                 if(isBreaked) break;
        //             }
        //             if(!isBreaked) ans++;
        //         }
        //     }
        // }

        // return ans;


        // dp[i][j] = size of the largest square of 1s whose bottom-right corner is at (i, j)
        vector<vector<int>> dp(n, vector<int>(m, 0));

        // First column: square size depends only on matrix value
        for(int i = 0; i < n; i++) {
            dp[i][0] = matrix[i][0];
        }

        // First row: square size depends only on matrix value
        for(int j = 0; j < m; j++) {
            dp[0][j] = matrix[0][j];
        }

        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {

                // Only possible to form square if current cell is 1
                if(matrix[i][j] == 1) {

                    // Minimum of three neighbors determines square size
                    int mini = min(dp[i - 1][j - 1],
                                   min(dp[i - 1][j], dp[i][j - 1]));

                    dp[i][j] = mini + 1;
                }
                else {
                    // If cell is 0, no square can end here
                    dp[i][j] = 0;
                }
            }
        }

        // Sum of all dp values gives total number of squares
        int ans = 0;
        for(auto &row : dp) {
            for(int val : row) {
                ans += val;
            }
        }

        return ans;

    }
};