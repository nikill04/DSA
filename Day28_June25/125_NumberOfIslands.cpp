/* NUMBER OF ISLANDS : https://leetcode.com/problems/number-of-islands/description/

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.                      */





class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        queue<pair<int, int>> q;

        int ans = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1' && !visited[i][j]) {
                    q.push({i, j});
                    visited[i][j] = true;
                    
                    while(!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();

                        int xTrav[] = {0, 0, -1, 1};
                        int yTrav[] = {-1, 1, 0, 0};

                        for(int k = 0; k < 4; k++) {
                            int nghbrX = x + xTrav[k];
                            int nghbrY = y + yTrav[k];

                            if(nghbrX < 0 || nghbrY < 0 || nghbrX >= m || nghbrY >= n || grid[nghbrX][nghbrY] == '0') continue;
                            if(!visited[nghbrX][nghbrY]) {
                                q.push({nghbrX, nghbrY});
                                visited[nghbrX][nghbrY] = true;
                            }
                        }
                    }

                    ans++;
                }
            }
        }

        return ans;
    }
};