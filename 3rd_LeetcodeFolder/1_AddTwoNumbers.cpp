/* ADD TWO NUMBERS : https://leetcode.com/problems/add-two-numbers/description/

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.           */





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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(-1);
        ListNode* head = ans;

        int sum = 0;
        int carry = 0;

        while(l1 != NULL && l2 != NULL) {
            sum = l1 -> val + l2 -> val + carry;
            carry = sum / 10;
            sum = sum % 10;

            ans -> next = new ListNode(sum);
            ans = ans -> next;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }

        while(l1 != NULL) {
            sum = carry + l1 -> val;
            ans -> next = new ListNode(sum % 10);
            carry = sum / 10;
            ans = ans -> next;
            l1 = l1 -> next;
        }

        while(l2 != NULL) {
            sum = carry + l2 -> val;
            ans -> next = new ListNode(sum % 10);
            carry = sum / 10;
            ans = ans -> next;
            l2 = l2 -> next;
        }

        if(carry != 0) {
            ans -> next = new ListNode(carry);
        }

        return head -> next;
    }
};