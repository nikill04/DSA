/* Maximum Matrix Sum : https://leetcode.com/problems/maximum-matrix-sum/?envType=daily-question&envId=2026-01-05

You are given an n x n integer matrix. You can do the following operation any number of times:

Choose any two adjacent elements of matrix and multiply each of them by -1.
Two elements are considered adjacent if and only if they share a border.

Your goal is to maximize the summation of the matrix's elements. Return the maximum sum of the matrix's elements using the operation mentioned above.

 

Example 1:


Input: matrix = [[1,-1],[-1,1]]
Output: 4
Explanation: We can follow the following steps to reach sum equals 4:
- Multiply the 2 elements in the first row by -1.
- Multiply the 2 elements in the first column by -1.
Example 2:


Input: matrix = [[1,2,3],[-1,-2,-3],[1,2,3]]
Output: 16
Explanation: We can follow the following step to reach sum equals 16:
- Multiply the 2 last elements in the second row by -1.
 

Constraints:

n == matrix.length == matrix[i].length
2 <= n <= 250
-105 <= matrix[i][j] <= 105                                            */






class Solution {
public:
/*   Observation:
- Each operation flips the signs of exactly two adjacent elements.
- Hence, the parity (even/odd) of the number of negative elements never changes.
- Absolute values never change, so the maximum possible sum is the sum of absolute values.

Logic:
- If the count of negative elements is even, all negatives can be eliminated.
- If the count is odd, exactly one element must remain negative.
  To minimize loss, that negative should be the smallest absolute value.

Approach:
- Compute sum of absolute values
- Count negative elements
- Track minimum absolute value                      */

    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int noNeg = 0;  // Total no. of negative elements
        int mini = INT_MAX; // Smallest absolute value in the matrix
        long long sum = 0;

        for(vector<int> i : matrix) {
            for(int j : i) {
                if(j < 0) {
                    noNeg++;
                    sum += -j;
                    mini = min(mini, -j);
                }
                else {
                    sum += j;
                    mini = min(mini, j);
                }
            }
        }

        if(noNeg % 2 == 0) return sum;
        return sum - 2 * mini;
    }
};