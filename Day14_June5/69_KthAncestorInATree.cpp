/*
Kth ANCESTOR IN A TREE: https://www.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1

Given a binary tree of size  n, a node, and a positive integer k., Your task is to complete the function kthAncestor(), the function should return the kth ancestor of the given node in the binary tree. If there does not exist any such ancestor then return -1.
Note:
1. It is guaranteed that the node exists in the tree.
2. All the nodes of the tree have distinct values.

Examples :

Input: k = 2, node = 4

Output: 1
Explanation:
Since, k is 2 and node is 4, so we first need to locate the node and look k times its ancestors. Here in this Case node 4 has 1 as his 2nd Ancestor aka the root of the tree.
Input: k=1, node=3    

Output: 1
Explanation: k=1 and node=3 ,kth ancestor of node 3 is 1.
Constraints:
1<=n<=105
1<= k <= 100
1 <= Node.data <= n                         */




/*
Structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left, *right;
};
*/
// your task is to complete this function
class Solution {
  public:
    Node* KAncestor(Node* root, int & k, int node) {
        if(root == NULL) return NULL;

        
        if(root -> data == node) return root;
        
        Node* temp1 = KAncestor(root -> left, k, node);
        Node* temp2 = KAncestor(root -> right, k, node);
        
        if(!temp1 && temp2) {
            k--;
            if(k <= 0) {
                k = INT_MAX;
                return root;
            }
            return temp2;
        } else if(temp1 && !temp2) {
            k--;
            if(k <= 0) {
                k = INT_MAX;
                return root;
            }
            return temp1;
        }
        
        return NULL;
    }


    int a = -2;
  
    // void Helper(Node* root, int k, int node, vector<int> & vec) {
    //     if(root == NULL) return;
    //     else if(a != -2) return;  // Very important, don't forget
        
    //     vec.push_back(root -> data);
        
    //     if(root -> data == node) {
    //         for(int i = k; i >= 1 && !vec.empty(); i--) {
    //             vec.pop_back();
    //         }
    //         if(!vec.empty()) a = vec.back();
    //         else a = -1;
    //         return;
    //     }
        
    //     Helper(root -> left, k, node, vec);
    //     Helper(root -> right, k, node, vec);
        
    //     vec.pop_back();
    //     // if we don't write if(a != -2) return; condition then here we have to write if(!vec.empty()) vec.pop_back();
    // }
    
    int kthAncestor(Node *root, int k, int node) {
        // Code here
        // vector<int> vec;
        // Helper(root, k, node, vec);
        // return a;


        
        Node* ans = KAncestor(root, k, node);
        if(ans == NULL || ans -> data == node) return -1;
        return ans -> data;
    }
};
