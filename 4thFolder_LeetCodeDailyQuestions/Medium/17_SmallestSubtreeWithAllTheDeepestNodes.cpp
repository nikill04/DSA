/* SMALLEST SUBTREE WITH ALL THE DEEPEST NODES : https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/description/?envType=daily-question&envId=2026-01-09

Given the root of a binary tree, the depth of each node is the shortest distance to the root.

Return the smallest subtree such that it contains all the deepest nodes in the original tree.

A node is called the deepest if it has the largest depth possible among any node in the entire tree.

The subtree of a node is a tree consisting of that node, plus the set of all descendants of that node.

 

Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4]
Output: [2,7,4]
Explanation: We return the node with value 2, colored in yellow in the diagram.
The nodes coloured in blue are the deepest nodes of the tree.
Notice that nodes 5, 3 and 2 contain the deepest nodes in the tree but node 2 is the smallest subtree among them, so we return it.
Example 2:

Input: root = [1]
Output: [1]
Explanation: The root is the deepest node in the tree.
Example 3:

Input: root = [0,1,3,null,2]
Output: [2]
Explanation: The deepest node in the tree is 2, the valid subtrees are the subtrees of nodes 2, 1 and 0 but the subtree of node 2 is the smallest.
 

Constraints:

The number of nodes in the tree will be in the range [1, 500].
0 <= Node.val <= 500
The values of the nodes in the tree are unique.
 

Note: This question is the same as 1123: https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/                  */





    // /**
    // * Definition for a binary tree node.
    // * struct TreeNode {
    // *     int val;
    // *     TreeNode *left;
    // *     TreeNode *right;
    // *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
    // *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    // *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    // * };
    // */
    class Solution {
    public:
        TreeNode* subtreeWithAllDeepest(TreeNode* root) {
            
            return dfs(root).second;




            // The below is very memory inefficient and time consuming approach. But if you want once check.
            // if(!root) return NULL;
            // if(!(root -> right || root -> left)) return root;

            // vector<TreeNode*> vec;
            // queue<TreeNode*> q;

            // q.push(root);

            // while(true) {
            //     int n = q.size();
            //     int n2 = n;
                
            //     int count = 0;
            //     while(n--) {
            //         TreeNode* node = q.front();
            //         q.pop();
            //         vec.push_back(node);

            //         if(!node) {
            //             count++;
            //             q.push(NULL);
            //             q.push(NULL);
            //         }
            //         else{
            //             q.push(node -> left);
            //             q.push(node -> right);
            //         }
            //     }

            //     if(count == n2) break;
            // }

            // int N = vec.size();
            // int noLev = log2(N + 1); // no. of actual levels + one level with all the NULL nodes

            // int start = vec.size() - (int)pow(2, noLev - 1);

            // vec.erase(vec.begin() + start, vec.end());

            // noLev--;

            // start = vec.size() - (int)pow(2, noLev - 1);

            // int onlyOne = 0;
            // TreeNode* node;
            // for(int i = start; i < vec.size(); i++) {
            //     if(vec[i] != NULL) {
            //         onlyOne++;
            //         node = vec[i];
            //     }
            // }
            // if(onlyOne == 1) return node;
            

            // unordered_map<TreeNode*, pair<int, int>> mp;

            // for(int i = start; i < vec.size(); i++) {
            //     if(vec[i] != NULL) {
            //         int parent = (i - 1) / 2;
            //         int lev = noLev - 2;

            //         for(int j = parent; j >= 0; ) {

            //             mp[vec[j]].first = lev;
            //             mp[vec[j]].second++;
            //             j = (j - 1) / 2;
            //             lev--;
            //         }
            //     }
            // }

            // pair<pair<int, int>, TreeNode*> ans = {{INT_MIN, INT_MIN}, NULL};

            // for(auto i : mp) {
            //     if((i.second.second > ans.first.second) || 
            //     (i.second.second == ans.first.second && i.second.first > ans.first.first)) {
            //         ans.first.first = i.second.first;
            //         ans.first.second = i.second.second;
            //         ans.second = i.first;
            //     }
            // } 

            // return ans.second;
        }

        pair<int, TreeNode*> dfs(TreeNode* root) {  // int => gives the maximum depth of the node's(root) subtree. TreeNode* => gives the deepest node subtree's root.
            if(!root) {
                return {0, NULL};
            }

            pair<int, TreeNode*> left = dfs(root -> left);
            pair<int, TreeNode*> right = dfs(root -> right);

            /*  Scenario A: Both sides are equally deep.
                This means the deepest nodes are split across both sides.
                So, *ROOT* is the lowest node that connects them.                    */
            if(left.first == right.first) {
                return {left.first + 1, root};
            }
            /*  Scenario B: Left side is deeper.
                The answer is already inside the left branch. Just pass it up.        */
            else if(left.first > right.first) {
                return {left.first + 1, left.second};
            }
            else {
                return {right.first + 1, right.second};
            }
        }
    };