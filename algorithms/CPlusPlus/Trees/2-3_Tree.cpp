#include <iostream>
using namespace std;

class Node {
public:
    int val1, val2;
    Node *left, *middle, *right, *parent;
    bool isLeaf;
    
    Node(int val1 = 0, int val2 = 0, Node *left = nullptr, Node *middle = nullptr, Node *right = nullptr, Node *parent = nullptr, bool isLeaf = true) {
        this->val1 = val1;
        this->val2 = val2;
        this->left = left;
        this->middle = middle;
        this->right = right;
        this->parent = parent;
        this->isLeaf = isLeaf;
    }
};

class TwoThreeTree {
private:
    Node *root;

public:
    TwoThreeTree() {
        root = nullptr;
    }

    void insert(int val) {
        if (root == nullptr) {
            root = new Node(val);
        } else {
            Node *curr = root;
            while (!curr->isLeaf) {
                if (val < curr->val1) {
                    curr = curr->left;
                } else if (curr->val2 == 0 || val < curr->val2) {
                    curr = curr->middle;
                } else {
                    curr = curr->right;
                }
            }
            if (curr->val2 == 0) {
                if (val < curr->val1) {
                    curr->val2 = curr->val1;
                    curr->val1 = val;
                } else {
                    curr->val2 = val;
                }
            } else {
                Node *newNode = new Node();
                if (val < curr->val1) {
                    newNode->val1 = curr->val2;
                    curr->val2 = curr->val1;
                    curr->val1 = val;
                    newNode->left = curr->middle;
                    newNode->middle = curr->right;
                    curr->middle = newNode;
                } else if (val < curr->val2) {
                    newNode->val1 = curr->val2;
                    curr->val2 = val;
                    newNode->left = curr->middle;
                    newNode->middle = curr->right;
                    curr->middle = newNode;
                } else {
                    newNode->val1 = curr->val2;
                    newNode->val2 = val;
                    newNode->left = curr->right;
                    newNode->middle = new Node();
                    newNode->middle->val1 = curr->val2;
                    newNode->middle->left = curr->middle;
                    newNode->middle->middle = curr->right;
                    curr->right = newNode;
                }
                if (curr->parent != nullptr) {
                    insertHelper(curr->parent, newNode);
                } else {
                    Node *newRoot = new Node(curr->val2, 0, curr, newNode, nullptr, nullptr, false);
                    curr->parent = newRoot;
                    newNode->parent = newRoot;
                    root = newRoot;
                }
            }
        }
    }

    void print() {
        printHelper(root);
        cout << endl;
    }

private:
    void insertHelper(Node *curr, Node *newNode) {
        if (curr->val2 == 0) {
            if (newNode->val1 < curr->val1) {
                curr->val2 = curr->val1;
                curr->val1 = newNode->val1;
                curr->middle = curr->left;
                curr->left = newNode->left;
                curr->right = newNode->middle;
                curr->middle->parent = curr;
