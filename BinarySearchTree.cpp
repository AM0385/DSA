
#include <iostream>
#include <queue>

using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

    ~Node() {
        int value = this->data;
        if(this->left == NULL) {
            delete left;
        }
        if(this->right == NULL) {
            delete right;
        }
        cout << "Node deleted with value: " << value << endl;
    }
};

Node* createBST(Node* &root, int data) {
    if(root == NULL) {
        root = new Node(data);
        return root;
    }

    if(data < root->data) {
        createBST(root->left, data);
    }
    else if(data > root->data) {
        createBST(root->right, data);
    }
    return root;
}

void takeInput(Node* &root) {
    int data;
    cin >> data;
    while(data != -1) {
        root = createBST(root, data);
        cin >> data;
    }
}

void levelOrderTraversal(Node* &root) {
    queue<Node*> queue;
    queue.push(root);
    queue.push(NULL);

    while(!queue.empty()) {
        Node* temp = queue.front();
        queue.pop();

        if(temp == NULL) {
            cout << endl;
            if(!queue.empty()) {
                queue.push(NULL);
            }
        }
        else {
            cout << temp->data << " ";
            if(temp->left) {
                queue.push(temp->left);
            }
            if(temp->right) {
                queue.push(temp->right);
            }
        }
    }
}

void inOrderTraversal(Node* &root) {
    // LNR
    if(root == NULL) {
        return;
    }

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void preOrderTraversal(Node* &root) {
    //NLR
    if(root == NULL) {
        return;
    }

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right); 
}

void postOrderTraversal(Node* &root) {
    //LRN
    if(root == NULL) {
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right); 
    cout << root->data << " ";
}

Node* inorderSuccessor(Node* &root) {
    Node* temp = root;
    if(temp == NULL) {
        return temp;
    }

    temp = temp->right;
    while(temp->left != NULL) {
        temp = temp->left;
    }
    return temp;
}

Node* deleteNode(Node* &root, int data) {
    if(root == NULL) {
        return root;
    }

    Node* temp = root;
    if(data == temp->data) {
        if(temp->left == NULL && temp->right == NULL) {
            delete temp;
            return NULL;
        }
        else if(temp->left != NULL && temp->right == NULL) {
            Node* store = temp->left;
            delete temp;
            return store;
        }
        else if(temp->left == NULL && temp->right != NULL) {
            Node* store = temp->right;
            delete temp;
            return store;
        }
        else if(temp->left != NULL && temp->right != NULL) {
            Node* successor = inorderSuccessor(temp);
            temp->data = successor->data;
            temp->right = deleteNode(temp->right, successor->data);
            return temp;
        }
    }
    else if(data < temp->data) {
        temp->left = deleteNode(temp->left, data);
        return temp;
    }
    else if(data > temp->data) {
        temp->right = deleteNode(temp->right, data);
        return temp;
    }
}

int main() {
    


    Node* root = NULL;
    cout << "Enter the data for creating a Binary Search Tree: " << endl;
    takeInput(root);
    cout << endl << "Tree: " << endl;
    levelOrderTraversal(root);
    cout << endl << endl << "Inorder Traversal: " << endl;
    inOrderTraversal(root);
    cout << endl << endl << "Preorder Traversal: " << endl;
    preOrderTraversal(root);
    cout << endl << endl << "Postorder Traversal: " << endl;
    postOrderTraversal(root);

    int data;
    cout << endl << "Enter the data to be deleted: ";
    cin >> data;
    deleteNode(root, data);
    cout << endl << "Tree: " << endl;
    levelOrderTraversal(root);
    cout << endl << endl << "Inorder Traversal: " << endl;
    inOrderTraversal(root);
    cout << endl << endl << "Preorder Traversal: " << endl;
    preOrderTraversal(root);
    cout << endl << endl << "Postorder Traversal: " << endl;
    postOrderTraversal(root);

    return 0;
}
