/* DIFFERENT WAYS TO EVALUATE A BOOLEAN EXPRESSION : https://takeuforward.org/plus/dsa/problems/different-ways-to-evaluate-a-boolean-expression

You are given a string expr consisting of the characters

'T' — represents true
'F' — represents false
'&' — the logical AND operator
'|' — the logical OR operator
'^' — the logical XOR (exclusive-or) operator


expr is guaranteed to follow the pattern operand operator operand operator … operand (i.e. it always starts and ends with an operand and no two operators are adjacent).



Return the number of distinct ways to fully parenthesize expr such that the whole expression evaluates to true.

Because the answer can be very large, return it modulo 1e9+7.


Example 1

Input: expr = "T|T&F^T"

Output: 4

Explanation:

The expression can be parenthesized as follows (✓ marks variants that evaluate to true):

1. ((T|T)&(F^T)) ✓

2. (T|(T&(F^T))) ✓

3. (((T|T)&F)^T) ✓

4. (T|((T&F)^T)) ✓

5. ((T|(T&F))^T)   → false

6. (T|T)&F^T     → false

Therefore 4 distinct parenthesizations evaluate to true.

Example 2

Input: expr = "T^F|F"

Output: 2

Explanation:

Two parenthesizations evaluate to true:

• ((T ^ F) | F)

• (T ^ (F | F))



Constraints

1 <= expr.length <= 100
expr[i] is 'T', 'F', '&', '|', or '^'.
Operands ('T' or 'F') and operators alternate, so expr always has odd length.
The answer fits in a signed 32-bit integer.                      */






class Solution {
public:
    using ll = long long;
    int mod = 1000000007;

    int countTrue(string s) {
        // Your code goes here
        int n = s.size();
        
        int startInd = 0;
        int endInd = s.size() - 1;

        vector<vector<vector<ll>>> memorization(n, vector<vector<ll>>(n, vector<ll>(2, -1)));

        return (int)dp(s, startInd, endInd, true, memorization);
    }

    ll dp(string & s, int startInd, int endInd, bool isTrue, vector<vector<vector<ll>>> & memorization) {
        if(startInd > endInd) return 0;
        if(startInd == endInd) {
            if(isTrue) return s[startInd] == 'T'; // returns "1" if s[i] is "T" because equals equals return true or false, if it equals returns true which is "1" if not returns false which is "0".
            else return s[startInd] == 'F';  
        }

        if(memorization[startInd][endInd][isTrue] != -1) return memorization[startInd][endInd][isTrue];
        
        ll ways = 0;

        for(int i = startInd + 1; i <= endInd - 1; i += 2) {
            ll leftTrue = dp(s, startInd, i - 1, true, memorization);
            ll leftFalse = dp(s, startInd, i - 1, false, memorization);
            ll rightTrue = dp(s, i + 1, endInd, true, memorization);
            ll rightFalse = dp(s, i + 1, endInd, false, memorization);

            if(s[i] == '&') {
                if(isTrue) {
                    ways = (ways + (leftTrue * rightTrue) % mod) % mod;
                }
                else {
                    ways = (ways + (leftTrue * rightFalse) % mod + (leftFalse * rightTrue) % mod + (leftFalse * rightFalse) % mod) % mod;
                }
            }
            else if(s[i] == '|') {
                if(isTrue) {
                    ways = (ways + (leftTrue * rightTrue) % mod + (leftTrue * rightFalse) % mod + (rightTrue * leftFalse) % mod) % mod;
                }
                else {
                    ways = (ways + (leftFalse * rightFalse) % mod) % mod;
                }
            }
            else {
                if(isTrue) {
                    ways = (ways + (leftTrue * rightFalse) % mod + (leftFalse * rightTrue) % mod) % mod;
                }
                else {
                    ways = (ways + (leftTrue * rightTrue) % mod + (leftFalse * rightFalse) % mod) % mod;
                }
            }

        }

        // return ways;
        return memorization[startInd][endInd][isTrue] = ways;
    }
};
