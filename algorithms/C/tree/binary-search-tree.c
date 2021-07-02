#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
	struct node* left;
	struct node* right;
	int val;
};

struct node* createNode(int val){
	struct node* n = (struct node*)malloc(sizeof(struct node));
	n->val = val;
	n->left = NULL;
	n->right = NULL;
	return n;
}

struct node* insert(struct node* root, int val){
	if(root == NULL){
		root = createNode(val);
	}
	else if(root->val < val){
		root->right = insert(root->right, val);
	}
	else{
		root->left = insert(root->left, val);
	}

	return root;
}

bool is_full(struct node* root){
	if(root == NULL || (root->left == NULL && root->right == NULL)){
		return true;
	}
	else if(root->left != NULL && root->right != NULL){
		return is_full(root->left) && is_full(root->right);
	}
	return false;
}

int depth(struct node* root){
	int d = 0;
	while(root != NULL){
		root = root->left;
		d++;
	}
	return d;
}

bool is_perfect(struct node* root, int depth, int current_lvl){
	if(root == NULL){
		return true; 
	}
	else if(root->left == NULL && root->right == NULL){
		return depth == current_lvl;
	}
	else if(root->left != NULL && root->right != NULL){
		return is_perfect(root->left, depth, 1+current_lvl) &&
		is_perfect(root->right, depth, 1+current_lvl);
	}
	
	return false;
}

void print(struct node* root){
	if(root != NULL){
		print(root->left);
		printf("%i ", root->val);
		print(root->right);
	}
}

void deallocate(struct node** root){
	if(*root != NULL){
		deallocate(&(*root)->left);
		deallocate(&(*root)->right);
		free(*root);
		*root = NULL;
	}
}

int main(){
	struct node* root = NULL;

	root = insert(root, 37);
	root = insert(root, 19);
	root = insert(root, 4);
	root = insert(root, 22);
	root = insert(root, 51);
	root = insert(root, 55);
	root = insert(root, 42);
	
	if(is_full(root)){
		printf("BST is full\n");
	}
	else{
		printf("BST is not full\n");
	}
	if(is_perfect(root, depth(root)-1, 0)){ 
		printf("BST is Perfect\n");
	}
	else{
		printf("BST is not Perfect\n");
	}
	print(root);
	/*
		Tree structure
	       37
	      /  \
	     19  51
	    / \  / \
	   4  22 42 55

		Output:
			BST is full
			BST is Perfect
			4 19 22 37 42 51 55
	*/
	deallocate(&root);
	return 0;
}
