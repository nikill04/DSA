/*
BALANCED TREE CHECK: https://www.geeksforgeeks.org/problems/check-for-balanced-tree/1

Given a binary tree, determine if it is height-balanced. A binary tree is considered height-balanced if the absolute difference in heights of the left and right subtrees is at most 1 for every node in the tree.

Examples:

Input: root[] = [10, 20, 30, 40, 60]

   
Output: true
Explanation: The height difference between the left and right subtrees at all nodes is at most 1. Hence, the tree is balanced.
Input: root[] = [1, 2, 3, 4, N, N, N, 5]
   
Output: false
Explanation: The height difference between the left and right subtrees at node 2 is 2, which exceeds 1. Hence, the tree is not balanced.
Input: root[] = [1, 2, N, N, 3]
   
Output: false
Explanation: The height difference between the left and right subtrees at node 1 is 2, which exceeds 1. Hence, the tree is not balanced.
Constraints:
0 <= number of nodes <= 5000
- 104 <= node->data <= 104                              */





/* A binary tree node structure

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
 */

class Solution {
  public:
  
    // int height(Node* root) {
    //     if(root == NULL) return -1;
        
    //     int a = height(root -> left);
    //     int b = height(root -> right);
        
    //     return max(a, b) + 1;
    // }
    
    pair<bool, int> balanceCheck(Node* root) {
        if(root == NULL) return {true, -1};
        
        pair<bool, int> a = balanceCheck(root -> right);
        pair<bool, int> b = balanceCheck(root -> left);
        
        int c = a.second - b.second;
        
        if(a.first && b.first && (c >= -1 && c <= 1)) {
            return {true, max(a.second, b.second) + 1};
        }
        return {false, max(a.second, b.second) + 1};
    }
    
    bool isBalanced(Node* root) {
        // Code here
        
        // if(!root || !(root -> left) && !(root -> right)) return true;
        
        // bool a = isBalanced(root -> right);
        // bool b = isBalanced(root -> left);
        
        // int c = height(root -> left) - height(root -> right);
        
        // if(a && b && (c >= -1 && c <= 1)) return true;
        // return false;
        
        
        return balanceCheck(root).first;
    }
};



/*
pair<bool, int> isBalancedFast(Node* root) {
                // base case
        if(root == NULL)
        {
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }
        
        pair<int,int> left = isBalancedFast(root->left);
        pair<int,int> right = isBalancedFast(root->right);
        
        
        bool leftAns = left.first;
        bool rightAns = right.first;
        
        bool diff = abs (left.second - right.second ) <=1;
        
        pair<bool,int> ans;
        ans.second = max(left.second, right.second) + 1;
        
        if(leftAns && rightAns && diff) {
           ans.first = true;
        }
        else
        {
            ans.first = false;
        }
        return ans;
    }
    bool isBalanced(Node *root)
    {
        return isBalancedFast(root).first;
    }                     */