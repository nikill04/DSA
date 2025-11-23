/*
NORMAL BST TO BALANCED BST: https://www.geeksforgeeks.org/problems/normal-bst-to-balanced-bst/1

Given a root of a Binary Search Tree, modify and return the given BST such that it is balanced and has minimum possible height. If there is more than one answer, return any of them.

Note: The height of balanced BST returned by you will be compared with the expected height of the balanced tree.

Examples:

Input: root[] = [30, 20, N, 10, N]
     
Output: 2
     
Explanation: The above unbalanced BST is converted to balanced with the minimum possible height i.e. 2.
Input: root[] = [4, 3, 5, 2, N, N, 6, 1, N, N, 7]
     
Output: 3
     
Explanation: The above unbalanced BST is converted to balanced with the minimum possible height i.e. 3.
Constraints:
1 <= Number of Nodes <= 105
1 <= Node -> data <= 109                            */





/*Structure of the Node of the BST is as
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
  
    void inorderHelper(Node* root, vector<int>& vec) {
        if(root == NULL) return;
        
        inorderHelper(root -> left, vec);
        vec.push_back(root -> data);
        inorderHelper(root -> right, vec);
    }
    
    Node* constructBSTHelper(vector<int>& vec, int start, int end) {
        /* 
        Here, above in parameters, you should pass "vec" by reference, not directly because,
            Node* constructBSTHelper(vector<int> vec, int start, int end)
            You pass the entire vector<int> vec by value every recursive call.

            When you do:
            constructBSTHelper(vec, start, mid - 1);
            C++ copies the whole vector every time because you wrote:
            vector<int> vec // pass by value
            So your recursion cost becomes O(N log N) extra copying cost instead of O(N).
            
            Node* constructBSTHelper(const vector<int>& vec, int start, int end)
            This way the vector is not copied at every call — you only index into it.  */
            
            
        if(end - start < 0) return NULL;
        
        int mid = start + ((end - start) / 2);
        Node* temp = new Node(vec[mid]);
        
        temp -> left = constructBSTHelper(vec, start, mid - 1);
        temp -> right = constructBSTHelper(vec, mid + 1, end);
        
        return temp;
    }
    
    // void inorder(Node* root, vector<Node*>& vec) {
    //     if(root == NULL) return;
        
    //     inorder(root -> left, vec);
    //     vec.push_back(root);
    //     inorder(root -> right, vec);
    // }
    
    // pair<Node*, int> findMid(vector<Node*> vec) {
    //     if(vec.empty()) return {};
    //     else if(vec.size() == 1) return {vec.front(), 0};
        
    //     int mid = (vec.size() / 2);
    //     // int mid = (vec.size() / 2) + 1;     // This is wrong.
    //     return {vec[mid], mid};
    // }
    
    // Node* constructBST(vector<Node*> vec) {
    //     if(vec.empty()) return NULL;
        
    //     pair<Node*, int> mid = findMid(vec);
        
    //     vector<Node*> leftVec(vec.begin(), vec.begin() + mid.second);
    //     mid.first -> left = constructBST(leftVec);
        
    //     // vector<Node*> rightVec(vec.begin() + mid.second + 1, vec.end());
    //     // mid.first -> right = constructBST(rightVec);
    //     //OR
        
    //     vec.erase(vec.begin(), vec.begin() + mid.second + 1);
    //     mid.first -> right = constructBST(vec);
        
    //     return mid.first;
    // }
    
    
    Node* balanceBST(Node* root) {
        // Code here
        // if(root == NULL) return NULL;
        
        // vector<Node*> vec;
        // inorder(root, vec);
        
        // return constructBST(vec);
        
        
        
        if(root == NULL) return NULL;
        
        vector<int> vec;
        inorderHelper(root, vec);
        
        return constructBSTHelper(vec, 0, vec.size() - 1);
    }
};