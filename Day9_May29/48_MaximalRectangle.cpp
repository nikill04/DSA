/*
MAXIMAL RECTANGLE: https://leetcode.com/problems/maximal-rectangle/description/

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
1 <= row, cols <= 200
matrix[i][j] is '0' or '1'.              */





class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> vect(matrix[0].size(), 0);
        int maxi = 0;

        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                if(matrix[i][j] == '1') {
                    vect[j] += 1;
                } else {
                    vect[j] = 0;
                }
            }
            maxi = max(maxi, maxArea(vect));
        }
        return maxi;
    }

    int maxArea(vector<int> vec) {
        stack<pair<int, int>> st1, st2;
        vector<int> vec1, vec2;
        vec2.resize(vec.size());
        int maxi = 0;

        for(int i = 0; i < vec.size(); i++) {
            while(!st1.empty() && st1.top().first >= vec[i]) {
                st1.pop();
            }
            if(st1.empty()) vec1.push_back(i + 1);
            else vec1.push_back(i - st1.top().second);

            st1.push({vec[i], i});
        }

        for(int j = vec.size() - 1; j >= 0; j--) {
            while(!st2.empty() && st2.top().first >= vec[j]) {
                st2.pop();
            }
            if(st2.empty()) vec2[j] = (vec.size() - j) - 1;
            else vec2[j] = (st2.top().second - j) - 1;

            st2.push({vec[j], j});

            maxi = max(maxi, (vec1[j] + vec2[j]) * vec[j]);
        }
        return maxi;
    }
};