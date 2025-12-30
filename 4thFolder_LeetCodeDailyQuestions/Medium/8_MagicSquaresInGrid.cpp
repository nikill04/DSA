/* MAGIC SQUARES IN GRID : https://leetcode.com/problems/magic-squares-in-grid/description/?envType=daily-question&envId=2025-12-30

A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.

Given a row x col grid of integers, how many 3 x 3 magic square subgrids are there?

Note: while a magic square can only contain numbers from 1 to 9, grid may contain numbers up to 15.

 

Example 1:


Input: grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]]
Output: 1
Explanation: 
The following subgrid is a 3 x 3 magic square:

while this one is not:

In total, there is only one magic square inside the given grid.
Example 2:

Input: grid = [[8]]
Output: 0
 

Constraints:

row == grid.length
col == grid[i].length
1 <= row, col <= 10
0 <= grid[i][j] <= 15                      */






class Solution {
public:
    /* The overall grid can have any numbers b/w 1-15, but we have to find the magic squares, which contains numbers 1-9 only. And every cell should be unique i.e., all no.'s from 1-9 must appear atleast once in that 3x3 matrix. 
    And if you figure out a simple math the sum(sum of each row, column and diagonals) always in a magic square must be equal to 15
    Because 1 + 2 + 3 + . . . + 9 = 45
    each row sum same => So, 45 / 3 = 15
    So, the sum must be equal to 15
    */
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;

        int n = grid.size();
        int m = grid[0].size();

        if(n < 3 || m < 3) return 0;

        for(int i = 0; i + 2 < n; i++) {
            for(int j = 0; j + 2 < m; j++) {
                if(helper2(grid, i, j)) {
                    ans++;
                }
            }
        }

        // helper(grid, ans, n, m); // This approach is uses set to check for uniqueness of elements in 3x3 matrix instead of vector, which is not that efficient, and significantly increases the time complexity.

        return ans;
    }

    bool helper2(vector<vector<int>> & grid, int & row, int & col) {
        vector<bool> used(10, false);

        for(int i = row; i < row + 3; i++) {
            for(int j = col; j < col + 3; j++) {
                int num = grid[i][j];
                if(used[num] || num > 9 || num < 1) {
                    return false;
                }
                used[num] = true;
            }
        }

        if( grid[row][col] + grid[row][col + 1] + grid[row][col + 2] == 15 &&
            grid[row + 1][col] + grid[row + 1][col + 1] + grid[row + 1][col + 2] == 15 &&
            grid[row + 2][col] + grid[row + 2][col + 1] + grid[row + 2][col + 2] == 15 &&
            
            grid[row][col] + grid[row + 1][col] + grid[row + 2][col] == 15 &&
            grid[row][col + 1] + grid[row + 1][col + 1] + grid[row + 2][col + 1] == 15 &&
            grid[row][col + 2] + grid[row + 1][col + 2] + grid[row + 2][col + 2] == 15 &&

            grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2] == 15 &&
            grid[row][col + 2] + grid[row + 1][col + 1] + grid[row + 2][col] == 15
        ) 
        return true;

        return false;
    }



    // void helper(vector<vector<int>> & grid, int & ans, int & n, int & m) {

    //     int a = n - 3 + 1; // no. of 3 x 3 matrices row wise
    //     int b = m - 3 + 1; // no. of 3 x 3 matrices column wise

    //     // Total (a * b) no. of,  3 x 3 matrices possible


    //     for(int i = 0; i < a; i++) {
    //         for(int j = 0; j < b; j++) {
    //             int row1, row2, row3, col1, col2, col3, diag1, diag2;
    //             row1 = row2 = row3 = col1 = col2 = col3 = diag1 = diag2 = 0;

    //             set <int> st; 
    //             bool isBreaked = false;           
    //             for(int p = i; p < i + 3; p++) {
    //                 for(int q = j; q < j + 3; q++) {
    //                     if(st.find(grid[p][q]) != st.end() || grid[p][q] > 9 || grid[p][q] < 1) {
    //                         isBreaked = true;
    //                         break;
    //                     }
    //                     st.insert(grid[p][q]);

    //                     if(p == i) row1 += grid[p][q];
    //                     else if(p == i + 1) row2 += grid[p][q];
    //                     else row3 += grid[p][q];

    //                     if(q == j) col1 += grid[p][q];
    //                     else if(q == j + 1) col2 += grid[p][q];
    //                     else col3 += grid[p][q];

    //                     if(p - i == q - j) diag1 += grid[p][q];
    //                     if(p + q - i - j == 2) diag2 += grid[p][q];
    //                 }
    //                 if(isBreaked) break;
    //             }
    //             if(!isBreaked) {
    //                 if(row1 == 15 && row2 == 15 && row3 == 15 && col1 == 15 && col2 == 15 && col3 == 15 && diag1 == 15 && diag2 == 15) {
    //                     ans++;
    //                 }
    //             }
    //         }
    //     }
    // }
};