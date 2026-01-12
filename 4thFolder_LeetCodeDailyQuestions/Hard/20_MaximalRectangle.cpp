/* MAXIMAL RECTANGLE : https://leetcode.com/problems/maximal-rectangle/?envType=daily-question&envId=2026-01-12

Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

 

Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
Example 2:

Input: matrix = [["0"]]
Output: 0
Example 3:

Input: matrix = [["1"]]
Output: 1
 

Constraints:

rows == matrix.length
cols == matrix[i].length
1 <= rows, cols <= 200
matrix[i][j] is '0' or '1'.                          */





class Solution {
public:
    // Main function: finds the largest rectangle of '1's in the matrix
    int maximalRectangle(vector<vector<char>>& matrix) {

        // vect[j] represents the height of consecutive '1's in column j
        vector<int> vect(matrix[0].size(), 0);
        int maxi = 0;

        // Traverse each row of the matrix
        for(int i = 0; i < matrix.size(); i++) {

            // Update the histogram heights for current row
            for(int j = 0; j < matrix[i].size(); j++) {

                // If current cell is '1', increase height
                if(matrix[i][j] == '1') {
                    vect[j] += 1;
                }
                // If '0', reset height to 0
                else {
                    vect[j] = 0;
                }
            }

            // Find the largest rectangle area in current histogram
            maxi = max(maxi, maxArea(vect));
        }

        return maxi;
    }

    // Function to find largest rectangle area in a histogram
    int maxArea(vector<int> vec) {

        // st1 -> stack for nearest smaller element to the LEFT
        // st2 -> stack for nearest smaller element to the RIGHT
        stack<pair<int, int>> st1, st2;

        // vec1[i] -> how many bars current bar can extend to the LEFT
        // vec2[i] -> how many bars current bar can extend to the RIGHT
        vector<int> vec1, vec2;
        vec2.resize(vec.size());

        int maxi = 0;

        // -------- LEFT WIDTH CALCULATION --------
        for(int i = 0; i < vec.size(); i++) {

            // Pop elements until we find a smaller height
            while(!st1.empty() && st1.top().first >= vec[i]) {
                st1.pop();
            }

            // If no smaller element on the left,
            // rectangle can extend till index 0
            if(st1.empty())
                vec1.push_back(i + 1);
            else
                // Distance from nearest smaller element
                vec1.push_back(i - st1.top().second);

            // Push current bar with its index
            st1.push({vec[i], i});
        }

        // -------- RIGHT WIDTH CALCULATION --------
        for(int j = vec.size() - 1; j >= 0; j--) {

            // Pop elements until we find a smaller height
            while(!st2.empty() && st2.top().first >= vec[j]) {
                st2.pop();
            }

            // If no smaller element on the right,
            // rectangle can extend till last index
            if(st2.empty())
                vec2[j] = (vec.size() - j) - 1;
            else
                // Distance from nearest smaller element
                vec2[j] = (st2.top().second - j) - 1;

            // Push current bar with its index
            st2.push({vec[j], j});

            // Calculate area using:
            // height = vec[j]
            // width  = vec1[j] + vec2[j]
            maxi = max(maxi, (vec1[j] + vec2[j]) * vec[j]);
        }

        return maxi;
    }
};
