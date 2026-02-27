/*
SORTED LINKED LIST TO BST: https://www.geeksforgeeks.org/problems/sorted-list-to-bst/1

Given a Singly Linked List which has data members sorted in ascending order. Construct a Balanced Binary Search Tree which has same data members as the given Linked List.
Note: There might be nodes with the same value.

Examples:

Input: Linked List: 1->2->3->4->5->6->7

Output: 4 2 1 3 6 5 7
Explanation : The BST formed using elements of the linked list is -
        4
      /   \
     2     6
   /  \   / \
  1   3  5   7  
Hence, preorder traversal of this tree is 4 2 1 3 6 5 7
Input: Linked List : 1->2->3->4
 
Ouput: 3 2 1 4
Explanation: The BST formed using elements of the linked list is -

Hence, the preorder traversal of this tree is 3 2 1 4
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)
 
Constraints:
1 ≤ Number of Nodes ≤ 106
1 ≤ Value of each node ≤ 106                  */




/*
struct LNode { //Linked List
    int data;
    struct LNode* next;
    LNode(int x){
        data = x;
        next = NULL; }
};
struct TNode {   //Tree
    int data;
    struct TNode* left;
    struct TNode* right;
    TNode(int x){
        data=x;
        left=right=NULL; }
}; */
class Solution {
  public:
    LNode* HelperMiddle(LNode* head) {
        LNode* slowBack = NULL;
        LNode* slow = head;
        LNode* fast = head;
        while(fast && fast -> next) {
            slowBack = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        if(slowBack) slowBack -> next = NULL;
        return slow;
    }
    
    TNode* HelperMain(LNode* head) {
        if(head == NULL) return NULL;
        
        LNode* mid = HelperMiddle(head);
        TNode* t = new TNode(mid -> data);
        
        if(head == mid) t -> left = NULL;
        else t -> left = HelperMain(head);

        t -> right = HelperMain(mid -> next);

        
        return t;
    }
    
    LNode* mergeSortMiddle(LNode* head) {
        if(!head || !head -> next) return head;
        
        LNode* slowBack = NULL;
        LNode* slow = head;
        LNode* fast = head;
        while(fast -> next && fast -> next -> next) {
            slowBack = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return ((slowBack) ? slowBack : slow); // rememeber not (slowBack) ? return slowBack : return slow;
    }
    
    LNode* merge(LNode* a, LNode* b) {
        if(!a) return b;
        else if(!b) return a;
        
        LNode* sortHead = new LNode(-1);
        LNode* sort = sortHead;
        
        while(a && b) {
            if(a -> data <= b -> data) {
                sort -> next = new LNode(a -> data);
                a = a -> next;
            } else {
                sort -> next = new LNode(b -> data);
                b = b -> next;
            }
            sort = sort -> next;
        }
        if(a) {
            sort -> next = a;
        } else {
            sort -> next = b;
        }
        // while(b) {
        //     sort -> next = new LNode(b -> data);
        //     b = b -> next;
        //     sort = sort -> next;
        // }
        
        return sortHead -> next;
    }
    
    LNode* mergeSort(LNode* head) {
        if(head == NULL || head -> next == NULL) return head;
        
        LNode* mid = mergeSortMiddle(head);
        LNode* temp = mid -> next;
        
        mid -> next = NULL;
        
        LNode* left = mergeSort(head);
        LNode* right = mergeSort(temp);
        
        return merge(left, right);
    }
    
    TNode *sortedListToBST(LNode *head) {
        // code here

        // This is when the linked list is not sorted, so we need to sort it first and then apply the same logic as in the first approach.
        // if(!head) return NULL;
        // LNode* headNew = mergeSort(head);

        // return HelperMain(headNew);
        


        if(!head) return NULL;
        return HelperMain(head);
    }
};