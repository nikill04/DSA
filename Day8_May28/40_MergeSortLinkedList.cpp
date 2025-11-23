/*
MERGESORT LINKED LIST: https://www.naukri.com/code360/problems/mergesort-linked-list_630514

For a given Singly Linked List of integers, sort the list using the 'Merge Sort' algorithm.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= N <= 10^5
1 <= DATA <= 10^9

Where 'DATA' denotes the value of node of Linked List.

Time Limit: 1sec
Sample Input 1 :
1 4 5 2 -1
Sample Output 1 :
1 2 4 5
Sample Input 2 :
10 9 8 7 6 5 4 -1
Sample Output 2 :
4 5 6 7 8 9 10                         */




/********************************************************************

    Following is the representation of the Singly Linked List Node:

    class node{
        public:
            int data;
            node * next;
            node(int data){
                this->data=data;
                this->next=NULL;
            }
    };
    
********************************************************************/

node* findMid(node * head) {
    node* fast = head;
    node* slow = head;

    node* slowBack = head;
    while(fast != NULL && fast -> next != NULL) {
        slowBack = slow;
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slowBack;
}

node* merge(node* a, node* b) {
    if(a == NULL) return b;
    if(b == NULL) return a;
    node* sort = new node(-1);
    node* sortHead = sort;
    while(a != NULL && b != NULL) {
        if(a -> data <= b -> data) {
            sort -> next = a;
            a = a -> next;
            sort = sort -> next;
        } else {
            sort -> next = b;
            b = b -> next;
            sort = sort -> next;
        }
    }
    while(a != NULL) {
        sort -> next = a;
        a = a -> next;
        sort = sort -> next;
    }
    while(b != NULL) {
        sort -> next = b;
        b = b -> next;
        sort = sort -> next;
    }
    return sortHead -> next;
}


node* mergeSort(node *head) {
    // Write your code here.
    if(head == NULL || head -> next == NULL) return head;

    node* mid = findMid(head);
    node* temp = mid -> next;
    mid -> next = NULL;

    node* a = mergeSort(head);
    node* b = mergeSort(temp);

    return merge(a, b);
}

/*
node* findMid(node* head) {
    node* slow = head;
    node* fast = head -> next;
    
    while(fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next; 
    }
    return slow;
}

node* merge(node* left, node* right) {
    
    if(left == NULL)
        return right;
    
    if(right == NULL)
        return left;
    
    node* ans = new node(-1);
    node* temp = ans;
    
    //merge 2 sorted Linked List
    while(left != NULL && right != NULL) {
        if(left -> data < right -> data ) {
            temp -> next = left;
            temp = left;
            left = left -> next;
        }
        else
        {
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
    }
    
    while(left != NULL) {
        temp -> next = left;
        temp = left;
        left = left -> next;
    }
    
    while(right != NULL) {
        temp -> next = right;
        temp = right;
        right = right -> next;
    }
    
    ans = ans -> next;
    return ans;
    
}
    
node* mergeSort(node *head) {
    //base case
    if( head == NULL || head -> next == NULL ) {
        return head;
    }
    
    // break linked list into 2 halvs, after finding mid
    node* mid = findMid(head);
    
    node* left = head;
    node* right = mid->next;
    mid -> next = NULL;
    
    //recursive calls to sort both halves
    left = mergeSort(left);
    right = mergeSort(right);
    
    //merge both left and right halves
    node* result = merge(left, right);
    
    return result;
}   */