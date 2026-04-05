/* EDIT DISTANCE : https://www.hackerrank.com/contests/iiits-ytp2026-1403/challenges/edit-distance-35-1

Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character

Delete a character

Replace a character

Input Format

The first line contains the string word1.

The second line contains the string word2.

Constraints

1<=word1.length, word2.length<=12

word1 and word2 consist of lowercase English letters

Output Format

A single integer representing the minimum number of operations.

Sample Input 0

horse
ros
Sample Output 0

3
Sample Input 1

intention
execution
Sample Output 1

5                                                */






int minDistance(string word1, string word2) {
    int n1 = word1.size();
    int n2 = word2.size();
    
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    // The value at $dp[i][j]$ represents the minimum number of operations required to convert the first $i$ characters of word1 into the first $j$ characters of word2.
    
    // If word2 is empty ($j = 0$), the only way to convert word1 to an empty string is to delete all its characters. So, dp[i][0] = i.
    for(int i = 0; i <= n1; i++) {
        dp[i][0] = i;
    }
    // If word1 is empty ($i = 0$), the only way to convert it to word2 is to insert all characters of word2. So, dp[0][j] = j.
    for(int j = 0; j <= n2; j++) {
        dp[0][j] = j;
    }
    
    for(int i = 1; i <= n1; i++) {
        for(int j = 1; j <= n2; j++) {
            if(word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                int insertion = dp[i][j - 1];
                int deletion = dp[i - 1][j];
                int replace = dp[i - 1][j - 1];
                
                dp[i][j] = 1 + min({insertion, deletion, replace});
            }
        }
    }
    
    /* We iterate through each character of both words. For every cell $dp[i][j]$, we check the characters word1[i-1] and word2[j-1]:
    Case A: The characters match. If word1[i-1] == word2[j-1], no new operation is needed. The cost is the same as converting the strings without these matching characters. dp[i][j] = dp[i-1][j-1] 
    
    Case B: 
        1. Deletion (dp[i-1][j])The Action: You remove the character at word1[i-1].The Index Logic: By deleting a character from word1, you have moved forward by one character in word1 (i -> i-1), but you have not matched anything in word2 yet.The Cell: You look up to dp[i-1][j]. This cell tells you: "What was the cost to match the previous version of word1 to the current target word2?"
        2. Insertion (dp[i][j-1])The Action: You add a character to word1 that matches word2[j-1].The Index Logic: Because you manually added the character that word2 needed, you have now "satisfied" or matched the character at index j (j -> j - 1). However, you haven't used up any of the original characters from word1 yet (i remains i).The Cell: You look left to dp[i][j-1]. This cell tells you: "What was the cost to match the current word1 to the previous part of word2?"
        3. Replacement (dp[i-1][j-1])The Action: You change the character at word1[i-1] to match word2[j-1]. Since you modified the character, both the current character of word1 and the current target character of word2 are now "resolved." You move back one step in both strings i.e., dp[i - 1][j - 1]. 
        
        
        Since we want the minimum operations, we take the smallest value among those three previous states and add 1 (the cost of the current edit).dp[i][j] = 1 + min(dp[i-1][j] (DELETE), dp[i][j-1] (INSERT), dp[i-1][j-1] (REPLACE))
        Why this worksBy the time you reach cell (i, j), the tabulation method ensures that all cells to the left, above, and diagonally above are already calculated. You are simply choosing the path of least resistance from the available operations.If word1[i-1] == word2[j-1], the cost is 0 for that step, so you just inherit the diagonal value: dp[i][j] = dp[i-1][j-1].
        */
    
    return dp[n1][n2];
}