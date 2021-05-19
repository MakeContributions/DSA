/** 
 * Conduct a morris in-order traversal of a binary tree,
 * printing out the value at each node according to 
 * the traversal
 **/
# include <iostream>
using namespace std;

// Basic tree definition
struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {};

};

/**
 * Print out the values of the treenodes using an in-order traversal
 * (left subtree - root - right subtree) without using additional memory
 * node values are printed with a space between the values of each 2 nodes
 **/

void print_morris(Node* root) {
    if (!root) cout << "\n";

    Node* previous;

    while(root) {
        if (!root->left) {
            cout << root->val << " ";
            root = root->right;
        } else {
            previous = root->left;

            while (previous->right && previous->right != root) 
                previous = previous->right;

            if (!previous->right) {
                previous->right = root;
                root = root->left;
            } else {
                previous->right = NULL;
                cout << root->val << " ";
                root = root->right;
            }
        }
    }
}

int main() {
    Node* my_root = new Node(8);
    my_root->left = new Node(5);
    my_root->right = new Node(10);
    my_root->right->left = new Node(9);
    my_root->right->right = new Node(6);

    /**
     * Test for the morris traversal:
     * tree referenced by my_root:
     *              8
     *            /   \
     *           5    10
     *               /  \
     *              9    6
     * 
     * expected output: 5 8 9 10 6
     * time complexity: O(n), space complexity O(1)
     **/

    print_morris(my_root);
    return 0;
}