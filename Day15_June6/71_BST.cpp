class Node {
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data) {
            this -> data = data;
            this -> left = NULL;
            this -> right = NULL;
        }
}

Node* insertIntoBST(Node* root, int data) {
    if(root == NULL) {
        root = new Node(data);
        return root;
    } else if(data > root -> data) {
        root -> right = insertIntoBST(root -> right, data);
    } else {
        root -> left = insertIntoBST(root -> left, data);
    }

    return root;
}

Node* deletionInBST(Node* root, int data) {
    if(root == NULL) return root;
    if(root -> data == data) {
        // 0 child
        if(root -> left == NULL && root -> right == NULL) {
            delete root;
            return NULL;
        }

        // 1 child
        // Left child
        else if(root -> left != NULL && root -> right == NULL) {
            Node* temp = root -> left;
            delete root;
            return temp;
        }
        // Right child
        else if(root -> left == NULL && root -> right != NULL) {
            Node* temp = root -> right;
            delete root;
            return temp;
        }

        // 2 children
        else {
            // Here we have to replace it with either "inorder" predecessor(highest value in it's left subtree) or successor(lowest value in it's right subtree).
            // Here, let's go inorder successor.
            int mini = minVal(root -> right); // We have to write a function to find the minimun value.
            root -> data = mini;
            root -> right = deletionInBST(root -> right, mini);
            return root;
        }
    }
    else if(data > root -> data) {
        root -> right = deletionInBST(root -> right, data);
        return root;
    } else {
        root -> left = deletionInBST(root -> left, data);
        return root;
    }
}