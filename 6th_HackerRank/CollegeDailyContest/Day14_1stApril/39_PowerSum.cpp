/* POWER SUM : https://www.hackerrank.com/contests/iiits-ytp2026-0104/challenges/the-power-sum/problem

Find the number of ways that a given integer, , can be expressed as the sum of the  powers of unique, natural numbers.

For example, if X = 13 and N = 2, we have to find all combinations of unique squares adding up to 13. The only solution is 2^2 + 3^2 = 13.

Function Description

Complete the powerSum function in the editor below. It should return an integer that represents the number of possible combinations.

powerSum has the following parameter(s):

X: the integer to sum to
N: the integer power to raise numbers to
Input Format

The first line contains an integer X.
The second line contains an integer N.

Constraints
1 <= X <= 1000
2 <= N <= 10

Output Format

Output a single integer, the number of possible combinations caclulated.

Sample Input 0

10
2
Sample Output 0

1
Explanation 0

If X = 10 and N = 2, we need to find the number of ways that 10 can be represented as the sum of squares of unique numbers.
10 = 1^2 + 3^2 

This is the only way in which 10 can be expressed as the sum of unique squares.

Sample Input 1

100
2
Sample Output 1

3
Explanation 1
100 = 10^2
100 = 8^2 + 6^2
100 = 7^2 + 5^2 + 4^2 + 3^2 + 1^2

Sample Input 2

100
3
Sample Output 2

1
Explanation 2

100 can be expressed as the sum of the cubes of 1, 2, 3, 4(1^3 + 2^3 + 3^3 + 4^3 = 100).
. There is no other way to express 100 as the sum of cubes.                                 */








int powerSum(int X, int N) {

    double a = pow(X, 1.0 / N);  // Why we are doing this is, we need to find the maximum number whose Nth power is less than or equal to X. So, we are finding the Nth root of X and then we will take the floor of it to get the maximum number.
    
    vector<vector<int>> dp((int)a + 1, vector<int>(X + 1, 0));
    
    for(int i = 0; i <= (int)a; i++) {
        dp[i][0] = 1;
    }
    
    for(int j = 1; j <= X; j++) {
        dp[0][j] = 0;
    }
    
    for(int i = 1; i <= (int)a; i++) {
        for(int j = 1; j <= X; j++) {
            if(pow(i, N) <= j) {
                int take = dp[i - 1][j - pow(i, N)];     // Take the current element into consideration
                int notTake = dp[i - 1][j];              // If chose to not take the current element.
                
                dp[i][j] = take + notTake;
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    
    return dp[(int)a][X];
}