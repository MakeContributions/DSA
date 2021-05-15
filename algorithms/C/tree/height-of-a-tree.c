// Program to find the height in a tree.

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

// creating a Node
struct Node * createNode(int data){
	struct Node *n;
    n = (struct Node *)malloc(sizeof(struct Node)); // allocating the memory in the heap
    n -> data = data; // setting the data
    n -> left = NULL; // setting left node to be NULL
    n -> right = NULL; // setting right node to be NULL
    return n; // returning the created node
}

// Function to find the max between 2 number
int max(int a, int b){
    if(a>b)
        return a;
    return b;
}

// Function to find height of the tree
int findHeight(struct Node*root){
    if (root == NULL) // if node is NULL then it will return -1 
        return -1;
    return max(findHeight(root->left),findHeight(root->right))+1;  // it will return max of height of its 2 subtrees +1 
}

// Driver code
int main(int argc, char const *argv[]){	
	// constructing the root node by calling createNode function
	struct Node *p0 = createNode(5); 
	struct Node *p1 = createNode(3);
	struct Node *p2 = createNode(6);
	struct Node *p3 = createNode(1);
	struct Node *p4 = createNode(4);
	
	// linking the root node with left and right child nodes
    p0 -> left = p1;
    p0 -> right = p2;
    p1 -> left = p3;
    p1 -> right = p4;
    // The tree looks like this
	//        p0
	//       / \
	//      p1  p2
	//     / \
	//    p3  p4
	
    printf("\nHeight of the tree is %d",findHeight(p0));
    
    return 0;
    
}
/* 
Output: Height of the tree is 2

Time complexity: O(n)
 */
