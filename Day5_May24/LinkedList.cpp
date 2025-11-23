/*
class Node {
    public:
        int data;
        Node* next;

    // CONSTRUCTOR
    Node(int data) {
        this -> data = data;
        this -> next = null;
    }
    
    // DESTRUCTOR
    Node() {
        int value = this -> data;
        // memory free
        if(this -> next != NULL) {
            delete next;
            this -> next = NULL;
        }
        cout << "Memory is free for node with data" << value << endl;
    }
}

void insertAtHead(Node* head, int d) {
    Node * temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node * tail, int d) {
    Node * temp = new Node(d);
    tail -> next = temp;
    tail = temp;
}


void Print(Node * head) {
    if(head == NULL) return;
    Node * temp = head;
    while(temp != NULL) {
        cout << tmep -> data;
        temp = temp ->next;
    }
}

void insertAtPosition(Node* tail, Node * head, int position, int d) {
    if(position == 1) {
        insertAtHead(head, d);
        return;
    }
    Node* temp = head;
    int count = 1;
    while(count < position - 1) {
        temp = temp -> next;
        count++;
    }
    // Inserting at Tail Position
    if(temp -> next == NULL) {
        insertAtTail(tail, d);
        return;
    }
    
    // Create
    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
}

void deleteNode(int position, Node* head) {
    if(position == 1) {
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
    } else {
        Node * curr = head;
        Node * prev = NULL;
        int count = 1;
        while(count < position - 1) {
            prev = curr;
            curr = curr -> next;
            count++;
        } 
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
}


// CHECKING WHETHER A L.L is CIRCULAR LINKED LIST OR NOT
bool checkCircularLL(Node* head) {
    if(head == NULL) return true;
    
    Node* temp = head -> next;
    while(temp != NULL && temp != head) {
        temp = temp -> next;
    }
    if(temp == head) {
        return true;
    }
    return false;
}

*/