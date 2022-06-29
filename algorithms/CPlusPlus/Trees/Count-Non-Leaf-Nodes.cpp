

/* QUESTION->
Given a Binary Tree of size N, your task is to complete the function countNonLeaf TreeNodes(), that should return the count of all the non-leaf  TreeNodes of the given binary tree.
*/


    /* Prerequisites
        Recursion
        Post-Order Traversal 
    */

    /* Complexity
        Time -> O(n);
        space -> O(Height of tree);
    */

   // Instructions  -> just copy to run

#include<bits/stdc++.h>
using namespace std;

// Basic Structure of a Tree
struct  TreeNode {
    int data;
    struct   TreeNode *left;
    struct   TreeNode *right;

     TreeNode(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};


//Function to calculate  to count  non-Leaf  of Tree
int countNonLeaf ( TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int sum=0;

        sum+= countNonLeaf(root->left);
        
        sum+=countNonLeaf(root->right);
        
         if(root->left!=NULL || root->right!=NULL){
              sum++;
         }
         return sum;
    }



int main(){
     TreeNode* root = new  TreeNode(1);
    root->left = new  TreeNode(2);
    root->right = new  TreeNode(3);
    root->left->left = new  TreeNode(4);
    root->left->right = new   TreeNode(5);
    root->right->right = new  TreeNode(7);

    /*
                    1----non leaf Node=1
                   / \
                  2   3----non leaf Nodes =2
                 / \   \
                4   5   7----non leaf Nodes=0

             Expected ans-> height=3
    */
    cout << "Count of non leaf nodes of tree is : " << countNonLeaf(root) << '\n';

    return 0;
}