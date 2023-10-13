#include <iostream>
using namespace std;
 
// Data structure to store a BST node
struct Node
{
    int data;
    Node* left = nullptr, *right = nullptr;
 
    Node() {}
    Node(int data): data(data) {}
};
 
// Function to perform inorder traversal on the BST
void inorder(Node* root)
{
    if (root == nullptr) {
        return;
    }
 
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
 
// Helper function to find the maximum value node in the subtree rooted at `ptr`
Node* findMaximumKey(Node* ptr)
{
    while (ptr->right != nullptr) {
        ptr = ptr->right;
    }
    return ptr;
}
 
// Recursive function to insert a key into a BST
Node* insert(Node* root, int key)
{
    // if the root is null, create a new node and return it
    if (root == nullptr) {
        return new Node(key);
    }
 
    // if the given key is less than the root node, recur for the left subtree
    if (key < root->data) {
        root->left = insert(root->left, key);
    }
 
    // if the given key is more than the root node, recur for the right subtree
    else {
        root->right = insert(root->right, key);
    }
 
    return root;
}
 
// Function to delete a node from a BST. Note that root is passed by
// reference to the function
void deleteNode(Node* &root, int key)
{
    // base case: the key is not found in the tree
    if (root == nullptr) {
        return;
    }
 
    // if the given key is less than the root node, recur for the left subtree
    if (key < root->data) {
        deleteNode(root->left, key);
    }
 
    // if the given key is more than the root node, recur for the right subtree
    else if (key > root->data) {
        deleteNode(root->right, key);
    }
 
    // key found
    else {
        // Case 1: node to be deleted has no children (it is a leaf node)
        if (root->left == nullptr && root->right == nullptr)
        {
            // deallocate the memory and update root to null
            delete root;
            root = nullptr;
        }
 
        // Case 2: node to be deleted has two children
        else if (root->left && root->right)
        {
            // find its inorder predecessor node
            Node* predecessor = findMaximumKey(root->left);
 
            // copy value of the predecessor to the current node
            root->data = predecessor->data;
 
            // recursively delete the predecessor. Note that the
            // predecessor will have at most one child (left child)
            deleteNode(root->left, predecessor->data);
        }
 
        // Case 3: node to be deleted has only one child
        else {
            // choose a child node
            Node* child = (root->left)? root->left: root->right;
            Node* curr = root;
 
            root = child;
 
            // deallocate the memory
            delete curr;
        }
    }
}
 
int main()
{
    int keys[] = { 15, 10, 20, 8, 12, 25 };
 
    Node* root = nullptr;
    for (int key: keys) {
        root = insert(root, key);
    }
 
    deleteNode(root, 12);
    inorder(root);
 
    return 0;
}
