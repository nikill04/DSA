/*
MAX SUM SUBARRAY OF SIZE K: https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1

Given an array of integers arr[]  and a number k. Return the maximum sum of a subarray of size k.

Note: A subarray is a contiguous part of any given array.

Examples:

Input: arr[] = [100, 200, 300, 400] , k = 2
Output: 700
Explanation: arr3  + arr4 = 700, which is maximum.
Input: arr[] = [100, 200, 300, 400] , k = 4
Output: 1000
Explanation: arr1 + arr2 + arr3 + arr4 = 1000, which is maximum.
Input: arr[] = [100, 200, 300, 400] , k = 1
Output: 400
Explanation: arr4 = 400, which is maximum.
Constraints:
1 <= arr.size() <= 106
1 <= arr[i]<= 106
1 <= k<= arr.size()          */



class Solution {
  public:
    int maximumSumSubarray(vector<int>& arr, int k) {
        // code here
        int i = 0;
        int j = k - 1;
        int max = INT_MIN;
        int sum = 0;
        for( ; i <= j; i++) {
            sum += arr[i];
        }
        if(max < sum) max = sum;
        for(i = 1; i <= arr.size() - k; i++) {
            j += 1;
            sum = sum + arr[j] - arr[i - 1];
            if(max < sum) max = sum;
        }
        return max;
    }
};

// What we did above was sliding window i.e., O(n). Otherwise, in brute force approach for every i we do k iterations and calculate sum i.e., nested loop which is O(n^2). 
// But here we just slided the window i.e., once calculated the sum and after that for every iteration just removed the before one and added the next one.
