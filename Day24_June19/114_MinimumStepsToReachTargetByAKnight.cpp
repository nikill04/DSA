/* MINIMUM STEPS TO REACH TARGET BY A KNIGHT : https://www.naukri.com/code360/problems/minimum-steps-to-reach-target-by-a-knight_893050

You have been given a square chessboard of size ‘N x N’. The position coordinates of the Knight and the position coordinates of the target are also given.

Your task is to find out the minimum steps a Knight will take to reach the target position.


Example:
knightPosition: {3,4}
targetPosition: {2,1}

The knight can move from position (3,4) to positions (1,3), (2,2) and (4,2). Position (4,2) is selected and the ‘stepCount’ becomes 1. From position (4,2), the knight can directly jump to the position (2,1) which is the target point and ‘stepCount’ becomes 2 which is the final answer. 
Note:

1. The coordinates are 1 indexed. So, the bottom left square is (1,1) and the top right square is (N, N).

2. The knight can make 8 possible moves as given in figure 1.

3. A Knight moves 2 squares in one direction and 1 square in the perpendicular direction (or vice-versa).
Detailed explanation ( Input/output format, Notes, Images )
Sample input 1
2
8
2 1
8 5
6
4 5
1 1
Sample output 1
4
3
Explanation of sample input 1:
Test case 1:

The knight is initially at position [2,1]. It has 3 possible blocks to move to, [4,2], [3,3], and [1,3]. The knight chooses [4,2]. Now, there are 6 more possible blocks to move to. The knight chooses [5,4]. Further, the knight chooses position [7,3]. Finally, the knight moves to the target position which is [8,5] which calculates to 4 steps.

Test case 2:
The knight moves from position [4,5] to [5,3] to [3,2] and finally to the target position [1,1] which gives us the minimum steps by the knight, that is, 3.
(4, 5) -> (5, 3) -> (3, 2) -> (1, 1).
Sample input 2:
2
6 
2 4
6 4
6
1 1
4 5
Sample output 2:
2
3                                                             */





int minSteps(pair<int, int> knightPosition, pair<int, int> targetPosition, int size) {
    // Write your code here.

    // First in any matrix (a, b), a is row and b is column that 0-index based(starting from 0). But here he took (a, b), where a is column and b is row and that too 1-indexed. So, to avoid confusion let's convert them according to our convinience.
    pair<int, int> knight = {size - knightPosition.second, knightPosition.first - 1};
    pair<int, int> target = {size - targetPosition.second, targetPosition.first - 1};

    if(knight == target) return 0;

    queue<pair<int, int>> q;
    q.push({knight.first, knight.second});

    int i, j;
    int steps = 0;
    vector<vector<int>> visited(size, vector<int>(size, -1));
    visited[knight.first][knight.second] = 1;

    while(!q.empty()) {
        int levelSize = q.size();
        steps++;

        while(levelSize--) {  // This loop is for making steps count increase one for each level not for every q.front() or simply every node. That's why wrapped the code in this while loop.
            for(int k = 0; k < 8; k++) {
                switch(k) {
                    case 0 :
                        i = q.front().first - 2;
                        j = q.front().second - 1;
                        break;
                    case 1 :
                        i = q.front().first - 2;
                        j = q.front().second + 1;
                        break;
                    case 2 :
                        i = q.front().first - 1;
                        j = q.front().second - 2;
                        break;
                    case 3 :
                        i = q.front().first - 1;
                        j = q.front().second + 2;
                        break;
                    case 4 :
                        i = q.front().first + 1;
                        j = q.front().second - 2;
                        break;
                    case 5 :
                        i = q.front().first + 1;
                        j = q.front().second + 2;
                        break;
                    case 6 :
                        i = q.front().first + 2;
                        j = q.front().second - 1;
                        break;
                    case 7 :
                        i = q.front().first + 2;
                        j = q.front().second + 1;
                }

                if(i == target.first && j == target.second) return steps;

                if(i < 0 || j < 0 || i >= size || j >= size || visited[i][j] == 1) {
                    continue;
                }

                q.push({i, j});
                visited[i][j] = 1;
            }
            
            q.pop();
        }
        
    }

    return -1;


    // The same code as above, just a simple change instead of big switch case, we just replaced reaminig all as it is same.
    
    // int dx[8] = {-2,-2,-1,-1,1,1,2,2};
    // int dy[8] = {-1,1,-2,2,-2,2,-1,1};

    // vector<vector<char>> visited(size, vector<char>(size, 0));
    // queue<pair<int,int>> q;

    // q.push(knight);
    // visited[knight.first][knight.second] = 1;

    // int steps = 0;

    // while (!q.empty()) {
    //     int levelSize = q.size();
    //     steps++;

    //     while (levelSize--) {
    //         auto [x, y] = q.front();
    //         q.pop();

    //         for (int k = 0; k < 8; k++) {
    //             int nx = x + dx[k];
    //             int ny = y + dy[k];

    //             if (nx < 0 || ny < 0 || nx >= size || ny >= size) continue;
    //             if (visited[nx][ny]) continue;
    //             if (nx == target.first && ny == target.second) return steps;

    //             visited[nx][ny] = 1;
    //             q.push({nx, ny});
    //         }
    //     }
    // }
    // return -1;
}

