/* GEEKS VILLAGE AND WELLS - 170647 : https://www.geeksforgeeks.org/problems/geeks-village-and-wells--170647/1 

Geek's village is represented by a 2-D matrix of characters of size n*m, where

H - Represents a house
W - Represents a well
. - Represents an open ground
N - Prohibited area(Not allowed to enter this area)

Every house in the village needs to take water from a well, as the family members are so busy with their work, so every family wants to take the water from a well in minimum time, which is possible only if they have to cover as less distance as possible. Your task is to determine the minimum distance that a person in the house should travel to take out the water and carry it back to the house.

A person is allowed to move only in four directions left, right, up, and down. That means if he/she is the cell (i,j), then the possible cells he/she can reach in one move are (i,j-1),(i,j+1),(i-1,j),(i+1,j), and the person is not allowed to move out of the grid.

Note: For all the cells containing 'N', 'W' and '.' our answer should be 0, and for all the houses where there is no possibility of taking water our answer should be -1.

Example 1:

Input:
n = 3
m = 3
c[][]: H H H
       H W H
       H H H
Output:
4 2 4 
2 0 2 
4 2 4
Explanation:
There is only one well hence all the houses present
in the corner of matrix will have to travel a minimum
distance of 4, 2 is for house to well and other two is
for well to house. And rest of the houses have to travel
a minimum distance of 2 (House -> Well -> House).
Example 2:

Input:
n = 5
m = 5
c[][]: H N H H H
       N N H H W
       W H H H H
       H H H H H
       H H H H H
Output:
-1 0 6 4 2 
0 0 4 2 0 
0 2 4 4 2 
2 4 6 6 4 
4 6 8 8 6
Explanation:
There is no way any person from the house in
cell (0,0) can take the water from any well, and
for rest of the houses there is same type of
strategy we have to follow as followed in example 1. 
Your Task:
You don't need to read input or print anything. Your task is to complete the function geekAndWells() which takes n and m, dimensions of the grid, and a 2-D grid of size n*m and returns a 2-D array containing the minimum distance for all the houses as explained above.

Expected Time Complexity: O(n*m)
Expected Space Complexity: O(n*m)

Constraints:
1 <= n <= 10^3
1 <= m <= 10^3                                     */






// User function Template for C++

class Solution {
  public:
    vector<vector<int>> chefAndWells(int n, int m, vector<vector<char>> &c) {
        // Code here
        
        // Instead finding nearest well for every house i.e., traversing through bfs for every house. We first keep list of all wells, then from the wells we traverse the houses, in this way we reduce the time.
        vector<vector<int>> ans(n, vector<int>(m, 0));
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        

        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
              
                if(c[i][j] == 'W') {
                    q.push({i, j});
                    visited[i][j] = true;
                }
                else if(c[i][j] == 'N') {
                    visited[i][j] = true;
                }
                
            }
        }
        
        int dist = 0;
        
        while(!q.empty()) {
            int N = q.size();
            
            while(N--) {
                int x = q.front().first;
                int y = q.front().second;
                
                q.pop();
                
                int xTrav[] = {0, 0, -1, 1};
                int yTrav[] = {-1, 1, 0, 0};
                
                for(int k = 0; k < 4; k++) {
                    int newX = x + xTrav[k];
                    int newY = y + yTrav[k];
                    
                    if(newX < 0 || newX >= n || newY < 0 || newY >= m || visited[newX][newY]) continue;
                    if(c[newX][newY] == 'H') {
                        ans[newX][newY] = 2 * (dist + 1);
                    }
                    
                    // The below statements we should do even for '.' not only for 'H'
                    visited[newX][newY] = true;
                    q.push({newX, newY});
                    
                }
                
            }
            
            dist++;
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(c[i][j] == 'H' && !visited[i][j]) ans[i][j] = -1;
            }
        }
        return ans;
    }
};