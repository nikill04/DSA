/* MAXIMUM SIDE LENGTH OF A SQUARE WITH SUM LESS THAN OR EQUAL TO THRESHOLD : https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/description/?envType=daily-question&envId=2026-01-19

Given a m x n matrix mat and an integer threshold, return the maximum side-length of a square with a sum less than or equal to threshold or return 0 if there is no such square.

 

Example 1:


Input: mat = [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]], threshold = 4
Output: 2
Explanation: The maximum side length of square with sum less than 4 is 2 as shown.
Example 2:

Input: mat = [[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2]], threshold = 1
Output: 0
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 300
0 <= mat[i][j] <= 104
0 <= threshold <= 105                                 */






class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        // int m = mat.size();
        // int n = mat[0].size();

        // for(int k = min(m, n); k >= 1; k--) {
        //     for(int i = 0; i <= m - k; i++) {
        //         for(int j = 0; j <= n - k; j++) {
                    
        //             int sum = 0;
        //             bool isBreak = false;
        //             for(int p = i; p < i + k; p++) {
        //                 for(int q = j; q < j + k; q++) {
        //                     sum += mat[p][q];
        //                 }
        //                 if(sum > threshold) {
        //                     isBreak = true;
        //                     break;
        //                 }
        //             }

        //             if(isBreak) continue;
        //             return k;
        //         }
        //     }
        // }

        // return 0;

        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                prefix[i][j] = mat[i - 1][j - 1]
                               + prefix[i][j - 1]
                               + prefix[i - 1][j]
                               - prefix[i - 1][j - 1];

            }
        }

        int low = 0; 
        int high = min(m, n); // Max side of a square;
        int answer = 0;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(isPossible(prefix, m, n, mid, threshold)) {
                answer = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return answer;
    }

    bool isPossible(vector<vector<int>> & prefix,
                    int m, int n, int k,
                    int threshold) {
        if(k == 0) return true;

        for(int i = 0; i <= m - k; i++) {
            for(int j = 0; j <= n - k; j++) {
                int sum = prefix[i + k][j + k]
                          - prefix[i][j + k]
                          - prefix[i + k][j]
                          + prefix[i][j];

                if(sum <= threshold) return true;
            }
        }

        return false;
    }
};