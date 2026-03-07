/* SUBARRAYS WITH GIVEN SUM AND BOUNDED MAXIMUM : https://www.hackerrank.com/contests/software-engineer-prep-kit/challenges/subarrays-given-sum-bounded-maximum/problem?isFullScreen=true

Given an integer array nums and integers k and M, count the number of contiguous subarrays whose sum equals k and whose maximum element is at most M.

Example

Input

nums = [2, -1, 2, 1, -2, 3]
k = 3
M = 2
Output

2
Explanation

We need subarrays with sum = 3 and all elements ≤ 2. 
Also, any subarray containing 3 is invalid because 3 > M. Check all starts:

- From index 0: [2, -1, 2] → sum = 3, max = 2 → valid (count = 1).
- From index 2: [2, 1] → sum = 3, max = 2 → valid (count = 2). No other subarray qualifies. Thus the total count is 2.
Input Format

The first line contains an integer n denoting the number of elements in nums.
The next n lines contains an integer denoting elements in nums followed by the value of k & M.
Example

6 → number of elements in nums
2 → elements of nums
-1
2
1
-2
3
3 → value of k
2 → value of M
Constraints

0 <= nums.length <= 1000000
-10^9 <= nums[i] <= 10^9 for all 0 <= i < nums.length
-10^15 <= k <= 10^15
-10^9 <= M <= 10^9
Output Format

Returns a non-negative integer denoting the count of all contiguous subarrays of nums.
Sample Input 0

0
0
0
Sample Output 0

0
Sample Input 1

1
5
5
5
Sample Output 1

1                                                    */





/*
 * Complete the 'countSubarraysWithSumAndMaxAtMost' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY nums
 *  2. LONG_INTEGER k
 *  3. LONG_INTEGER M
 */

long countSubarraysWithSumAndMaxAtMost(vector<int> nums, long k, long M) {
    int n = nums.size();
    
    long ans = 0;
    
    for(int i = 0; i < n; i++) {
        if(nums[i] > M) continue;
        
        int sum = 0;
        for(int j = i; j < n; j++) {
                if(nums[j] > M) break;
            
            sum += nums[j];
            if(sum == k) ans++;
        }
    }
    
    return ans;
}