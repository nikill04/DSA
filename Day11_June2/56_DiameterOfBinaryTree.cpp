/*
DIAMETER OF BINARY TREE: https://leetcode.com/problems/diameter-of-binary-tree/description/

Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

 

Example 1:


Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
Example 2:

Input: root = [1,2]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-100 <= Node.val <= 100           */





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
    // int height(TreeNode* root) {
    //     if(root == NULL) return -1;
    //     int h1 = height(root -> left);
    //     int h2 = height(root -> right);
    //     return max(h1, h2) + 1;
    // }

    pair<int, int> diameter(TreeNode* root) {
        if(root == NULL) {
            return {0, -1};  // Here, if node is NULL, then it's height is -1 which is okay and correct. And also when a node is NULL, it's diameter is 0 but not -1 and also you can think like, diameter of a leaf node alone is 1.
        }
        // There are three possibilities of diameter, it can either be in left subtree, right subtree or it passes throught the root node(in this last case, deepest left node to deepest right node via root.)
        pair<int, int> a = diameter(root -> left);
        pair<int, int> b = diameter(root -> right);
        int c = (a.second + 1) + (b.second + 1);

        return {max(a.first, max(b.first, c)), max(a.second, b.second) + 1}; 
    }

    int diameterOfBinaryTree(TreeNode* root) {
        // if(root == NULL) return -1;

        // int a = diameterOfBinaryTree(root -> left);
        // int b = diameterOfBinaryTree(root -> right);
        // int c = height(root -> left) + height(root -> right) + 1;  // Here we are calculating height for every node, traversing all the below nodes to find it's height. Therefore O(n^2) time complexity.

        // return max(max(a, b), c) + 1;

        pair<int, int> p = diameter(root);

        return p.first;
    }
};