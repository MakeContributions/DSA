#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <utility>
using namespace std;
 
// Data structure to store a binary tree node
struct Node
{
    int data;
    Node* left = nullptr, *right = nullptr;
 
    Node() {}
    Node(int data): data(data) {}
};
 
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
 
// Helper function to perform level order traversal on a binary tree
void printLevelOrderTraversal(Node* root)
{
    // base case: empty tree
    if (root == nullptr) {
        return;
    }
 
    queue<Node*> q;
    q.push(root);
 
    while (!q.empty())
    {
        int n = q.size();
        while (n--)
        {
            Node* front = q.front();
            q.pop();
 
            cout << front->data << ' ';
 
            if (front->left) {
                q.push(front->left);
            }
 
            if (front->right) {
                q.push(front->right);
            }
        }
 
        cout << endl;
    }
}
 
// Function to perform inorder traversal on a given binary tree and
// enqueue all nodes (in encountered order)
void inorder(Node* root, queue<int> &keys)
{
    if (root == nullptr) {
        return;
    }
 
    inorder(root->left, keys);
    keys.push(root->data);
    inorder(root->right, keys);
}
 
// Function to perform preorder traversal on a given binary tree.
// Assign each encountered node with the next key from the queue
void preorder(Node* root, queue<int> &keys)
{
    // base case: empty tree
    if (root == nullptr) {
        return;
    }
 
    // replace the root's key value with the next key from the queue
    root->data = keys.front();
    keys.pop();
 
    // process left subtree
    preorder(root->left, keys);
 
    // process right subtree
    preorder(root->right, keys);
}
 
// Function to convert a BST into a min-heap
void convert(Node* root)
{
    // base case
    if (root == nullptr) {
        return;
    }
 
    // maintain a queue to store inorder traversal on the tree
    queue<int> keys;
 
    // fill the queue in an inorder fashion
    inorder(root, keys);
 
    // traverse tree in preorder fashion, and for each encountered node,
    // dequeue a key and assign it to the node
    preorder(root, keys);
}
 
int main()
{
    vector<int> keys = { 5, 3, 2, 4, 8, 6, 10 };
 
    /* Construct the following BST
               5
             /   \
            /     \
           3       8
          / \     / \
         /   \   /   \
        2     4 6    10
    */
 
    Node* root = nullptr;
    for (int key: keys) {
        root = insert(root, key);
    }
 
    convert(root);
    printLevelOrderTraversal(root);
 
    return 0;
}