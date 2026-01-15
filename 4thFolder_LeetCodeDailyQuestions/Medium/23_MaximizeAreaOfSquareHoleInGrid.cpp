/* MAXIMIZE AREA OF SQUARE HOLE IN GRID : https://leetcode.com/problems/maximize-area-of-square-hole-in-grid/description/?envType=daily-question&envId=2026-01-15

You are given the two integers, n and m and two integer arrays, hBars and vBars. The grid has n + 2 horizontal and m + 2 vertical bars, creating 1 x 1 unit cells. The bars are indexed starting from 1.

You can remove some of the bars in hBars from horizontal bars and some of the bars in vBars from vertical bars. Note that other bars are fixed and cannot be removed.

Return an integer denoting the maximum area of a square-shaped hole in the grid, after removing some bars (possibly none).

 

Example 1:



Input: n = 2, m = 1, hBars = [2,3], vBars = [2]

Output: 4

Explanation:

The left image shows the initial grid formed by the bars. The horizontal bars are [1,2,3,4], and the vertical bars are [1,2,3].

One way to get the maximum square-shaped hole is by removing horizontal bar 2 and vertical bar 2.

Example 2:



Input: n = 1, m = 1, hBars = [2], vBars = [2]

Output: 4

Explanation:

To get the maximum square-shaped hole, we remove horizontal bar 2 and vertical bar 2.

Example 3:



Input: n = 2, m = 3, hBars = [2,3], vBars = [2,4]

Output: 4

Explanation:

One way to get the maximum square-shaped hole is by removing horizontal bar 3, and vertical bar 4.

 

Constraints:

1 <= n <= 109
1 <= m <= 109
1 <= hBars.length <= 100
2 <= hBars[i] <= n + 1
1 <= vBars.length <= 100
2 <= vBars[i] <= m + 1
All values in hBars are distinct.
All values in vBars are distinct.            */






class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {

        // vector<bool> xBars(n + 3, true);
        // vector<bool> yBars(m + 3, true);

        // for(int i = 0; i < hBars.size(); i++) {
        //     int bar = hBars[i];
        //     xBars[bar] = false;
        // }

        // for(int j = 0; j < vBars.size(); j++) {
        //     int bar = vBars[j];
        //     yBars[bar] = false;
        // }

        // int hMax = 0;
        // int vMax = 0;

        // for(int i = 1; i < xBars.size(); i++) {
        //     int temp = 0;
        //     while(xBars[i] == false) {
        //         i++;
        //         temp++;
        //     }
        //     hMax = max(hMax, temp);
        // }

        // for(int j = 1; j < yBars.size(); j++) {
        //     int temp = 0;
        //     while(yBars[j] == false) {
        //         j++;
        //         temp++;
        //     }
        //     vMax = max(vMax, temp);
        // }

        // int minDim = min(hMax + 1, vMax + 1);

        // return minDim * minDim;



        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int hMax = 1;
        int curr = 1;
        for(int i = 1; i < hBars.size(); i++) {
            if(hBars[i] == hBars[i - 1] + 1) {
                curr++;
            }
            else {
                curr = 1;
            }
            hMax = max(hMax, curr);
        }

        int vMax = 1;
        curr = 1;
        for(int j = 1; j < vBars.size(); j++) {
            if(vBars[j] == vBars[j - 1] + 1) {
                curr++;
            }
            else {
                curr = 1;
            }
            vMax = max(vMax, curr);
        }

        int side = min(hMax + 1, vMax + 1);
        return side * side;
    }
};