/* Maximum Level Sum of a Binary Tree : https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/?envType=daily-question&envId=2026-01-06

Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

Return the smallest level x such that the sum of all the values of nodes at level x is maximal.

 

Example 1:


Input: root = [1,7,0,7,-8,null,null]
Output: 2
Explanation: 
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.
Example 2:

Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
Output: 2
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-105 <= Node.val <= 105                                  */






/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        pair<int, int> ans = {INT_MIN, 0}; // first one is for max sum, and second one is for level.
        queue<TreeNode*> q;

        q.push(root);
        int level = 0;

        while(!q.empty()) {
            level++;
            int N = q.size();

            int tempSum = 0;
            while(N--) {
                TreeNode* node = q.front();
                q.pop();
                tempSum += node -> val;

                if(node -> left != NULL) {
                    q.push(node -> left);
                }
                if(node -> right != NULL) {
                    q.push(node -> right);
                }

            }

            if(tempSum > ans.first) {
                ans.first = tempSum;
                ans.second = level;
            }

            
        }
        
        return ans.second;




        // vector<int> levelSum;
        // dfs(root, 0, levelSum);

        // int maxSum = INT_MIN;
        // int bestLevel = 0;

        // for (int i = 0; i < levelSum.size(); i++) {
        //     if (levelSum[i] > maxSum) {
        //         maxSum = levelSum[i];
        //         bestLevel = i;
        //     }
        // }

        // // +1 because problem levels are 1-indexed
        // return bestLevel + 1;
    }

    // void dfs(TreeNode* node, int level, vector<int>& levelSum) {
    //     if (!node) return;

    //     // If this level is visited for the first time
    //     if (level == levelSum.size()) {
    //         levelSum.push_back(0);
    //     }

    //     levelSum[level] += node->val;

    //     dfs(node->left, level + 1, levelSum);
    //     dfs(node->right, level + 1, levelSum);
    // }
};