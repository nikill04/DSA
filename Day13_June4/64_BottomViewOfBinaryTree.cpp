/*
BOTTOM VIEW OF BINARY TREE: https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

Given a binary tree, return an array where elements represent the bottom view of the binary tree from left to right.

Note: If there are multiple bottom-most nodes for a horizontal distance from the root, then the latter one in the level traversal is considered. For example, in the below diagram, 3 and 4 are both the bottommost nodes at a horizontal distance of 0, here 4 will be considered.

                      20
                    /    \
                  8       22
                /   \     /   \
              5      3 4     25
                     /    \      
                 10       14

For the above tree, the output should be 5 10 4 14 25.

Examples :

Input:
       1
     /   \
    3     2
Output: 3 1 2
Explanation: First case represents a tree with 3 nodes and 2 edges where root is 1, left child of 1 is 3 and right child of 1 is 2.

Thus bottom view of the binary tree will be 3 1 2.
Input:
         10
       /    \
      20    30
     /  \
    40   60
Output: 40 20 60 30
Input:
        1
       /   
      2
Output: 2 1
Constraints:
1 <= number of nodes <= 105
1 <= node->data <= 105                         */







// Function to return a list containing the bottom view of the given tree.

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // Your Code Here
        vector<int> vec;
        if(root == NULL) return vec;
        
        queue<pair<Node*, int>> q;
        map<int, int> mp;
        
        q.push({root, 0});
        mp[0] = root -> data;
        
        while(!q.empty()) {
            int N = q.size();
            while(N--) {
                pair<Node*, int> a = q.front();
                q.pop();
                
                if(a.first -> left) {
                    q.push({a.first -> left, a.second - 1});
                    mp[a.second - 1] = a.first -> left -> data;
                }
                if(a.first -> right) {
                    q.push({a.first -> right, a.second + 1});
                    mp[a.second + 1] = a.first -> right -> data;
                }
            }
        }
        
        for(auto j : mp) {
            vec.push_back(j.second);
        }
        
        return vec;
    }
};