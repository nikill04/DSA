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





/*Structure of the node of the binary tree is as
struct Node {
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
    // Function to store the zig zag order traversal of tree in a list.
    vector<int> zigZagTraversal(Node* root) {
        // Code here
        vector<int> vec;
        deque<Node*> dq;
        int count = 0;
        
        dq.push_front(root);
        count++;
        vec.push_back(root -> data);
        
        while(!dq.empty()) {
            int N = dq.size();
            while(N) {
                Node* temp;
                if(count % 2 == 1) {
                    temp = dq[--N];
                    dq.erase(dq.begin() + N);
                    
                    if(temp -> right) {
                        dq.push_back(temp -> right);
                        vec.push_back(temp -> right -> data);
                    }
                    if(temp -> left) {
                        dq.push_back(temp -> left);
                        vec.push_back(temp -> left -> data);
                    }
                } else {
                    temp = dq[--N];
                    dq.erase(dq.begin() + N);
                    
                    if(temp -> left) {
                        dq.push_back(temp -> left);
                        vec.push_back(temp -> left -> data);
                    }
                    if(temp -> right) {
                        dq.push_back(temp -> right);
                        vec.push_back(temp -> right -> data);
                    }
                }
            }
            count++;
        }
        return vec;
    }
};