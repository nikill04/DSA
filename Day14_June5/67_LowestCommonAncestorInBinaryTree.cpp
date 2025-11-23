/*
LOWEST COMMON ANCESTOR IN BINARY TREE: https://www.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1

Given a Binary Tree with all unique values and two nodes value, n1 and n2. The task is to find the lowest common ancestor of the given two nodes. We may assume that either both n1 and n2 are present in the tree or none of them are present.

LCA: It is the first common ancestor of both the nodes n1 and n2 from bottom of tree.

Examples:

Input: root = [1,2,3,4,5,6,7], n1 = 5 , n2 = 6

      
Output: 1
Explanation: LCA of 5 and 6 is 1.
Input: root = [5, 2, N, 3, 4], n1 = 3 , n2 = 4 

           5    
          /    
         2  
        / \  
       3   4
Output: 2
Explanation: LCA of 3 and 4 is 2. 
Input: root = [5, 2, N, 3, 4], n1 = 5 , n2 = 4 

           5    
          /    
         2  
        / \  
       3   4
Output: 5
Explanation: LCA of 5 and 4 is 5. 
Constraints:
1 ≤ number of nodes ≤ 105
1 ≤ node->data ≤ 105                                   */






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
       
       // Node* findLCA(Node* root, int n1, int n2, bool& foundN1, bool& foundN2) {
       //        if (root == NULL) return NULL;

       //        Node* left = findLCA(root->left, n1, n2, foundN1, foundN2);
       //        Node* right = findLCA(root->right, n1, n2, foundN1, foundN2);

       //        if (root->data == n1) {
       //        foundN1 = true;
       //        return root;
       //        }

       //        if (root->data == n2) {
       //        foundN2 = true;
       //        return root;
       //        }

       //        if (left && right) return root;

       //        return left ? left : right;
       
       // }

       
       // Function to return the lowest common ancestor in a Binary Tree.
       Node* lca(Node* root, int n1, int n2) {
              // Your code here
              // if(root == NULL) return NULL;
              
              // Node* temp1 = lca(root -> left, n1, n2);
              // Node* temp2 = lca(root -> right, n1, n2);
              
              // if(temp1 && temp2) return root;
              // else if(!temp1 && !temp2 && (root -> data == n1 || root -> data == n2)) return root;
              // else if(!temp1 && !temp2) return NULL;
              // else if(!temp1 && temp2 && (root -> data == n1 || root -> data == n2)) return root;
              // else if(temp1 && !temp2 && (root -> data == n1 || root -> data == n2)) return root;
              // else if(temp1 && !temp2) return temp1;
              // else if(!temp1 && temp2) return temp2;
              
              // return NULL;



              if (root == NULL) return NULL;

              if (root->data == n1 || root->data == n2) return root;

              Node* leftLCA = lca(root->left, n1, n2);
              Node* rightLCA = lca(root->right, n1, n2);

              if (leftLCA && rightLCA) return root;

              return (leftLCA != NULL) ? leftLCA : rightLCA;


              /*
              The above two codes, if only one node present in the tree case  — it just returns the present node, assuming it's the LCA.
              But if you want to be strict (i.e., retxurn NULL unless both nodes are present), the two codes won’t do that.*/

              // If we want it to be strict(but the question is asks strictly for not strict case, the below code is just in case, how to do it, for knowing)

              // bool foundN1 = false, foundN2 = false;

              // Node* lcaNode = findLCA(root, n1, n2, foundN1, foundN2);

              // // Return LCA only if both nodes were found
              // if (foundN1 && foundN2)
              // return lcaNode;

              // return NULL;
        
       }
};