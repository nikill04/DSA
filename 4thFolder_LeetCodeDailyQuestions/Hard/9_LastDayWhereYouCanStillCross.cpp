/* LAST DAY WHERE YOU CAN STILL CROSS : https://leetcode.com/problems/last-day-where-you-can-still-cross/description/?envType=daily-question&envId=2025-12-31

There is a 1-based binary matrix where 0 represents land and 1 represents water. You are given integers row and col representing the number of rows and columns in the matrix, respectively.

Initially on day 0, the entire matrix is land. However, each day a new cell becomes flooded with water. You are given a 1-based 2D array cells, where cells[i] = [ri, ci] represents that on the ith day, the cell on the rith row and cith column (1-based coordinates) will be covered with water (i.e., changed to 1).

You want to find the last day that it is possible to walk from the top to the bottom by only walking on land cells. You can start from any cell in the top row and end at any cell in the bottom row. You can only travel in the four cardinal directions (left, right, up, and down).

Return the last day where it is possible to walk from the top to the bottom by only walking on land cells.

 

Example 1:


Input: row = 2, col = 2, cells = [[1,1],[2,1],[1,2],[2,2]]
Output: 2
Explanation: The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 2.
Example 2:


Input: row = 2, col = 2, cells = [[1,1],[1,2],[2,1],[2,2]]
Output: 1
Explanation: The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 1.
Example 3:


Input: row = 3, col = 3, cells = [[1,2],[2,1],[3,3],[2,2],[1,1],[1,3],[2,3],[3,2],[3,1]]
Output: 3
Explanation: The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 3.
 

Constraints:

2 <= row, col <= 2 * 104
4 <= row * col <= 2 * 104
cells.length == row * col
1 <= ri <= row
1 <= ci <= col
All the values of cells are unique.                              */





// The Below is not a optimal solution. The optimal solution uses union-find data structure to solve this problem. Once, check that.
class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int left = 1;
        int right = cells.size();
        int ans = 0;

        // Binary Search on the 'Day'
        while (left <= right) {
            int midDay = left + (right - left) / 2;

            if (canCross(row, col, midDay, cells)) {
                ans = midDay;     // It's possible on this day, let's try a later day
                left = midDay + 1;
            } else {
                right = midDay - 1; // Stuck, need to try an earlier day
            }
        }
        return ans;
    }

    // Helper function to check if a path exists on a specific day
    bool canCross(int row, int col, int day, vector<vector<int>>& cells) {
        vector<vector<int>> grid(row, vector<int>(col, 0));
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        
        // Mark water cells for the current 'day'
        // Only mark cells from index 0 to day-1
        for (int i = 0; i < day; i++) {
            grid[cells[i][0] - 1][cells[i][1] - 1] = 1; 
            visited[cells[i][0] - 1][cells[i][1] - 1] = true;
        }

        // BFS Setup
        queue<pair<int, int>> q;

        // Add all valid starting points (top row land cells)
        for (int c = 0; c < col; c++) {
            if (grid[0][c] == 0) {
                q.push({0, c});
                visited[0][c] = true;
            }
        }

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            // If we reached the bottom row, return true
            if (r == row - 1) return true;

            for (int i = 0; i < 4; i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];

                if (nr >= 0 && nr < row && nc >= 0 && nc < col && 
                    !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }

        return false;
    }
};