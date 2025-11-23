/*
VERTICAL TREE TRAVERSAL: https://www.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1

Given a root of a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level.
If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.

Examples:

Input: root[] = [1, 2, 3, 4, 5, 6, 7, N, N, N, N, N, 8, N, 9]
     Vertical-Taversal-          
Output: [[4], [2], [1, 5, 6], [3, 8], [7], [9]]
Explanation: The below image shows the horizontal distances used to print vertical traversal starting from the leftmost level to the rightmost level.
     
Input: root[] = [1, 2, 3, 4, 5, N, 6]
     
Output: [[4], [2], [1, 5], [3], [6]]
Explanation: From left to right the vertical order will be [[4], [2], [1, 5], [3], [6]]
Constraints:
1 <= number of nodes <= 105
1 <= node->data <= 105                 */





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
    vector<vector<int>> verticalOrder(Node *root) {
        // Your code here
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        
        queue<pair<Node*, int>> q;
        map<int, vector<int>> mp;
        q.push({root, 0});
        mp[0].push_back(root -> data);
        
        while(!q.empty()) {
            int N = q.size();
            while(N--) {
                pair<Node*, int> temp = q.front();
                q.pop();
                
                if(temp.first -> left) {
                    q.push({temp.first -> left, temp.second - 1});
                    mp[temp.second - 1].push_back(temp.first -> left -> data);
                }
                if(temp.first -> right) {
                    q.push({temp.first -> right, temp.second + 1});
                    mp[temp.second + 1].push_back(temp.first -> right -> data);
                }
            }
        }
        
        for(auto i: mp) {
            ans.push_back(i.second);  // Here, it is not mp[i].second but i.second . Observe carefully
        }
        
        /* Here if we want it an decreasing order manner. We can declare it like this above.
            1) map<int, vector<int>, greater<int>> mp;
                                OR
            2) for (auto it = mp.rbegin(); it != mp.rend(); ++it) {
                    ans.push_back(it->second);  // it->first goes from high to low
                }
        */
        
        return ans;
    }
};
