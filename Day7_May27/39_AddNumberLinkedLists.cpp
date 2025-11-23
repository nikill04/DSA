/*
ADD NUMBER LINKED LISTS: https://www.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

Given the head of two singly linked lists num1 and num2 representing two non-negative integers. The task is to return the head of the linked list representing the sum of these two numbers.

For example, num1 represented by the linked list : 1 -> 9 -> 0, similarly num2 represented by the linked list: 2 -> 5. Sum of these two numbers is represented by 2 -> 1 -> 5.

Note: There can be leading zeros in the input lists, but there should not be any leading zeros in the output list.

Examples:

Input: num1 = 4 - > 5, num2 = 3 -> 4 -> 5
Output:  3 -> 9 -> 0
 
Explanation: Given numbers are 45 and 345. There sum is 390.
Input: num1 = 0 -> 0 -> 6 -> 3, num2 = 0 -> 7 
Output: 7 -> 0 
 
Explanation: Given numbers are 63 and 7. There sum is 70.
Constraints:
1 <= size of both linked lists <= 106
0 <= elements of both linked lists <= 9                     */





/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* addTwoLists(Node* num1, Node* num2) {
        // code here
        if(!num1) return num2;
        else if(!num2) return num1;
        
        while(num1 != NULL && num1 -> data == 0) {
            num1 = num1 -> next;
        }
        while(num2 != NULL && num2 -> data == 0) {
            num2 = num2 -> next;
        }
        
        num1 = reverse(num1);
        num2 = reverse(num2);
        
        Node* newNode = new Node(-1);
        Node* newTail = newNode;
        
        int carry = 0;
        int sum;
        while(num1 != NULL && num2 != NULL) {
            sum = num1 -> data + num2 -> data + carry;
            carry = sum % 10;
            newTail -> next = new Node(carry);
            newTail = newTail -> next;
            carry = sum / 10;
            num1 = num1 -> next;
            num2 = num2 -> next;
        }
        if(num1 == NULL && num2 != NULL) {
            while(num2 != NULL) {
                sum = carry + num2 -> data;
                carry = sum % 10;
                newTail -> next = new Node(carry);
                newTail = newTail -> next;
                carry = sum / 10;
                num2 = num2 -> next;
            }
            if(carry != 0) {
                newTail -> next = new Node(carry);
            }
        } else if(num1 != NULL && num2 == NULL) {
            while(num1 != NULL) {
                sum = carry + num1 -> data;
                carry = sum % 10;
                newTail -> next = new Node(carry);
                newTail = newTail -> next;
                carry = sum / 10;
                num1 = num1 -> next;
            }
            if(carry != 0) {
                newTail -> next = new Node(carry);
            }
        } else if(num1 == NULL && num2 == NULL && carry != 0) {
            newTail -> next = new Node(carry);
        }
        
        newNode = newNode -> next;
        newNode = reverse(newNode);
        
        return newNode;
    }
    
    Node* reverse(Node* head) {
        if(head == NULL || head -> next == NULL) return head;
        Node* temp = head -> next;
        Node* newHead = reverse(head -> next);
        temp -> next = head;
        head -> next = NULL;
        return newHead;
    }
};