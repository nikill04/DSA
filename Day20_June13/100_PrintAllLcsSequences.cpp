// The below code should be optimized, it is giving Time Limit Exceeded for running all test cases on gfg, one part of the solution contains recursion, i think it should be optimized.

/* PRINT ALL LCS SEQUENCES : https://www.geeksforgeeks.org/problems/print-all-lcs-sequences3413/1

You are given two strings s1 and s2. Your task is to print all distinct longest common subsequences in lexicographical order.

Note: A subsequence is derived from another string by deleting some or none of the elements without changing the order of the remaining elements.

Examples:

Input: s1 = "abaaa", s2 = "baabaca"
Output: ["aaaa", "abaa", "baaa"]
Explanation: Length of lcs is 4, in lexicographical order they are "aaaa", "abaa", "baaa".
Input: s1 = "aaa", s2 = "a"
Output: ["a"]
Explanation: Length of lcs is 1 and it is "a".               */




class Solution {
  public:
    vector<string> STR;
    
    vector<string> allLCS(string &s1, string &s2) {
        // Code here
        vector<vector<int>> mat(s1.size() + 1, vector<int>(s2.size() + 1));
        
        helper(s1, s2, mat);
        
        helper1(s1, s2, "", s1.size(), s2.size(), mat);
        
        sort(STR.begin(), STR.end());
        
        
        
        // for(auto str = STR.begin(); str != STR.end(); ) {
        //     string s = *(str);
            
        //     for( ; *(++str) != s; ) {
        //         STR.erase(str);
        //     }
        // }
        // This above for loop gives error, use the below one
        
        for(auto str = STR.begin(); str != STR.end(); ) {
            string s = *(str);
            auto next = str + 1;
            
            while(next != STR.end() && *next == s) {
                next = STR.erase(next);
            }
            
            str = next;
        }
        
        // Or you simply use the below one in one simple line
        // STR.erase(unique(STR.begin(), STR.end()), STR.end());
        return STR;
    }
    
    void helper1(string &s1, string &s2, string s3, int n , int m, vector<vector<int>> & mat) {
        if(n == 0 || m == 0) {
            reverse(s3.begin(), s3.end());
            STR.push_back(s3);
            return;
        }
        
        if(s1[n - 1] == s2[m - 1]) {
            s3 = s3 + s1[n - 1];
            helper1(s1, s2, s3, n - 1, m - 1, mat);
        } 
        else if(mat[n - 1][m] > mat[n][m - 1]) {
            helper1(s1, s2, s3, n - 1, m, mat);
        }
        else if(mat[n - 1][m] < mat[n][m - 1]) {
            helper1(s1, s2, s3, n, m - 1, mat);
        }
        else {
            helper1(s1, s2, s3, n - 1, m, mat);
            helper1(s1, s2, s3, n, m - 1, mat);
        }
        
        return;
    }
    
    void helper(string & s1, string & s2, vector<vector<int>> & mat) {
        for(int j = 0; j <= s2.size(); j++) {
            mat[0][j] = 0;
        }
        
        for(int i = 1; i <= s1.size(); i++) {
            mat[i][0] = 0;
        }
        
        for(int i = 1; i <= s1.size(); i++) {
            for(int j = 1; j <= s2.size(); j++) {
                if(s1[i - 1] == s2[j - 1]) {
                    mat[i][j] = 1 + mat[i - 1][j - 1];
                }
                else {
                    mat[i][j] = max(mat[i - 1][j], mat[i][j - 1]);
                }
            }
        }
    }
};
