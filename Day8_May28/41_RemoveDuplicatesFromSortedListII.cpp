/*
REMOVE DUPLICATES FROM SORTED LIST ii: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/

Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

 

Example 1:


Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
Example 2:


Input: head = [1,1,1,2,3]
Output: [2,3]
 

Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.                      */




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
    ListNode* deleteDuplicates(ListNode* head) {

        if(!head || !(head -> next)) return head;
        
        ListNode* travel = head;
        ListNode* prev = new ListNode(INT_MIN);
        while(travel && travel -> next) {
            if(travel -> val == travel -> next -> val) {
                int value = travel -> val;
                while(travel && travel -> val == value) {
                    travel = travel -> next;
                }
                prev -> next = travel;

                if(prev -> val == INT_MIN) {   // only when the first node is duplicate and we have to change head.
                    head = travel;
                }
            }
            else {
                prev = travel;
                travel = travel -> next;
            }
        }

        return head;




        // if(head == NULL || head -> next == NULL) return head;

        // vector<int> vec; 
        // ListNode* curr = head;
        // ListNode* prev = NULL;
        // ListNode* newHead = NULL;

        // while(curr != NULL && curr -> next != NULL) {
        //     if(curr -> val == curr -> next -> val) {
        //         vec.push_back(curr -> val);
        //         while(curr != NULL && vec[0] == curr -> val) {
        //             curr = curr -> next;
        //         }
        //         vec.pop_back();

        //         if(!prev && (curr != NULL && curr -> next != NULL) && (curr -> val != curr -> next -> val)) {
        //             prev = curr;
        //             newHead = curr;
        //             curr = curr -> next;
        //         } else if(!prev && (curr == NULL || curr -> next == NULL)) {
        //             newHead = curr;
        //         }
        //         else if(prev) prev -> next = curr;
        //     }
        //     else {
        //         if(prev) prev = prev -> next;
        //         else {
        //             prev = curr;
        //             newHead = curr;
        //         }
        //         curr = curr -> next;
        //     }
        // }
        // return newHead;
    }
};