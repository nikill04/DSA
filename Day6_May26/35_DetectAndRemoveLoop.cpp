/*
DETECT AND REMOVE LOOP: https://www.naukri.com/code360/problems/interview-shuriken-42-detect-and-remove-loop_241049

Given a singly linked list, you have to detect the loop and remove the loop from the linked list, if present. You have to make changes in the given linked list itself and return the updated linked list.

Expected Complexity: Try doing it in O(n) time complexity and O(1) space complexity. Here, n is the number of nodes in the linked list.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= N <= 100000.
1 <= ‘VAL’ <= 1000 .  

Time limit: 1 sec
Sample Input:
6 2
1 2 3 4 5 6 
Sample Output:
1 2 3 4 5 6
Explanation:
For the given input linked list, the last node is connected to the second node as:

Now, after detecting and removing this loop the linked list will be:                    */





/*************************************************
    
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

*************************************************/
#include <bits/stdc++.h>

Node *removeLoop(Node *head)
{
    // Write your code here.
    if(head -> next == NULL) return head;
    Node* temp1 = head;
    Node* temp2 = head;
    unordered_set<Node*> uset;
    uset.insert(temp1);
    temp1 = temp1 -> next;

    while(uset.find(temp1) == uset.end() && temp1 != NULL) {
        uset.insert(temp1);
        temp1 = temp1 -> next;
        temp2 = temp2 -> next;
    }

    temp2 -> next = NULL;
    return head;



    // if(head == NULL || head -> next == NULL) return head;
    // Node* slow = head;
    // Node* fast = head;

    // do {
    //     slow = slow -> next;
    //     fast = fast -> next -> next;
    // } while(!(fast == NULL || fast -> next == NULL) && fast != slow && !(fast == head || fast -> next == head));
    // // Remeber null checks are very important and should be done in first and should be done in an order. Here !(fast -> next == NULL || fast == NULL) gives an error. this whole bracket should be at the first and also in the bracket it should be in that order only.


    // // Similary here also the NULL check should be the first if condition and also in that bracket the order should be like this only.
    // if(fast == NULL || fast -> next == NULL) return head;
    // else if(fast -> next == head) {
    //     fast -> next = NULL;
    //     return head;
    // } else if(fast == head) {
    //     while(fast -> next != head) {
    //         fast = fast -> next;
    //     }
    //     fast -> next = NULL;
    //     return head;
    // } 

    // fast = head;
    // while(fast -> next != slow -> next) {
    //     fast = fast -> next;
    //     slow = slow -> next;
    // }
    // slow -> next = NULL;
    // return head;




    // OR THE BELOW ONE IS FLOYD LOOP DETECTION AND REMOVAL
    //     if (head == NULL || head->next == NULL)
    //         return head;

    //     Node *slow = head;
    //     Node *fast = head;

    //     // Step 1: Detect loop using Floyd’s algorithm
    //     while (fast && fast->next)
    //     {
    //         slow = slow->next;
    //         fast = fast->next->next;

    //         if (slow == fast)
    //             break; // Loop detected
    //     }

    //     // Step 2: If no loop found, return
    //     if (fast == NULL || fast->next == NULL)
    //         return head;

    //     // Step 3: Find the start of the loop
    //     slow = head;
    //     if (slow == fast)
    //     {
    //         // Loop starts at head, find the last node in the loop
    //         while (fast->next != slow)
    //         {
    //             fast = fast->next;
    //         }
    //     }
    //     else
    //     {
    //         // Move both one step at a time to find the node before the loop start
    //         while (slow->next != fast->next)
    //         {
    //             slow = slow->next;
    //             fast = fast->next;
    //         }
    //     }

    //     // Step 4: Break the loop
    //     fast->next = NULL;

    //     return head;
    /*
    when the **loop starts at the head** (i.e. there is no “tail” leading into the cycle and the cycle length is the entire list), Floyd’s pointers will **always** first meet back at the head. Here’s why:

1. **Setup**

   * Let the list have $N$ nodes, numbered $0$ through $N-1$.
   * Node $N-1$ points back to node $0$.
   * On each step, `slow` advances by +1, `fast` by +2, with everything taken “mod N” (because it wraps around the cycle).

2. **Meeting time**

   * After t steps,

     slow=(0+t)modN,fast=(0+2t)modN.
   * They meet when

     (0+t)modN=(0+2t)modN⟹t≡2t(modN)⟹t≡0(modN
   * The **smallest positive** t satisfying that is t = N.
   * At t=N,

     slow=NmodN=0,fast=2NmodN=0.

     which is the **head** (node 0).

So in a pure cycle of length $N$, the very first time the two pointers collide is **after $N$ steps**, and they collide **at the head**. Hence the special check

```cpp
if (slow == fast) {
    // here slow == fast == head
    // so we know the loop starts at head
    …
}
```

is both necessary and sufficient. There is **no** configuration where a loop that **begins at the head** would make `slow` and `fast` first meet somewhere else.              

if you want to see
Example 1: Cycle A -> B -> C -> A (Cycle Length 3)
t=0: Slow = A, Fast = A.
t=1: Slow = B (A -> B), Fast = C (A -> B -> C).
t=2: Slow = C (B -> C), Fast = B (C -> A -> B).
t=3: Slow = A (C -> A), Fast = A (B -> C -> A).
At t=3, Slow = A and Fast = A. They meet at the head (A) after 3 steps, which equals the cycle length.

Example 2: Cycle A -> B -> A (Cycle Length 2)
t=0: Slow = A, Fast = A.
t=1: Slow = B (A -> B), Fast = A (A -> B -> A).
t=2: Slow = A (B -> A), Fast = A (A -> B -> A).
At t=2, they meet at A, the head, after 2 steps, matching the cycle length.

Example 3: Cycle A -> A (Cycle Length 1)
t=0: Slow = A, Fast = A.
t=1: Slow = A (A -> A), Fast = A (A -> A -> A).
They meet at A immediately at t=1, again at the head.

Example 4: Cycle A -> B -> C -> D -> E -> A (Cycle Length 5)
t=0: Slow = A, Fast = A.
t=1: Slow = B, Fast = C (A -> B -> C).
t=2: Slow = C, Fast = E (C -> D -> E).
t=3: Slow = D, Fast = B (E -> A -> B).
t=4: Slow = E, Fast = D (B -> C -> D).
t=5: Slow = A (E -> A), Fast = A (D -> E -> A).
They meet at A at t=5, the cycle length.*/
}