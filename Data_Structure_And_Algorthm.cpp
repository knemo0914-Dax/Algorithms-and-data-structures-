#include <iostream>
using namespace std;


// Binary Search Tree Node
// TIME COMPLEXITIES
// Best Case   : O(log n)
// Average Case: O(log n)
// Worst Case  : O(n)
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};
// INSERT OPERATION
// Runtime:
// Best Case   -> O(log n)
// Worst Case  -> O(n)
Node* insert(Node* root, int value) {
    if (root == NULL)
        return new Node(value);
    if (value < root->data)
        root->left = insert(root->left, value);
		    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}
// SEARCH OPERATION
// Runtime:
// Best Case   -> O(1)
// Average Case-> O(log n)
// Worst Case  -> O(n)
bool search(Node* root, int key) {
    if (root == NULL)
        return false;
    if (root->data == key)
        return true;

    if (key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}
// FIND MINIMUM
// Runtime:
// Best Case   -> O(1)
// Worst Case  -> O(n)
Node* findMin(Node* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}
// FIND MAXIMUM
// Runtime:
// Best Case   -> O(1)
// Worst Case  -> O(n)
Node* findMax(Node* root) {
    while (root && root->right != NULL)
        root = root->right;
    return root;
}
// DELETE OPERATION
// Runtime:
// Best Case   -> O(log n)
// Worst Case  -> O(n)
Node* deleteNode(Node* root, int key) {
    if (root == NULL)
        return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Case 1: No child
        // Case 2: One child
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: Two children
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
// INORDER TRAVERSAL
// Runtime: O(n)
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
// PREORDER TRAVERSAL
// Runtime: O(n)
void preorder(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
// POSTORDER TRAVERSAL
// Runtime: O(n)
void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}
// MAIN FUNCTION

int main() {
    Node* root = NULL;
    int choice, value, key;
    do {
        cout << "\n* * * * Binary Search Tree * * * * "<<endl;
        cout << "1. Insert Node()"<<endl;
        cout << "2. Search Key()"<<endl;
        cout << "3. Inorder Traversal()"<<endl;
        cout << "4. Preorder Traversal()"<<endl;
        cout << "5. Postorder Traversal()"<<endl;
        cout << "6. Find Minimum()"<<endl;
        cout << "7. Find Maximum()"<<endl;
        cout << "8. Delete Node()"<<endl;
        cout << "9. Exit()"<<endl;
        
        cout << "Select Operation: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter value to insert: ";
            cin >> value;

            root = insert(root, value);

            cout << "Node inserted successfully.\n";
            break;
        case 2:
            cout << "Enter key to search: ";
            cin >> key;

            if (search(root, key))
                cout << "Key found in BST.\n";
            else
                cout << "Key not found.\n";
            break;


        case 3:
            cout << "Inorder Traversal: ";
            inorder(root);
            cout << endl;
            break;
        case 4:
            cout << "Preorder Traversal: ";
            preorder(root);
            cout << endl;
            break;
        case 5:
            cout << "Postorder Traversal: ";
            postorder(root);
            cout << endl;
            break;
        case 6:
            if (root == NULL)
                cout << "Tree is empty.\n";
            else
                cout << "Minimum value = "
                     << findMin(root)->data << endl;
            break;
        case 7:
            if (root == NULL)
                cout << "Tree is empty.\n";
            else
                cout << "Maximum value = "
                     << findMax(root)->data << endl;
            break;
        case 8:
            cout << "Enter value to delete: ";
            cin >> key;
            root = deleteNode(root, key);
            cout << "Deletion completed.\n";
            break;
        case 9:
            cout << "Program ended successfully.\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 9);

    return 0;
}