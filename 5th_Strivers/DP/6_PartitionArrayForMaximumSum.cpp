/* PARTITION ARRAY FOR MAXIMUM SUM : https://leetcode.com/problems/partition-array-for-maximum-sum/description/

Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.

 

Example 1:

Input: arr = [1,15,7,9,2,5,10], k = 3
Output: 84
Explanation: arr becomes [15,15,15,9,10,10,10]
Example 2:

Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
Output: 83
Example 3:

Input: arr = [1], k = 1
Output: 1
 

Constraints:

1 <= arr.length <= 500
0 <= arr[i] <= 109
1 <= k <= arr.length                                  */





class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        // return helper(arr, k, 0);

        vector<int> dp(arr.size(), -1);
        return helper2(arr, k, 0, dp);
    }

    int helper2(vector<int> & arr, int & k, int start, vector<int> & dp) {
        int n = arr.size();

        if(start == n) return 0;
        if(dp[start] != -1) return dp[start];

        int maxi = INT_MIN;
        int maxiSum = INT_MIN;

        for(int i = start; i < min(start + k, n); i++) {
            maxi = max(maxi, arr[i]);

            int sum = (i - start + 1) * maxi + helper2(arr, k, i + 1, dp);

            maxiSum = max(maxiSum, sum);
        }

        return dp[start] = maxiSum;
    }

    // int helper(vector<int> & arr, int & k, int start) {
    //     int n = arr.size();
    //     if(start == n) return 0;

    //     int maxi = INT_MIN;
    //     int maxiSum = INT_MIN;

    //     for(int i = start; i < min(start + k, n); i++) {
    //         maxi = max(maxi, arr[i]);

    //         int sum = (i - start + 1) * maxi + helper(arr, k, i + 1);

    //         maxiSum = max(maxiSum, sum);
    //     }

    //     return maxiSum;
    // } 
};









































class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        // Adjacency List
        // if(n <= 1) return 0;

        vector<vector<pair<int, int>>> graph(n);
        for(int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }

        vector<vector<pair<int, int>>> reverseGraph(n);
        for(int i = 0; i < edges.size(); i++) {
            reverseGraph[edges[i][1]].push_back({edges[i][0], 2 * edges[i][2]});
        }

        vector<bool> traversed(n, false);

        return helper(graph, reverseGraph, traversed, 0, 0);
    }

    int helper(vector<vector<pair<int, int>>> & graph,
               vector<vector<pair<int, int>>> & reverseGraph,
               vector<bool> & traversed,
               int currNode,
               int sum) {
        if(traversed[currNode]) return INT_MAX;
        traversed[currNode] = true;
        if(currNode == graph.size() - 1) {
            traversed[currNode] = false;
            return sum;
        }

        int mini = INT_MAX;
        for(int i = 0; i < graph[currNode].size(); i++) {
            int currSum = helper(graph, reverseGraph, traversed, graph[currNode][i].first, sum + graph[currNode][i].second);

            // traversed[graph[currNode][i].first] = false;
            mini = min(mini, currSum);
        }

        for(int i = 0; i < reverseGraph[currNode].size(); i++) {
            int currSum = helper(graph, reverseGraph, traversed, reverseGraph[currNode][i].first, sum + reverseGraph[currNode][i].second);

            mini = min(mini, currSum);
        }

        traversed[currNode] = false;
        return mini;
    }
};