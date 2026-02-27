/*
SUM OF NODES ON LONGEST PATH: https://www.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1

Given a binary tree root[], you need to find the sum of the nodes on the longest path from the root to any leaf node. If two or more paths have the same length, the path with the maximum sum of node values should be considered.

Examples:

Input: root[] = [4, 2, 5, 7, 1, 2, 3, N, N, 6, N]
 
Output: 13
Explanation:

The highlighted nodes (4, 2, 1, 6) above are part of the longest root to leaf path having sum = (4 + 2 + 1 + 6) = 13
Input: root[] = [1, 2, 3, 4, 5, 6, 7]

Output: 11
Explanation: 

The longest root-to-leaf path is 1 -> 3 -> 7, with sum 11.
Input: root[] = [10, 5, 15, 3, 7, N, 20, 1]

Output: 19
Explanation: 

The longest root-to-leaf path is 10 -> 5 -> 3 -> 1 with a sum of 10 + 5 + 3 + 1 = 19.
Constraints:
1 <= number of nodes <= 106
0 <= node->data <= 104                     */




/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
        return helper(root).second;
    }
    
    pair<int, int> helper(Node* root) {
        if(!root) return {-1, 0};
        
        pair<int, int> left = helper(root -> left);
        pair<int, int> right = helper(root -> right);
        
        int sum;
        if(left.first == right.first) sum = max(left.second, right.second);
        else {
            if(left.first > right.first) sum = left.second;
            else sum = right.second;
        }
        
        return {max(left.first, right.first) + 1, sum + root -> data};
    }
};





// class Solution {
//   public:
//     int max = 0;
//     int count = 0;
    
//     void maxSum(Node* root, int sum, int count1) {
//         if(root == NULL) return;
        
//         sum += root -> data;
        
        
//         /* 
//         if(count1 >= count && sum > max) {
//             count = count1;
//             max = sum;
//         }
//         We should not like this because, consider right now count is 3 and sum = 15, but now you found count1 = 4 but sum = 12, in that case sum should be updated to new value but as per the if conition, it doesn't enter the if.
//         */
//         if(!root -> left && !root -> right) {
//             if(count1 > count || (count1 == count && sum > max)) {
//                 count = count1;
//                 max = sum;
//             }
//             return // not mandatory.
//         }
        
//         // count1 += 1; 
        
//         if(root -> left) maxSum(root -> left, sum, count1 + 1);
//         if(root -> right) maxSum(root -> right, sum, count1 + 1);
        
//         return;
//     }
    
//     int sumOfLongRootToLeafPath(Node *root) {
//         // code here
//         maxSum(root, 0, 1);
//         return max;
//     }
// };
