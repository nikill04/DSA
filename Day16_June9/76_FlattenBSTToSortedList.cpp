/*
FLATTEN BST TO SORTED LIST:https://www.geeksforgeeks.org/problems/flatten-bst-to-sorted-list--111950/1

You are given a Binary Search Tree (BST) with n nodes, each node has a distinct value assigned to it. The goal is to flatten the tree such that, the left child of each element points to nothing (NULL), and the right child points to the next element in the sorted list of elements of the BST (look at the examples for clarity). You must accomplish this without using any extra storage, except for recursive calls, which are allowed.

Note: If your BST does have a left child, then the system will print a -1 and will skip it, resulting in an incorrect solution.

Example 1:

Input:
          5
        /    \
       3      7
      /  \    /   \
     2   4  6     8
Output: 2 3 4 5 6 7 8
Explanation: 
After flattening, the tree looks
like this
    2
     \
      3
       \
        4
         \
          5
           \
            6
             \
              7
               \
                8
Here, left of each node points
to NULL and right contains the
next node.
Example 2:

Input:
       5
        \
         8
       /   \
      7     9  
Output: 5 7 8 9
Explanation:
After flattening, the tree looks like this:
   5
    \
     7
      \
       8
        \
         9
Your Task:
You don't need to read input or print anything. Your task is to complete the function flattenBST() which takes root node of the BST as input parameter and returns the root node after transforming the tree.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= Number of nodes <= 103
1 <= Data of a node <= 105                           */









// User function Template for C++

/* Node of the binary search tree
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    // Node* Helper(Node* root) {
    //     if(root == NULL) return root;
        
    //     Node* temp1 = Helper(root -> left);
    //     while(temp1 && temp1 -> right != NULL) {
    //         temp1 = temp1 -> right;
    //     }
    //     if(temp1) {
    //         temp1 -> right = root;
    //         root -> left = temp1;
    //     }
        
    //     Node* temp2 = Helper(root -> right);
    //     while(temp2 && temp2 -> left != NULL) {
    //         temp2 = temp2 -> left;
    //     }
    //     if(temp2) {
    //         temp2 -> left = root;
    //         root -> right = temp2;
    //     }
        
    //     return root;
    // }
    
    void helperInorder(Node* root, vector<Node*> & vec) {
        if(root == NULL) return;
        
        helperInorder(root -> left, vec);
        vec.push_back(root);
        helperInorder(root -> right, vec);
    }
    
    Node *flattenBST(Node *root) {
        // code here
        // Node* ans1 = Helper(root);
        
        // while(ans1 && ans1 -> left) {
        //     ans1 = ans1 -> left;
        // }
        // Node* ans2 = ans1;
        // while(ans2 != NULL) {
        //     ans2 -> left = NULL;
        //     ans2 = ans2 -> right;
        // }
        // return ans1;
        
        vector<Node*> vec;
        helperInorder(root, vec);
        
        // for(auto i = vec.begin(); i < vec.end() - 1; i++) {
        //     (*i) -> left = NULL;    // Remember not *(i) -> left, as '->' has higher precedence that '*', so first i -> left, then '*' operator, i.e., it will be read as *(i -> left).
        //     (*i) -> right = *(i + 1);  // (*i + 1), This is incorrect iterator arithmetic. (*i) gives a Node*, and + 1 on a pointer would do pointer arithmetic (which is wrong here). You should instead use *(i + 1) or *(next(i))
        // }
        // vec.back() -> right = NULL;  // Remember not (*vec.back())
        // vec.back() -> left = NULL; 
        
        // or we can do
        // for(auto i = vec.begin(); i < vec.end(); i++) {
        //     (*i) -> left = NULL;
            
        //     if(i != vec.end() - 1) {
        //         (*i) -> right = *(i + 1);
        //     } else {
        //         (*i) -> right = NULL;
        //     }
        // }
        
        // or simply, in a regular way.
        int i = 0;
        for( ; i < vec.size() - 1; i++) {
            vec[i] -> left = NULL;
            vec[i] -> right = vec[i + 1];
        }
        vec[i] -> left = NULL;
        
        // Any of the below return statements is fine.
        return *vec.begin();
        // return vec[0];
        // return vec.front();
    }
};