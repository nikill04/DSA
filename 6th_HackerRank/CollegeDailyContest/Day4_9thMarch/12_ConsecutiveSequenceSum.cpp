/* CONSECUTIVE SEQUENCE SUM : https://www.hackerrank.com/contests/iiits-ytp2026-0903/challenges/consecutive-sequence-sum

Given a positive integer M, find all possible sequences of at least two consecutive positive integers such that their sum is exactly M.

For each valid sequence, output only its starting and ending numbers as a space-separated pair on a new line.

If multiple valid sequences exist, print them in ascending order of their starting numbers.

If no such sequence exists, print nothing.

Input Format

A single integer M on the first line.

Constraints

10 <= M <= 2 * 10^8

Output Format

Print each valid sequence on a new line in the format:

start end

If no such sequence exists, print nothing.

Sample Input 0

10
Sample Output 0

1 4
Explanation 0

The sequence 1, 2, 3, 4 sums to 10.

No other sequence of at least two consecutive positive integers sums to 10.

Sample Input 1

15
Sample Output 1

1 5
4 6
7 8
Explanation 1

15 can be written as the sum of consecutive positive integers in the following ways:

1 + 2 + 3 + 4 + 5 = 15
4 + 5 + 6 = 15
7 + 8 = 15

So the valid start and end pairs are: 1 5 4 6 7 8                               */






vector<vector<int>> consecutiveSequenceSum(int M) {
    vector<vector<int>> ans;
    
    int start = 1;
    int end = 2;
    int currentSum = 3;
    
    while(start <= M / 2) {
        if(currentSum == M) {
            ans.push_back({start, end});
            currentSum -= start;
            start++;
        }
        else if(currentSum < M) {
            end++;
            currentSum += end;
        }
        else {
            currentSum -= start;
            start++;
        }
    }
    
    return ans;
}