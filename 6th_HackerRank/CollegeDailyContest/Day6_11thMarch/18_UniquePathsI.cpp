/* UNIQUE PATHS I : https://www.hackerrank.com/contests/iiits-ytp2026-1103/challenges/unique-paths-i

There is a robot on an m*n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m-1][n-1]). The robot can only move either down or right at any point in time.Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

Input Format

The first line contains a single integer, m, representing the number of rows in the grid.

The second line contains a single integer, n, representing the number of columns in the grid.

Constraints

1<=m,n<=100

The test cases are generated so that the answer will be less than or equal to 2*times 10^9

Output Format

A single line containing an integer that represents the total number of unique paths from the top-left to the bottom-right corner.

Sample Input 0

3
7
Sample Output 0

28
Sample Input 1

3
2
Sample Output 1

3                                              */






int helper(int x, int y, int & m, int & n, vector<vector<int>> & vec) {
    if(x == m - 1 && y == n - 1) return 1;
    
    if(vec[x][y] != -1) return vec[x][y];
    
    int ans = 0;
    if(x != m - 1) {
        ans += helper(x + 1, y, m, n, vec);
    }
    if(y != n - 1) {
        ans += helper(x, y + 1, m, n, vec);
    }
    
    vec[x][y] = ans;
    return ans;
}


int uniquePaths(int m, int n) {
    vector<vector<int>> vec(m, vector<int>(n, -1));
    return helper(0, 0, m, n, vec);
}