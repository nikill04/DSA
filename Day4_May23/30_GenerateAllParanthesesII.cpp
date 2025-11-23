/*
GENERATE ALL PARANTHESES ii: https://www.interviewbit.com/problems/generate-all-parentheses-ii/

Given an integer A pairs of parentheses, write a function to generate all combinations of well-formed parentheses of length 2*A.



Problem Constraints
1 <= A <= 10



Input Format
First and only argument is integer A.



Output Format
Return a sorted list of all possible parenthesis.



Example Input
Input 1:

A = 3
Input 2:

A = 1


Example Output
Output 1:

[ "((()))", "(()())", "(())()", "()(())", "()()()" ]
Output 2:

[ "()" ]


Example Explanation
Explanation 1:

 All paranthesis are given in the output list.
Explanation 2:

 All paranthesis are given in the output list.             */



 void solve(int open, int close, string str, vector<string> &vec) {
    if(close == 0) {
        vec.push_back(str);
        return;
    }
    if(open > 0) {
        solve(open - 1, close, str + "(", vec);
    }  
    if(open < close) {
        solve(open, close - 1, str + ")", vec);
    }  
}

vector<string> Solution::generateParenthesis(int A) {
    vector<string> vec;
    if(A == 0) return vec;
    
    int open = A;
    int close = A;
    
    string str = "";
    solve(open, close, str, vec);
    return vec;
}