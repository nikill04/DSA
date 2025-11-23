/*
TREE BOUNDARY TRAVERSAL: https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

Left Boundary: This includes all the nodes on the path from the root to the leftmost leaf node. You must prefer the left child over the right child when traversing. Do not include leaf nodes in this section.

Leaf Nodes: All leaf nodes, in left-to-right order, that are not part of the left or right boundary.

Reverse Right Boundary: This includes all the nodes on the path from the rightmost leaf node to the root, traversed in reverse order. You must prefer the right child over the left child when traversing. Do not include the root in this section if it was already included in the left boundary.

Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 

Examples:

Input: root[] = [1, 2, 3, 4, 5, 6, 7, N, N, 8, 9, N, N, N, N]
Output: [1, 2, 4, 8, 9, 6, 7, 3]
Explanation:

Input: root[] = [1, 2, N, 4, 9, 6, 5, N, 3, N, N, N, N 7, 8]
Output: [1, 2, 4, 6, 5, 7, 8]
Explanation:












As the root doesn't have a right subtree, the right boundary is not included in the traversal.
Input: root[] = [1, N, 2, N, 3, N, 4, N, N] 
    1
     \
      2
       \
        3
         \
          4

Output: [1, 4, 3, 2]
Explanation:
Left boundary: [1] (as there is no left subtree)
Leaf nodes: [4]
Right boundary: [3, 2] (in reverse order)
Final traversal: [1, 4, 3, 2]
Constraints:
1 ≤ number of nodes ≤ 105
1 ≤ node->data ≤ 105                               */




/*
// Tree Node
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
    vector<int> vec;
    
    void leftBoundary(Node* root) {
        // if(!root -> left && !root -> right) return;
        
        // vec.push_back(root -> data);
        // if(root -> left) leftBoundary(root -> left);
        // else if(root -> right) leftBoundary(root -> right);
        
        while(root -> left || root -> right) {
            vec.push_back(root -> data);
            if(root -> left) root = root -> left;
            else if(root -> right) root = root -> right;
        }
    }
    
    void inorderTraversal(Node* root) {  // It can be any traversal, not only inorder
        if(root == NULL) return;
        
        inorderTraversal(root -> left);
        if(!root -> right && !root -> left) vec.push_back(root -> data);
        inorderTraversal(root -> right);
    }
    
    void reverseRight(Node* root) {
        if(!root -> left && !root -> right) return;
        
        if(root -> right) reverseRight(root -> right);
        else if(root -> left) reverseRight(root -> left);
        vec.push_back(root -> data);
    }
    
    vector<int> boundaryTraversal(Node *root) {
        // code here
        if(root == NULL) return vec;
        vec.push_back(root -> data);
        if(!root -> left && !root -> right) return vec;
        
        if(root -> left) leftBoundary(root -> left);
        inorderTraversal(root);
        if(root -> right) reverseRight(root -> right);
        
        return vec;
    }
};




/*
void traverseLeft(Node* root, vector<int> &ans) {
    //base case
    if( (root == NULL) || (root->left == NULL && root->right == NULL) )
        return ;
        
    ans.push_back(root->data);
    if(root->left)
        traverseLeft(root->left, ans);
    else
        traverseLeft(root->right, ans);
        
}

void traverseLeaf(Node* root, vector<int> &ans) {
    //base case
    if(root == NULL)
        return ;
        
    if(root->left == NULL && root->right == NULL) {
        ans.push_back(root->data);
        return;
    }
    
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
    
}
    
void traverseRight(Node* root, vector<int> &ans) {
    //base case
    if( (root == NULL) || (root->left == NULL && root->right == NULL) )
        return ;
    
    if(root->right)
        traverseRight(root->right, ans);
    else
        traverseRight(root->left, ans);
        
    //wapas aagye
    ans.push_back(root->data);
        
}

vector <int> boundary(Node *root)
{
    vector<int> ans;
    if(root == NULL)
        return ans;
        
    ans.push_back(root->data);
    
    //left part print/store
    traverseLeft(root->left, ans);
    
    //traverse Leaf Nodes
    
    //left subtree
    traverseLeaf(root->left, ans);
    //right subtree
    traverseLeaf(root->right, ans);
    
    //traverse right part
    traverseRight(root->right, ans);
    
    return ans;     
}
    
*/