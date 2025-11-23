/*
You are given root node of the BST and an integer key. You need to find the in-order successor and predecessor of the given key. If either predecessor or successor is not found, then set it to NULL.

Note:- In an inorder traversal the number just smaller than the target is the predecessor and the number just greater than the target is the successor. 

Examples :

Input: root[] = [8, 1, 9, N, 4, N, 10, 3, N, N, N], key = 8
Output: 4 9
Explanation: In the given BST the inorder predecessor of 8 is 4 and inorder successor of 8 is 9.

Input: root[] = [10, 2, 11, 1, 5, N, N, N, N, 3, 6, N, 4, N, N], key = 11
Output: 10 -1
Explanation: In given BST, the inorder predecessor of 11 is 10 whereas it does not have any inorder successor.

Input: root[] = [2, 1, 3], key = 3
Output: 2 -1
Explanation: In given BST, the inorder predecessor of 3 is 2 whereas it does not have any inorder successor.
Constraints: 
1 <= no. of nodes <= 10^5
1 <= node->data <= 10^6
1 <= key <= 10^6
*/

#include "bits/stdc++.h"
using namespace std;

// BST Node
class Node {
    public: 
        int data;
        Node* left;
        Node* right;

        Node (int x) {
            data = x;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
        vector<Node*> findPreSuc(Node* root, int key) {
            // code here
        }
}

Node* buildTree(string str) {
    // Corner Case
    if(str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; ) 
        ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];
        
        // If the left child is not null
        if(currVal != "N") {
            // Create the left child for the current node
            currNode -> left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size()) 
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {
            // Create the right child for the current node
            currNode -> right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode -> right);
        }
        i++;
    }
    return root;
}

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while(t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        getline(cin, s);
        int key = stoi(s);

        solution ob;
        vector<Node*> result = ob.findPreSuc(root, key);
        Node* pre = result[0];
        Node* suc = result[1];

        if(pre! = nullptr) 
            cout << pre->data << " ";
        else 
            cout << -1 << " ";

        if(suc != nullptr) 
            cout << suc->data << endl;
        else 
            cout << -1 << endl;
    }
    return 0;
}