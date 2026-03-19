/* NO OF ISLANDS : https://www.hackerrank.com/contests/iiits-ytp2026-1803/challenges/no-of-islands-1

Given an  2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Input Format

The first line contains an integer , the number of rows in the grid.

The second line contains an integer , the number of columns in the grid.

The next  lines each contain  space-separated characters (1 or 0) representing the grid.

Constraints


grid[i][j] is '0' or '1'.

Output Format

A single integer representing the total number of islands.

Sample Input 0

4
5
1 1 1 1 0
1 1 0 1 0
1 1 0 0 0
0 0 0 0 0
Sample Output 0

1
Sample Input 1

4
5
1 1 0 0 0
1 1 0 0 0
0 0 1 0 0
0 0 0 1 1
Sample Output 1

3                                             */






void explore(vector<vector<char>> & grid, vector<vector<bool>> & traveled, int x, int y, int & nR, int & nC) {
    if(x >= nR || y >= nC || x < 0 || y < 0 || traveled[x][y] || grid[x][y] == '0') return;
    
    traveled[x][y] = true;
    
    int arrX[] = {x, x, x + 1, x - 1};
    int arrY[] = {y + 1, y - 1, y, y};
    
    for(int p = 0; p < 4; p++) {
        explore(grid, traveled, arrX[p], arrY[p], nR, nC);
    }
    
    return;
}

int numIslands(vector<vector<char>> grid) {
    int nR = grid.size();
    int nC = grid[0].size();
    
    vector<vector<bool>> traveled(nR, vector<bool>(nC, false));
    
    int count = 0;
    
    for(int i = 0; i < nR; i++) {
        for(int j = 0; j < nC; j++) {
            if(grid[i][j] == '1' && !traveled[i][j]) {
                count++;
                explore(grid, traveled, i, j, nR, nC);
            }
        }
    }
    
    return count;
}