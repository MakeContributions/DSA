/*
Problem

Count the Number of Nodes in the Binarry Tree, 
and do find the sum of all nodes in a binary tree.

*/

#include <iostream>

using namespace std;

// Basic Structure of a tree
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

/* Counting Nodes Algorithm

    Left subtree Count + Right Subtree Count + 1

*/

int CountNodes(Node *root)
{
    //Base Case
    if (root == NULL)
        return 0;

    return CountNodes(root->left) + CountNodes(root->right) + 1;
}

/* Sum of Nodes Nodes 
    Left subtree Sum + Right Subtree Sum + Node Value
*/

int SumNodes(Node *root)
{
    //Base Case
    if (root == NULL)
        return 0;

    return SumNodes(root->left) + SumNodes(root->right) + root->data;
}

int main()
{

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    //Counting nodes
    cout << "Number of Nodes : " << CountNodes(root) << endl;

    /*                       
                    1
                   / \
                  2   3
                 / \   \
                4   5   7    
        
        Expected Output 
    Step 1 - First find the Left subtree Count recursively 
    Step 2 - Seconly Find  Right Subtree count Recursively
    Step 3 = Add one for current node
    You can see here that there are total of 7 nodes in the tree.
            Count: 7 Nodes
            
    */

    //Sum of Nodes
    cout << "Sum of Nodes : " << SumNodes(root);

    /*                       
                    1
                   / \
                  2   3
                 / \   \
                4   5   7    
        
        Expected Output 
        Similarly as Counted
    Step 1 - First find the Left subtree Sum  recursively 
    Step 2 - Seconly Find  Right Subtree Sum Recursively
    Step 3 = Add the Current Node Value
    You can see here that total sum is 28
            Sum: 28
            
    */
}
