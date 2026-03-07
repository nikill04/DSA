/* ZERO SUM TRIPLETS WITHIN A SLIDING WINDOW : https://www.hackerrank.com/contests/software-engineer-prep-kit/challenges/zero-sum-triplets-within-sliding-window/problem?isFullScreen=true

Given an integer array and an integer windowSize, find all unique triplets at indices i < j < k such that array[i] + array[j] + array[k] = 0 and k - i + 1 <= windowSize. Return the triplets without duplicates.

Example

Input:

readings = [1, -2, 1, 0, 5]
windowSize = 3
Output:

[[1, -2, 1]]
Explanation:

We look at every subarray of length up to 3 (k - i + 1 ≤ 3).

The only possible triples are indices (0,1,2): (1, -2, 1) which sums to 0; indices (1,2,3): (-2, 1, 0) sums to -1; indices (2,3,4): (1, 0, 5) sums to 6.

Only [1, -2, 1] sums to zero.

Input Format

The function receives two arguments:

readings: an INTEGER_ARRAY of length N, where 1 <= N <= 100000 and each element is between -100000 and 100000.
windowSize: an INTEGER, 1 <= windowSize <= N.
Constraints

1 <= readings.length <= 100000
-100000 <= readings[i] <= 100000 for each valid i
1 <= windowSize <= readings.length
Output Format

Return a 2D_INTEGER_ARRAY where each element is a triplet [x, y, z] meeting the zero-sum and window constraints. Triplets must be unique (no duplicate sets) and may be in any order. Corresponding outputs for the example inputs:

[[-1, -1, 2], [-1, 0, 1]]
[[0, 0, 0]]
[]
[[-2, 0, 2], [-2, 1, 1]]
[[-5, 2, 3], [-2, -1, 3]]
Sample Input 0

1
1
1
Sample Input 1

2
1
-1
2                                        */





