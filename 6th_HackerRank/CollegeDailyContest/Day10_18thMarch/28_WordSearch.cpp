/* WORD SEARCH : https://www.hackerrank.com/contests/iiits-ytp2026-1803/challenges/word-search-22

Given an  grid of characters board and a string word, return true if word exists in the grid.The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a single word path.

Input Format

The first line contains an integer , the number of rows in the board.

The second line contains an integer , the number of columns in the board.

The next  lines each contain  space-separated characters representing the board.The final line contains a single string, word.

Constraints


board and word consists of only lowercase and uppercase English letters.

Output Format

A single line containing true or false.

Sample Input 0

3
4
A B C E
S F C S
A D E E
ABCCED
Sample Output 0

true
Sample Input 1

3
4
A B C E
S F C S
A D E E
SEE
Sample Output 1

true*/






bool isExist(vector<vector<char>> & board, string & word, int x, int y, vector<vector<bool>> & checkBoard, int ind, int & nR, int & nC) {
    
    if(ind == (int)word.length()) return true;
    if(x >= nR || y >= nC || x < 0 || y < 0 || checkBoard[x][y] || board[x][y] != word[ind]) return false;
    
    checkBoard[x][y] = true;
    
    int arrX[] = {x, x, x + 1, x - 1};
    int arrY[] = {y + 1, y - 1, y, y};
    
    for(int i = 0; i < 4; i++) {
        if(isExist(board, word, arrX[i], arrY[i], checkBoard, ind + 1, nR, nC)) return true;
    }
    
    checkBoard[x][y] = false;  // Don't Forget this one. IMPORTANT

    return false;
}

bool exist(vector<vector<char>> board, string word) {
    int nR = board.size();
    int nC = board[0].size();

        
    for(int i = 0; i < nR; i++) {
        for(int j = 0; j < nC; j++) {
            
            if(board[i][j] == word[0]) {
                vector<vector<bool>> checkBoard(nR, vector<bool>(nC, false));
                
                if(isExist(board, word, i, j, checkBoard, 0, nR, nC))
                    return true; 
            } 
        }
    }
    
    return false;
}