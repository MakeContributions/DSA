// program to find the minimum and maximum element in a binary search tree (using recursion) 

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

//function to insert a node in tree
struct Node *insert(struct Node *root, int data){
	if(root==NULL){ // empty tree condition
		root = createNode(data);
		return root;
	}
	
	else if(data <= root->data) // data to be inserted at left subtree
		root->left = insert(root->left,data);
	
	else if(data > root->data) // data to be inserted at right subtree
		root->right = insert(root->right,data);
	return root;
}

//function to find the min element from the tree using recursion
int findMin(struct Node *root){
	if(root==NULL){
		printf("Tree is empty\n");
		return -1;
	}
	
	struct Node *current = root; // current is the traversing node
	while(current->left !=NULL){
		current=current->left;  // if left node is not empty then traversing node = left node
	}
	return current->data;
}

//function to find the max element using recursion
int findMax(struct Node *root){
	if(root==NULL){
		printf("Tree is empty\n");
		return -1;
	}
	
	struct Node *current = root; // current is the traversing node
	while(current->right !=NULL){
		current=current->right;  // if right node is not empty then traversing node = right node
	}
	return current->data;
}

int main(int argc, char const *argv[]){
	
	// constructing the root node
	struct Node *p0 = createNode(5);
	struct Node *p1 = createNode(3);
	struct Node *p2 = createNode(6);
	struct Node *p3 = createNode(1);
	struct Node *p4 = createNode(4);
	
	// linking the root node with left and right children
    p0 -> left = p1;
    p0 -> right = p2;
    p1 -> left = p3;
    p1 -> right = p4;
    // the tree looks like this
	//        p0
	//       / \
	//      p1  p2
	//     / \
	//    p3  p4
    
    // inserting few new nodes
    insert(p0,15);
    insert(p0,18);
    insert(p0,0);
    insert(p0,-1);
    printf("\nMin element of the tree is %d",findMin(p0));
    printf("\nMax element of the tree is %d",findMax(p0));
    return 0;
}
/*
Output: 
Min element of the tree is -1
Max element of the tree is 18

Time complexity: O(n)

 */
