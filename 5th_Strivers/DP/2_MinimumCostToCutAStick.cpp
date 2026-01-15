/* MINIMUM COST TO CUT A STICK : https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/

Given a wooden stick of length n units. The stick is labelled from 0 to n. For example, a stick of length 6 is labelled as follows:


Given an integer array cuts where cuts[i] denotes a position you should perform a cut at.

You should perform the cuts in order, you can change the order of the cuts as you wish.

The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of all cuts. When you cut a stick, it will be split into two smaller sticks (i.e. the sum of their lengths is the length of the stick before the cut). Please refer to the first example for a better explanation.

Return the minimum total cost of the cuts.

 

Example 1:


Input: n = 7, cuts = [1,3,4,5]
Output: 16
Explanation: Using cuts order = [1, 3, 4, 5] as in the input leads to the following scenario:

The first cut is done to a rod of length 7 so the cost is 7. The second cut is done to a rod of length 6 (i.e. the second part of the first cut), the third is done to a rod of length 4 and the last cut is to a rod of length 3. The total cost is 7 + 6 + 4 + 3 = 20.
Rearranging the cuts to be [3, 5, 1, 4] for example will lead to a scenario with total cost = 16 (as shown in the example photo 7 + 4 + 3 + 2 = 16).
Example 2:

Input: n = 9, cuts = [5,6,1,4,2]
Output: 22
Explanation: If you try the given cuts ordering the cost will be 25.
There are much ordering with total cost <= 25, for example, the order [4, 6, 5, 2, 1] has total cost = 22 which is the minimum possible.
 

Constraints:

2 <= n <= 106
1 <= cuts.length <= min(n - 1, 100)
1 <= cuts[i] <= n - 1
All the integers in cuts array are distinct.                   */





class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        // sort(cuts.begin(), cuts.end());

        // cuts.insert(cuts.begin(), 0);
        // cuts.push_back(n);

        // return recursion(cuts, 1, cuts.size() - 2);

        sort(cuts.begin(), cuts.end());

        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);

        vector<vector<int>> mat(cuts.size() - 1, vector<int>(cuts.size() - 1, -1));

        return memorization(cuts, 1, cuts.size() - 2, mat);
    }

    int memorization(vector<int> & cuts, int start, int end, vector<vector<int>> & mat) {
        if(start > end) return 0;

        if(mat[start][end] != -1) return mat[start][end];
        int mini = INT_MAX;

        for(int i = start; i <= end; i++) {

            int length = cuts[end + 1] - cuts[start - 1];
            int cost1 = memorization(cuts, start, i - 1, mat);
            int cost2 = memorization(cuts, i + 1, end, mat);

            int cost = length + cost1 + cost2;
            mini = min(mini, cost);
        }

        mat[start][end] = mini;
        return mini;
    }

    // int recursion(vector<int> & cuts, int start, int end) {

    //     if(start > end) return 0;

    //     int mini = INT_MAX;

    //     for(int i = start; i <= end; i++) {
    //         int length = cuts[end + 1] - cuts[start - 1]; // Length of the stick current;
    //         int cost1 = recursion(cuts, start, i - 1);
    //         int cost2 = recursion(cuts, i + 1, end);

    //         int cost = cost1 + cost2 + length;

    //         mini = min(mini, cost);
    //     }

    //     return mini;
    // }
};