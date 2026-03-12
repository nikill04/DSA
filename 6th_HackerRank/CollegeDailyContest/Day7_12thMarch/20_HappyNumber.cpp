/* HAPPY NUMBER : https://www.hackerrank.com/contests/iiits-ytp2026-1203/challenges/happy-number-68-1/problem

Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return the string "true" (without quotes) if n is a happy number, and "false" (without quotes) if not.

Input Format

The first and only line contains a single integer n.
Constraints

1<=n<=2^31 - 1

Output Format

Print "true" if n is a happy number.
Otherwise, print "false".
Sample Input 0

19
Sample Output 0

true
Sample Input 1

2
Sample Output 1

false                                                      */






string isHappy(int n) {
    unordered_set<int> us;
    
    while(us.find(n) == us.end() && n != 1) {
        int temp = 0;
        us.insert(n);
        
        while(n != 0) {
            temp += (n % 10) * (n % 10);
            n = n / 10;
        }
        
        n = temp;
    }
        
    if(n == 1) return "true";
    return "false";
}