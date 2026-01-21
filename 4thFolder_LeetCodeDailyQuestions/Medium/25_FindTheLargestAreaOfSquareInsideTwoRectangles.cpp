/* FIND THE LARGEST AREA OF SQUARE INSIDE TWO RECTANGLES : https://leetcode.com/problems/find-the-largest-area-of-square-inside-two-rectangles/?envType=daily-question&envId=Invalid%20Date

There exist n rectangles in a 2D plane with edges parallel to the x and y axis. You are given two 2D integer arrays bottomLeft and topRight where bottomLeft[i] = [a_i, b_i] and topRight[i] = [c_i, d_i] represent the bottom-left and top-right coordinates of the ith rectangle, respectively.

You need to find the maximum area of a square that can fit inside the intersecting region of at least two rectangles. Return 0 if such a square does not exist.

 

Example 1:


Input: bottomLeft = [[1,1],[2,2],[3,1]], topRight = [[3,3],[4,4],[6,6]]

Output: 1

Explanation:

A square with side length 1 can fit inside either the intersecting region of rectangles 0 and 1 or the intersecting region of rectangles 1 and 2. Hence the maximum area is 1. It can be shown that a square with a greater side length can not fit inside any intersecting region of two rectangles.

Example 2:


Input: bottomLeft = [[1,1],[1,3],[1,5]], topRight = [[5,5],[5,7],[5,9]]

Output: 4

Explanation:

A square with side length 2 can fit inside either the intersecting region of rectangles 0 and 1 or the intersecting region of rectangles 1 and 2. Hence the maximum area is 2 * 2 = 4. It can be shown that a square with a greater side length can not fit inside any intersecting region of two rectangles.

Example 3:

  
Input: bottomLeft = [[1,1],[2,2],[1,2]], topRight = [[3,3],[4,4],[3,4]]

Output: 1

Explanation:

A square with side length 1 can fit inside the intersecting region of any two rectangles. Also, no larger square can, so the maximum area is 1. Note that the region can be formed by the intersection of more than 2 rectangles.

Example 4:

  
Input: bottomLeft = [[1,1],[3,3],[3,1]], topRight = [[2,2],[4,4],[4,2]]

Output: 0

Explanation:

No pair of rectangles intersect, hence, the answer is 0.

 

Constraints:

n == bottomLeft.length == topRight.length
2 <= n <= 103
bottomLeft[i].length == topRight[i].length == 2
1 <= bottomLeft[i][0], bottomLeft[i][1] <= 107
1 <= topRight[i][0], topRight[i][1] <= 107
bottomLeft[i][0] < topRight[i][0]
bottomLeft[i][1] < topRight[i][1]*/






class Solution {
public:
    // We do not care about intersection between multiple rectangles. We only want the maximum intersection area between any two rectangles.
    long long largestSquareArea(vector<vector<int>>& bottomLeft,
                                vector<vector<int>>& topRight) {

        int n = bottomLeft.size();   // Number of rectangles

        long long maxSide = 0;       // Stores the maximum possible square side length

        // Compare every pair of rectangles
        for (int i = 0; i < n; i++) {

            // Rectangle 1 coordinates
            int rect1bottX = bottomLeft[i][0];
            int rect1topX  = topRight[i][0];

            int rect1bottY = bottomLeft[i][1];
            int rect1topY  = topRight[i][1];

            // Compare rectangle i with rectangle j (j > i)
            for (int j = i + 1; j < n; j++) {

                // Rectangle 2 coordinates
                int rect2bottX = bottomLeft[j][0];
                int rect2topX  = topRight[j][0];

                int rect2bottY = bottomLeft[j][1];
                int rect2topY  = topRight[j][1];

                // Compute overlapping width (X direction)
                int side1 = min(rect2topX, rect1topX)
                            - max(rect1bottX, rect2bottX);

                // Compute overlapping height (Y direction)
                int side2 = min(rect2topY, rect1topY)
                            - max(rect1bottY, rect2bottY);

                // If rectangles do not overlap, skip
                if (side1 < 0 || side2 < 0)
                    continue;

                maxSide = max(maxSide, (long long)min(side1, side2));
            }
        }

        return maxSide * maxSide;
    }
};
