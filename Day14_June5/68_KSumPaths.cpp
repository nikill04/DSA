/*
K SUM PATHS: https://www.geeksforgeeks.org/problems/k-sum-paths/1

Given a binary tree and an integer k, determine the number of downward-only paths where the sum of the node values in the path equals k. A path can start and end at any node within the tree but must always move downward (from parent to child).

Examples:

Input: k = 7   

Output: 3
Explanation: The following paths sum to k 
 
Input: k = 3

Output: 2 
Explanation: Path 1 : 1 -> 2 (Sum = 3) Path 2 : 3 (Sum = 3)

Constraints:
1 ≤ number of nodes ≤ 104
-100 ≤ node value ≤ 100
-109 ≤ k ≤ 109                                              */






/*
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
        int a = 0;
        
        // for a particular node, This Helper function, calculates no. of all downward paths leading to count k, from that particular node.
        // void Helper(Node* root, int k, int sum) {
        //     if(root == NULL) return;
            
        //     sum = sum + root -> data;
        //     if(sum == k) a += 1;         // Observe that here we are not returning once we reached k, because after that also again negative nodes and positive nodes maybe there again leading to sum == k. so, we are not returing.
            
        //     Helper(root -> left, k, sum);
        //     Helper(root -> right, k, sum);
        // }
        
        // This Helper1 function sends all the nodes to Helper function.
        // void Helper1(Node* root, int k) { 
        //     if(root == NULL) return;
            
        //     Helper(root, k, 0);
            
        //     Helper1(root -> left, k);
        //     Helper1(root -> right, k);
        // }


        void kSum(Node* root, int k, vector<int> & vec) {
            if(root == NULL) return;
            
            vec.push_back(root -> data);
            
            if(root -> left) kSum(root -> left, k, vec);
            if(root -> right) kSum(root -> right, k, vec);
            
            int sum = 0;
            for(auto i = vec.end() - 1; i >= vec.begin(); i--) {
                sum += *(i);
                if(sum == k) a++;
            }
            vec.pop_back();        
        }
        
        int sumK(Node *root, int k) {
            // code here
            // Helper1(root, k);
            
            // return a;

            // The above one is correct, but it takes too much time, O(n^2). So, sometimes it won't execute due to the time factor.


            vector<int> vec;        
            kSum(root, k, vec);            
            return a;
            /* 
            but isn't in also approach 2 aren't we adding all values in the vector one by one, at every node, isn't this also makes time complexity as O(n^2) everytime. same as O(n^2) as in approach 1, then how come approach 2 is better than approach 1?


            You're correct that in the worst case, both approaches have time complexity O(n²).
            But the key is why Approach 2 is still better in practice — and that's what we’ll explain clearly now.

            ✅ Let’s analyze both approaches precisely.
            🔁 Approach 1 — DFS from every node
            
            void Helper1(Node* root, int k) {
                if (root == NULL) return;
                Helper(root, k, 0);         // ← does full DFS from this node
                Helper1(root->left, k);
                Helper1(root->right, k);
            }
            You visit each node n, and from each, you do a full traversal of its subtree.

            So the same nodes are visited again and again in different traversals.

            Worst-case time: O(n) + O(n-1) + O(n-2) + ... + O(1) = O(n²)
            This redundancy is real even in balanced trees.

            ✅ Approach 2 — One DFS, maintain path vector
    
            vector<int> vec;
            kSum(root, k, vec);
            In kSum, for each node, you: Append the node’s value to vec (O(1))

            Traverse the vector backwards to compute suffix sums.

            At each node, the maximum suffix loop does is O(h) where h is the height of the path from root to current node.

            In a balanced binary tree, the height h ≈ log n.
            So average time at each node: O(log n)
            And total time: n * log n = O(n log n)
            Only in a worst-case skewed tree (like a linked list), where height h = n, this becomes O(n²).
            But that's rare — and still, it's a single traversal, not repeating work like Approach 1.           */
        }
};