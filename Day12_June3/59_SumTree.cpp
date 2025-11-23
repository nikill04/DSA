/*
SUM TREE: https://www.geeksforgeeks.org/problems/sum-tree/1

Given a Binary Tree. Check for the Sum Tree for every node except the leaf node. Return true if it is a Sum Tree otherwise, return false.

A SumTree is a Binary Tree where the value of a node is equal to the sum of the nodes present in its left subtree and right subtree. An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0. A leaf node is also considered a Sum Tree.

Examples:

Input:
    3
  /   \    
 1     2
Output: true
Explanation: The sum of left subtree and right subtree is 1 + 2 = 3, which is the value of the root node. Therefore,the given binary tree is a sum tree.
Input:
          10
        /    \
      20      30
    /   \ 
   10    10
Output: false
Explanation: The given tree is not a sum tree. For the root node, sum of elements in left subtree is 40 and sum of elements in right subtree is 30. Root element = 10 which is not equal to 30+40.
Input:
   25
  /   \    
 9     15
Output: false
Constraints:
2 ≤ number of nodes ≤ 105
1 ≤ node->data ≤ 105                            */




/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution {
  public:
    int sum(Node* root) {
        
        // if(root == NULL) return 0;
        
        // int rootSum = root -> data;
        // int leftSum = sum(root -> left);
        // int rightSum = sum(root -> right);
        
        // return rootSum + leftSum + rightSum;
    }
    
    pair<bool, int> sumTCheck(Node* root) {
        if(root == NULL) return {true, 0};
        else if(!(root -> left) && !(root -> right)) return {true, root -> data};
        
        pair<bool, int> a = sumTCheck(root -> left);
        pair<bool, int> b = sumTCheck(root -> right);
        
        if(a.first && b.first && a.second + b.second == root -> data) {
            return {true, a.second + b.second + root -> data};         // For every node we are returning it with the sum of that respective node tree. so only 1 time for all the nodes, i.e., O(n) time.
        } 
        return {false, a.second + b.second + root -> data};
    }
    
    bool isSumTree(Node* root) {
        // Your code here
        // if(!root || (root -> left == NULL && root -> right == NULL)) return true;
        
        
        // bool a = isSumTree(root -> left);
        // bool b = isSumTree(root -> right);
        // int c = sum(root -> left) + sum(root -> right);  // Here for every node we are calculating the sum of all the below nodes including itslef. So, n * n = O(n^2);
        
        // if(a && b && c == root -> data) return true;
        // return false;



        
        return sumTCheck(root).first;
    }
};
