/* THE MAXIMUM SUBARRAY : https://www.hackerrank.com/contests/iiits-ytp2026-0603/challenges/maxsubarray

We define subsequence as any subset of an array. We define a subarray as a contiguous subsequence in an array.

Given an array, find the maximum possible sum among:

1. all nonempty subarrays.
2. all nonempty subsequences.
Print the two values as space-separated integers on one line.

Note that empty subarrays/subsequences should not be considered.

Example
arr = [-1, 2, 3, -4, 5, 10]

The maximum subarray sum is comprised of elements at inidices [1 - 5] . Their sum is 2 + 3 -4 + 5 + 10 = 16. The maximum subsequence sum is comprised of elements at indices [1, 2, 4, 5] and their sum is 2 + 3 + 5 + 10 = 20.

Function Description

Complete the maxSubarray function in the editor below.

maxSubarray has the following parameter(s):

int arr[n]: an array of integers
Returns

int[2]: the maximum subarray and subsequence sums
Input Format

The first line of input contains a single integer t, the number of test cases.

The first line of each test case contains a single integer n.
The second line contains n space-separated integers arr[i]  where 0 <= i < n.

Constraints
1 <= t <= 10
1 <= n <= 10^5
-10^4 <= arr[i] <= 10^4

The subarray and subsequences you consider should have at least one element.

Sample Input 0

2
4
1 2 3 4
6
2 -1 2 3 4 -5
Sample Output 0

10 10
10 11
Explanation 0

In the first case: The maximum sum for both types of subsequences is just the sum of all the elements since they are all positive.

In the second case: The subarray  [2, -1, 2, 3, 4] is the subarray with the maximum sum, and  [2, 2, 3, 4] is the subsequence with the maximum sum.

Sample Input 1

1
5
-2 -3 -1 -4 -6
Sample Output 1

-1 -1
Explanation 1

Since all of the numbers are negative, both the maximum subarray and maximum subsequence sums are made up of one element, -1.*/






vector<int> maxSubarray(vector<int> arr) {
    
//     int n = arr.size();
//     if(n == 0) return {};
    
//     vector<int> ans(2);
    
//     vector<pair<int, int>> mp;
//     int sum = 0;
//     for(int i = 0; i < n; i++) {
//         if(arr[i] < 0) {
//             mp.push_back({i, sum});
//             sum = 0;
//         }
//         else sum += arr[i];
//     }
    
//     int maxSum = INT_MIN;
    
//     int n1 = mp.size();
    
//     for(int i = 0; i < n1; i++) {
//         int sum = 0;
//         for(int j = i; j < n1; j++) {
//             sum += mp[j].second;
//             maxSum = max(maxSum, sum);
//             sum += arr[mp[j].first];
//         }
//     }
    
//     ans[0] = maxSum;
    
    

//     sort(arr.begin(), arr.end());
//     if(arr[n - 1] < 0) ans[1] = arr[0];
//     else {
//         for(int i = 0; i < n; i++) {
//             if(arr[i] < 0) continue;
//             ans[1] += arr[i];
//         }
//     }
    
//     // if(maxSum == 0) ans[0] = arr[0];
    
//     return ans;
    
    int n = arr.size();
    
    int result1 = INT_MIN;
    int maxEnding = 0;
    
    for(int i = 0; i < n; i++) {
        if(maxEnding < 0) 
            maxEnding = arr[i];
        else
            maxEnding += arr[i];
        
        result1 = max(result1, maxEnding);
    }
    
    int result2 = 0;
    sort(arr.begin(), arr.end());
    if(arr[n - 1] < 0) result2 = arr[n - 1];
    else {
        for(int i = 0; i < n; i++) {
            if(arr[i] > 0) result2 += arr[i];
        }
    }
    
    return {result1, result2};

}