#include <iostream>
using namespace std;

// sturcture of a tree node
struct Node
{
    int data;
    Node *right;
    Node *left;

    Node(int data)
    {
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }
};

// function to check if a tree is a BST or not
bool validateBST(Node *root)
{
    // if the tree is empty
    if (root == NULL)
        return true;

    // if the left child is not null and its data is greater than the root's data then its not a BST
    if (root->left != NULL && root->left->data > root->data)
        return false;

    // if the right child is not null and its data is less than the root's data then its not a BST
    if (root->right != NULL && root->right->data < root->data)
        return false;

    // if the left and right subtree are not BST then the tree is not a BST
    if (!validateBST(root->left) || !validateBST(root->right))
        return false;

    // if all the above conditions are false then the tree is a BST
    return true;
}

int main()
{
    // creating a bst
    Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    // checking if the tree is a BST or not
    if (validateBST(root))
        cout << "Valid BST" << endl;
    else
        cout << "Invalid BST" << endl;

    return 0;
}