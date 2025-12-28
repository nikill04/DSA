/* COUNT NEGATIVE NUMBERS IN A SORTED MATRIX : https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/?envType=daily-question&envId=Invalid%20Date   

Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.

 

Example 1:

Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.
Example 2:

Input: grid = [[3,2],[1,0]]
Output: 0
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 100
-100 <= grid[i][j] <= 100
 

Follow up: Could you find an O(n + m) solution?            */






class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int totNeg = 0;

        int j, i;

        for(j = m - 1; j >= 0 && grid[0][j] < 0; j--);
        j++;
        totNeg = (m - j) * n;

        for(i = n - 1; i >= 0 && grid[i][0] < 0; i--);
        i++;
        totNeg += (n - i) * (j);

        int colStart = 1;
        for(int a = i - 1; a >= 0; a--) {
            bool found = false;
            for(int b = colStart; b < j; b++) {
                if(grid[a][b] < 0) {
                    found = true;
                    
                    totNeg += j - b;
                    colStart = b;
                    break;
                }
            }

            if(found == false) break;
        }

        return totNeg;
    }
};
// This is O(n + m) solution