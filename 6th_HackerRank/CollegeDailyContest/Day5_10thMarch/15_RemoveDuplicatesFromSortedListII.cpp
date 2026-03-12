/* REMOVE DUPLICATES FROM SORTED LIST II : https://www.hackerrank.com/contests/iiits-ytp2026-1003/challenges/remove-duplicates-from-sorted-list-ii-2-1

Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

Input Format

An integer N representing the number of nodes.

N space-separated integers representing the node values in sorted order.

Constraints

0<=N<=300

-100<=Node.val<=100

The list is guaranteed to be sorted in ascending order

Output Format

Space-separated integers representing the final linked list.

Sample Input 0

7
1 2 3 3 4 4 5
Sample Output 0

1 2 5
Sample Input 1

5
1 1 1 2 3
Sample Output 1

2 3                                                */






ListNode* deleteDuplicates(ListNode* head) {
    // Write your code here
    
    ListNode* dummy = new ListNode(-1);
    dummy -> next = head;
    
    ListNode* prev = dummy;
    ListNode* curr = head;
    
    while(curr) {
        while(curr -> next && curr -> val == curr -> next -> val) {
            curr = curr -> next;
        }
        
        if(prev -> next != curr) {
            prev -> next = curr -> next;
        }
        else {
            prev = curr;
        }
        
        curr = curr -> next;
    }
    
    return dummy -> next;
}