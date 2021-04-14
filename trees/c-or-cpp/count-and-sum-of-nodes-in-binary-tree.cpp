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

/*                       
                    1
                   / \
                  2   3
                 / \   \
                4   5   7    
        
        Expected Output in this case
            Count: 7
            Sum : 28
    */

/* Counting Nodes Algorithm

    Left subtree Count + Right Subtree Count + 1

*/

int CountNodes(Node *root)
{
    //Base Case
    if (root == NULL)
        return 0;

    //Recursive Case
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

    //Recursive Case
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

    //Sum of Nodes
    cout << "Sum of Nodes : " << SumNodes(root);
}