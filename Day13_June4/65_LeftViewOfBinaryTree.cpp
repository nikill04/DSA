/*
LEFT VIEW OF BINARY TREE: https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1

You are given the root of a binary tree. Your task is to return the left view of the binary tree. The left view of a binary tree is the set of nodes visible when the tree is viewed from the left side.

If the tree is empty, return an empty list.

Examples :

Input: root[] = [1, 2, 3, 4, 5, N, N]

Output: [1, 2, 4]
Explanation: From the left side of the tree, only the nodes 1, 2, and 4 are visible.

Input: root[] = [1, 2, 3, N, N, 4, N, N, 5, N, N]

Output: [1, 2, 4, 5]
Explanation: From the left side of the tree, the nodes 1, 2, 4, and 5 are visible.

Input: root[] = [N]
Output: []
Constraints:
0 <= number of nodes <= 106
0 <= node -> data <= 105                            */






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
    vector<int> leftView(Node *root) {
        // code here
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
                
                if(a.first -> right) {
                    q.push({a.first -> right, a.second + 1});
                    if(mp.find(a.second + 1) == mp.end()) {
                        mp[a.second + 1] = a.first -> right -> data;
                    }
                }
                if(a.first -> left) {
                    q.push({a.first -> left, a.second + 1});
                    if(mp.find(a.second + 1) == mp.end()) {
                        mp[a.second + 1] = a.first -> left -> data;
                    } 
                }
            }
        }
        
        for(auto i: mp) {
            vec.push_back(i.second);
        }
        
        return vec;
    }
};