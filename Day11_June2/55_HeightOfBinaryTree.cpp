/*
HEIGHT OF BINARY TREE: https://www.geeksforgeeks.org/problems/height-of-binary-tree/1

Given a binary tree, find its height.

The height of a tree is defined as the number of edges on the longest path from the root to a leaf node. A leaf node is a node that does not have any children.

Examples:

Input: root[] = [12, 8, 18, 5, 11] 
 
Output: 2
Explanation: One of the longest path from the root (node 12) goes through node 8 to node 5, which has 2 edges.
Input: root[] = [1, 2, 3, 4, N, N, 5, N, N, 6, 7]  

Output: 3
Explanation: The longest path from the root (node 1) to a leaf node 6 with 3 edge.
Constraints:
1 <= number of nodes <= 105
0 <= node->data <= 105          */




/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int height(Node* node) {
        // code here
        if(node == NULL) return -1;   //  If asked depth of binary tree or no. of nodes, return 0;
        int h1 = height(node -> left);
        int h2 = height(node -> right);
        return max(h1, h2) + 1;
    }
};