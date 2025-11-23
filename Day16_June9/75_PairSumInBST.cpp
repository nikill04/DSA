/*
PAIR SUM IN BST: https://www.geeksforgeeks.org/problems/find-a-pair-with-given-target-in-bst/1

Given a Binary Search Tree(BST) and a target. Check whether there's a pair of Nodes in the BST with value summing up to the target. 

Examples:

Input: root = [7, 3, 8, 2, 4, N, 9], target = 12
       bst
Output: True
Explanation: In the binary tree above, there are two nodes (8 and 4) that add up to 12.
Input: root = [9, 5, 10, 2, 6, N, 12], target = 23
          bst-3
Output: False
Explanation: In the binary tree above, there are no such two nodes exists that add up to 23.
Constraints:

1 ≤ Number of Nodes ≤ 105
1 ≤ target ≤ 106                               */




/*
Node is as follows
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  
    // vector<int> inorder1(Node* root) {
    //     if(root == NULL) return {};
        
    //     vector<int> vec1 = inorder1(root -> left);
    //     vec1.push_back(root -> data);
    //     vector<int> vec2 = inorder1(root -> right);
        
    //     vec1.insert(vec1.end(), vec2.begin(), vec2.end());
    //     return vec1;
    // }
    
    void inorder2(Node* root, vector<int>& vec) {
        if(root == NULL) return;
        
        inorder2(root -> left, vec);
        vec.push_back(root -> data);
        inorder2(root -> right, vec);
    }
    
    bool findTarget(Node *root, int target) {
        // your code here.
        // Method 1
        // You can do one thing, which is, for every node substract that data from the target, and check whether such is present in the tree. If yes, then return it.
        // But here, O(n^2) as for every node, we are travelling entire tree. 
        
        // Method 2. 
        // As we know inorder traversal of a binary tree is in sorted order. We can proceed in that way.
        // vector<int> vec = inorder1(root);
        
        vector<int> vec;
        inorder2(root, vec);
        
        // carefully understand understand what we are doing below. And it perfectly works for finding whether two nodes are present which adds to make our target.
        for(int i = 0, j = vec.size() - 1; i < j; ) {
            if(vec[i] + vec[j] < target) { 
                i++;
            } else if(vec[i] + vec[j] > target) {
                j--;
            }
            else return true;
        }
        return false;
        
    }
};