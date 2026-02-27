/*
ZIGZAG TREE TRAVERSAL: https://www.geeksforgeeks.org/problems/zigzag-tree-traversal/1

Given a binary tree with n nodes. Find the zig-zag level order traversal of the binary tree.
In zig zag traversal starting from the first level go from left to right for odd-numbered levels and right to left for even-numbered levels.

Examples:

Input:
        1
      /   \
     2      3
    / \    /  \
   4   5  6    7
Output: [1, 3, 2, 4, 5, 6, 7]
Explanation:
For level 1 going left to right, we get traversal as {1}.
For level 2 going right to left, we get traversal as {3,2}.
For level 3 going left to right, we get traversal as {4,5,6,7}.
Merging all this traversals in single array we get {1,3,2,4,5,6,7}.
Input:
          7
        /   \
       9     7
     /  \   /   
    8   8  6     
   /  \
  10   9 
Output: [7, 7, 9, 8, 8, 6, 9, 10] 
Explanation:
For level 1 going left to right, we get traversal as {7}.
For level 2 going right to left, we get traversal as {7,9}.
For level 3 going left to right, we get traversal as {8,8,6}.
For level 4 going right to left, we get traversal as {9,10}.
Merging all this traversals in single array we get {7,7,9,8,8,6,9,10}.
Input:
          5
        /   \
       1     9
      / \   / \
     3   2 8   4

Output: [5, 9, 1, 3, 2, 8, 4]
Explanation:
For level 1 going left to right, we get traversal as {5}.
For level 2 going right to left, we get traversal as {9,1}.
For level 3 going left to right, we get traversal as {3,2,8,4}.
Merging all this traversals in single array we get {5,9,1,3,2,8,4}.             */





/*
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
    vector<int> zigZagTraversal(Node* root) {
        // code here
        // vector<int> vec;
        
        // helper(root, vec);
        
        // return vec;
        
        
        vector<int> vec1;
        helper1(root, vec1);
        return vec1;
        
    }
    
    void helper1(Node * root, vector<int> & vec) {
        deque<Node*> dq;
        
        dq.push_front(root);
        
        bool oddRow = true;
        
        while(!dq.empty()) {
            int N = dq.size();
            
            if(oddRow) {
                while(N--) {
                    Node* node = dq.back();
                    dq.pop_back();
                    
                    vec.push_back(node -> data);
                    
                    if(node -> left) dq.push_front(node -> left);
                    if(node -> right) dq.push_front(node -> right);
                }
            }
            else {
                while(N--) {
                    Node* node = dq.front();
                    dq.pop_front();
                    vec.push_back(node -> data);
                    
                    if(node -> right) dq.push_back(node -> right);
                    if(node -> left) dq.push_back(node -> left);
                }
            }
            
            oddRow = !oddRow;
        }
        
        return;
    }
    
    // void helper(Node* root, vector<int> & vec) {
    //     bool oddRow = true;
        
    //     deque<Node*> dq;
    //     dq.push_back(root);
        
    //     vec.push_back(root -> data);
        
    //     while(!dq.empty()) {
    //         int N = dq.size();
            
    //         if(oddRow) {
    //             while(N--) {
    //                 Node* node = dq[N];
    //                 dq.erase(dq.begin() + N);
                    
    //                 if(node -> right) {
    //                     dq.push_back(node -> right);
    //                     vec.push_back(node -> right -> data);
    //                 }
    //                 if(node -> left) {
    //                     dq.push_back(node -> left);
    //                     vec.push_back(node -> left -> data);
    //                 }
    //             } 
    //         }
    //         else {
    //             while(N--) {
    //                 Node * node = dq[N];
    //                 dq.erase(dq.begin() + N);
                    
    //                 if(node -> left) {
    //                     dq.push_back(node -> left);
    //                     vec.push_back(node -> left -> data);
    //                 }
    //                 if(node -> right) {
    //                     dq.push_back(node -> right);
    //                     vec.push_back(node -> right -> data);
    //                 }
    //             }
    //         }
            
    //         oddRow = !oddRow;
    //     }
        
    //     return;
    // }
};