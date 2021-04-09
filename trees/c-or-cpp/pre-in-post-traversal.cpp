#include<iostream>
#define endl "\n"
using namespace std;


// Basic Structure of a Tree
struct Node{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

/* Pre, In and Post order Traversal of a Binary Tree using recusrion */
/* Complexity for each Traversal : O(n) */

// LST -> Left SubTree   RST -> Right SubTree

// Pre-Order goes like :-   Root, LST, RST (Recursively)
void pre_order(struct Node* root){
    if(root == NULL)
      return;
    cout<<root->data<<" ";
    pre_order(root->left);
    pre_order(root->right);
}

// In-Order goes like :-   LST, Root, RST (Recursively)
void in_order(struct Node* root){
    if(root == NULL)
      return;
    in_order(root->left);
    cout<<root->data<<" ";
    in_order(root->right);
}

// Pre-Order goes like :-  LST, RST, Root (Recursively)
void post_order(struct Node* root){
    if(root == NULL)
      return;
    post_order(root->left);
    post_order(root->right);
    cout<<root->data<<" ";
}


int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(7);

    /*                       
                    1
                   / \
                  2   3
                 / \   \
                4   5   7    
        Expected-> pre-order :  1,2,4,5,3,7
                   in-order  :  4,2,5,1,3,7
                   post-order:  4,5,2,7,3,1
    
    */
   cout<<"pre-order : "; pre_order(root); cout<<endl;
   cout<<"in-order : "; in_order(root); cout<<endl;
   cout<<"post-order : "; post_order(root); cout<<endl;

    return 0;
}
