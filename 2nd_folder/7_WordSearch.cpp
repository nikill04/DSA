/* WORD SEARCH : https://leetcode.com/problems/word-search/description/?envType=problem-list-v2&envId=depth-first-search&

Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

Example 1:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 

Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.
 

Follow up: Could you use search pruning to make your solution faster with a larger board?          */






class Solution {
public:
    bool ans = false;

    bool exist(vector<vector<char>>& board, string word) {

        if(board.size() == 0 || word.size() == 0) return false;


        vector<pair<int, int>> startingPoint;

        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                if(board[i][j] == word[0]) startingPoint.push_back({i, j});
            }
        }

        if(startingPoint.size() == 0) return false;
        if(word.size() == 1) return true;

        for(int i = 0; i < startingPoint.size(); i++) {
            vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), -1));
            visited[startingPoint[i].first][startingPoint[i].second] = 1;

            finder(board, word, 1, startingPoint[i].first, startingPoint[i].second, visited);  // 1 is index of word, i.e., from that index of the word string we have to find in board.

            if(ans == true) return ans;
        }

        return ans;
    }

    void finder(vector<vector<char>> & board, string & word, int c, int a, int b, vector<vector<int>> & visited) {
        if(c == word.size()) return;
        int i, j;
        
        for(int k = 0; k < 4; k++) {
            switch(k) {
                case 0:
                    i = a - 1;
                    j = b;
                    break;
                case 1:
                    i = a;
                    j = b - 1;
                    break;
                case 2:
                    i = a;
                    j = b + 1;
                    break;
                case 3: 
                    i = a + 1;
                    j = b;
            }
            if( ans == true || i < 0 || i >= board.size() || j < 0 || j >= board[a].size() || visited[i][j] == 1 || board[i][j] != word[c]) {
                    continue;
                }
                
                if(c == word.size() - 1 && board[i][j] == word[c]) {
                    ans = true;
                    return;
                }

                visited[i][j] = 1;
                finder(board, word, c + 1, i, j, visited);
                visited[i][j] = -1;
        }

        return;
    }
};