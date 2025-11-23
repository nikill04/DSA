/*
PALINDROME LINKED LIST: https://www.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1

Given a head singly linked list of positive integers. The task is to check if the given linked list is palindrome or not.

Examples:

Input: head: 1 -> 2 -> 1 -> 1 -> 2 -> 1
Output: true
Explanation: The given linked list is 1 -> 2 -> 1 -> 1 -> 2 -> 1 , which is a palindrome and Hence, the output is true.

Input: head: 1 -> 2 -> 3 -> 4
Output: false
Explanation: The given linked list is 1 -> 2 -> 3 -> 4, which is not a palindrome and Hence, the output is false.

Constraints:
1 <= number of nodes <= 105
1 ≤ node->data ≤ 103            */






/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution {
  public:
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head) {
        // Your code here
        if(head == NULL || head -> next == NULL) return true;
        
        Node* slow = head;
        Node* fast = head;
        
        while(fast != NULL && fast -> next != NULL) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        
        Node* secondList = reverse(slow);
        while(secondList != NULL) {
            if(head -> data == secondList -> data) {
                head = head -> next;
                secondList = secondList -> next;
            } else break;
        }
        if(secondList == NULL) return true;
        else return false;
    }
    
    Node* reverse(Node * head) {
        if(head == NULL || head -> next == NULL) return head;
        Node* temp = head -> next; 
        Node* newHead = reverse(head -> next);
        temp -> next = head;
        head -> next = NULL;
        return newHead;
    }
};

/*
class Solution{
  private:
    Node* getMid(Node* head ) {
        Node* slow = head;
        Node* fast = head -> next;
        
        while(fast != NULL && fast-> next != NULL) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        
        return slow;
    }
    Node* reverse(Node* head) {
        
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        
        while(curr != NULL) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
        
public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        if(head -> next == NULL) {
            return true;
        }
        
        //step 1 -> find Middle
        Node* middle = getMid(head);
        //cout << "Middle " << middle->data << endl;
        
        //step2 -> reverse List after Middle
        Node* temp = middle -> next;
        middle -> next = reverse(temp);
        
        //step3 - Compare both halves
        Node* head1 = head;
        Node* head2 = middle -> next;
        
        while(head2 != NULL) {
            if(head2->data != head1->data) {
                return 0;
            }
            head1 = head1 -> next;
            head2 = head2 -> next;
        }
    
        //step4 - repeat step 2
        temp = middle -> next;
        middle -> next = reverse(temp);
        
        return true;
    }
};                    */