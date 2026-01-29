/* PARSING A BOOLEAN EXPRESSION : https://leetcode.com/problems/parsing-a-boolean-expression/description/

A boolean expression is an expression that evaluates to either true or false. It can be in one of the following shapes:

't' that evaluates to true.
'f' that evaluates to false.
'!(subExpr)' that evaluates to the logical NOT of the inner expression subExpr.
'&(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical AND of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
'|(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical OR of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
Given a string expression that represents a boolean expression, return the evaluation of that expression.

It is guaranteed that the given expression is valid and follows the given rules.

 

Example 1:

Input: expression = "&(|(f))"
Output: false
Explanation: 
First, evaluate |(f) --> f. The expression is now "&(f)".
Then, evaluate &(f) --> f. The expression is now "f".
Finally, return false.
Example 2:

Input: expression = "|(f,f,f,t)"
Output: true
Explanation: The evaluation of (false OR false OR false OR true) is true.
Example 3:

Input: expression = "!(&(f,t))"
Output: true
Explanation: 
First, evaluate &(f,t) --> (false AND true) --> false --> f. The expression is now "!(f)".
Then, evaluate !(f) --> NOT false --> true. We return true.
 

Constraints:

1 <= expression.length <= 2 * 104
expression[i] is one following characters: '(', ')', '&', '|', '!', 't', 'f', and ','.         */





class Solution {
public:
    bool parseBoolExpr(string expression) {
        
        while(expression.size() > 1) {
            int n = expression.size();

            int i;
            int j;
            for(i = 0; i < n; i++) {
                if(expression[i] == '(') j = i;
                if(expression[i] == ')') break;
            }

            auto start = expression.begin();

            if(j == 0) {
                return expression[1] == 't' ? true : false; 
            }

            while((expression[j - 1] == '(' && expression[i + 1] == ')') || expression[j - 1] == ',') {
                expression.erase(start + (j - 1));
                expression.erase(start + (i));
            }


            if(expression[j - 1] == '!') {
                for(int a = j + 1; a < i; a++) {
                    if(expression[a] == ',') continue;

                    expression[a] = (expression[a] == 't' ? 'f' : 't');
                }
                
                expression.erase(i, 1);
                expression.erase(j - 1, 2);
            }
            else if(expression[j - 1] == '&') {
                bool isFalse = false;

                for(int a = j + 1; a < i; a++) {
                    if(expression[a] == 'f') {
                        isFalse = true;
                        break;
                    }
                    else if(expression[a] == ',') continue;
                }
                
                isFalse == true ? expression[j - 1] = 'f' : expression[j - 1] = 't';

                expression.erase(start + j, start + (i + 1));

            }
            else {
                bool isTrue = false;

                for(int a = j + 1; a < i; a++) {
                    if(expression[a] == 't') {
                        isTrue = true;
                        break;
                    }
                    else if(expression[a] == ',') continue;
                }

                isTrue == true ? expression[j - 1] = 't' : expression[j - 1] = 'f';

                expression.erase(start + j, start + (i + 1));
            }
                
        }

        return expression[0] == 't' ? true : false;
    }
};