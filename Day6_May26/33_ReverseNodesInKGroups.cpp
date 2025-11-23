/*
REVERSE NODES IN K GROUPS: https://leetcode.com/problems/reverse-nodes-in-k-group/description/

Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
Example 2:


Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
 

Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000
 

Follow-up: Can you solve the problem in O(1) extra memory space?             */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL) return NULL;

        ListNode* temp = head;
        int count = 0;
        while(temp != NULL && count < k) {
            temp = temp -> next;
            count++;
        }
        // If less than k nodes, return.
        if(count < k) return head;

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        int a = k;

        while(curr != NULL && a--) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }

        head -> next = reverseKGroup(curr, k);
        return prev;
    }
};