// Wap to find the height in a binary search tree.

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

// to find the max
int max(int a, int b){
    if(a>b)
        return a;
    return b;
}

// if node is NULL return -1 else max of height of its 2 subtrees +1 
int findHeight(struct Node*root){
    if (root == NULL)
        return -1;
    return max(findHeight(root->left),findHeight(root->right))+1;  
}

int main(int argc, char const *argv[]){	
	// constructing the root node
	struct Node *p = createNode(5);
	struct Node *p1 = createNode(3);
	struct Node *p2 = createNode(6);
	struct Node *p3 = createNode(1);
	struct Node *p4 = createNode(4);
	
	// Finally the tree looks like this
	//        5
	//       / \
	//      3   6
	//     / \
	//    1   4
	// in preorder traversal expected output is (4 1 5 2 6)
	
	// linking the root node with left and right children
    p -> left = p1;
    p -> right = p2;
    p1 -> left = p3;
    p1 -> right = p4;
    
    printf("Tree is been created  \n");
    printf("Root(p) node has data = %d \n",p->data);
    printf("p1 node has data = %d \n",p1->data);
    printf("p2 node has data = %d \n",p2->data);
    printf("p3 node has data = %d \n",p3->data);
    printf("p4 node has data = %d \n",p4->data);
    
    printf("\nHeight of the tree is %d",findHeight(p));
    return 0;
}
/* ------------output----------------
Tree is been created  
Root(p) node has data = 5 
p1 node has data = 3 
p2 node has data = 6 
p3 node has data = 1 
p4 node has data = 4 

Height of the tree is 2
 */
