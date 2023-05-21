#include<bits/stdc++.h>
using namespace std;
    // Create the following binary tree
    //       1
    //     /   \
    //    2     3
    //   / \   / \
    //  4   5 6   7
    //     /   \
    //    8     9

    // output should be: 1,3,7,9

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
} Node;
 
/*  Print Right View of Binary Tree. This function takes root, current_level and max_level(Pass by reference) */
void rightSideView(Node *root, int current_level, int &max_level)
{
    /* Base Case */
    if(root == NULL)
    return;
    
    /* 
        If current level is greater than previous levels,
        print the current node and update the max_level
    */
    if(current_level > max_level)
    {
        cout<<root -> data<<" ";
        max_level = current_level;
    }
    
    /* Recursion call to next level of each sub tree*/
    rightSideView(root -> right, current_level+1, max_level);
    rightSideView(root -> left, current_level+1, max_level);
}


 
int main()
{

    //Time complexity: O(N) where N = number of nodes
    Node *root = NULL;
    // createing tree  and inserting values 
    root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> right -> left = new Node(6);
    root -> right -> right = new Node (7);
    root -> left -> right -> left = new Node(8);
    root -> right -> left -> right = new Node(9);
    
    cout<<"Binary Tree right side view: ";

    int max_level = 0;
    rightSideView(root, 1, max_level);
}