/* VALID PARENTHESES : https://www.hackerrank.com/contests/iiits-ytp2026-1203/challenges/valid-parentheses-78

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
Input Format

A single line containing a string s.
Constraints

1 <= s.length <= 10^4
s consists of parentheses only '()[]{}'
Output Format

Print "true" if the string is valid.
Otherwise print "false".
Sample Input 0

()
Sample Output 0

true
Sample Input 1

()[]{}
Sample Output 1

true                               */






string isValid(string s) {
    int n = s.size();
    
    int curvOpen = 0;
    int curlOpen = 0;
    int sqOpen = 0;
    
    for(int i = 0; i < n; i++) {
        if(s[i] == '(') curvOpen++;
        if(s[i] == '{') curlOpen++;
        if(s[i] == '[') sqOpen++;
        
        if(s[i] == ')') {
            curvOpen--;
            if(curlOpen != 0 && sqOpen != 0) return "false";
        }
        if(s[i] == '}') {
            curlOpen--;
            if(curvOpen != 0 && sqOpen != 0) return "false";
        }
        if(s[i] == ']') {
            sqOpen--;
            if(curlOpen != 0 && curvOpen != 0) return "false";
        }
        
        if(curvOpen < 0 || curlOpen < 0 || sqOpen < 0) return "false";
        
    }
    
    return "true";
}