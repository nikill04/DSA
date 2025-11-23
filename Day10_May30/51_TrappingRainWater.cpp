/*
TRAPPING RAIN WATER: https://leetcode.com/problems/trapping-rain-water/description/

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105                       */






class Solution {
public:
    int trap(vector<int>& height) {
        // At any index how much water stored is dependent on it's previous greater block height and also the next greater block height. 
        // Simply, if you observe you can find out that at any index, the amount of stored is min(LeftGreatest, RightGreatest) - height[i]
        if(height.size() < 3) return 0;
        stack<int> st;
        vector<int> vec1, vec2;
        int maxi = 0, total = 0;

        vec2.resize(height.size());

        for(int i = 0; i < height.size(); i++) {
            maxi = max(maxi, height[i]);
            vec1.push_back(maxi);
        }

        maxi = 0;
        for(int i = height.size() - 1; i >= 0; i--) {
            maxi = max(maxi, height[i]);
            vec2[i] = maxi;

            total += min(vec1[i], vec2[i]) - height[i];
        }

        return total;
    }
};