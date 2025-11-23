/*
IDENTICAL TREES: https://www.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1

Given two binary trees with their root nodes r1 and r2, return true if both of them are identical, otherwise, false.

Examples:

Input:
    1          1
   /   \       /   \
  2     3    2    3
Output: true
Explanation: 
There are two trees both having 3 nodes and 2 edges, both trees are identical having the root as 1, left child of 1 is 2 and right child of 1 is 3.
Input:
    1         1
   /   \      /  \
  2     3   3   2
Output: false
Explanation: There are two trees both having 3 nodes and 2 edges, but both trees are not identical.
Input:
    1   1
   /      \
  2        2
Output: false
Explanation: Although both trees have the same node values (1 and 2), they are arranged differently, making the trees non-identical.
Constraints:
1 <= number of nodes <= 105
1 <= node->data <= 109                                  */





/* A binary tree node


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    // Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2) {
        // Your Code here
        if(r1 == NULL && r2 == NULL) return true;
        else if(!r1 && r2) return false;
        else if(r1 && !r2) return false;
        
        bool a = isIdentical(r1 -> left, r2 -> left);
        bool b = isIdentical(r1 -> right, r2 -> right);
        
        if(a && b && r1 -> data == r2 -> data) return true;
        return false;
        
    }
};