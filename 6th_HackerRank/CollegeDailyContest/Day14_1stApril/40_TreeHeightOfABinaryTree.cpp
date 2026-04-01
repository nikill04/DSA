/* TREE : HEIGHT OF A BINARY TREE : https://www.hackerrank.com/contests/iiits-ytp2026-0104/challenges/tree-height-of-a-binary-tree   */





int height(Node* root) {
    // Write your code here.
    if(!root) return -1;
    
    int left = height(root -> left);
    int right = height(root -> right);
    
    int h = max(left, right) + 1;
    
    return h;
}