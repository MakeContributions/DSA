#include <stdio.h>
#include <stdlib.h>
#define max(a,b) (a > b? a: b)

struct node{
	struct node* left;
	struct node* right;
	int height;
	int val;
};

struct node* createNode(int val){
	struct node* n = (struct node*)malloc(sizeof(struct node));
	n->val = val;
	n->left = NULL;
	n->right = NULL;
	n->height = 0;
	return n;
}

int height(struct node* root){
	if(root == NULL){
		return -1;
	}
	return root->height;
}

void update(struct node** root){
	if(*root == NULL){
		return;
	}
	(*root)->height = 1 + max(height((*root)->right),height((*root)->left));
}

int balance_factor(struct node* root){
	if(root == NULL){
		return 0;
	}
	return height(root->right) - height(root->left);
}

void right_rotation(struct node** root){
	if(*root == NULL){
		return;
	}

	struct node* a = (*root);
	struct node* b = (*root)->left;
	a->left = b->right;
	b->right = a;

	*root = b;

	update(&a);
	update(&b);
}

void left_rotation(struct node** root){
	if(*root == NULL){
		return;
	}

	struct node* a = *root;
	struct node* b = (*root)->right;
	a->right = b->left;
	b->left = a;

	*root = b;

	update(&a);
	update(&b);
}

void left_right_rotation(struct node** root){
	if(*root == NULL){
		return;
	}
	left_rotation(&(*root)->left);
	right_rotation(root);
}

void right_left_rotation(struct node** root){
	if(*root == NULL){
		return;
	}
	right_rotation(&(*root)->right);
	left_rotation(root);
}

void insert(struct node** root, int val){
	if(*root == NULL){
		*root = createNode(val);
	}
	else if((*root)->val < val){
		insert(&(*root)->right, val);
	}
	else{
		insert(&(*root)->left, val);
	}

	update(root);

	int balance = balance_factor(*root);

	if(balance == 2){
		int bal_r = balance_factor((*root)->right);
		if(bal_r == 1 || bal_r == 0){
			left_rotation(root);
		}
		else if(bal_r == -1){
			right_left_rotation(root);
		}
	}
	else if(balance == -2){
		int bal_l = balance_factor((*root)->left);
		if(bal_l == 1 || bal_l == 0){
			left_right_rotation(root);
		}
		else if(bal_l == -1){
			right_rotation(root);
		}
	}
}

void print(struct node* root){
	if(root != NULL){
		printf("%i ", root->val);
		print(root->left);
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

	insert(&root, 1);
	insert(&root, 2);
	insert(&root, 3);
	insert(&root, 4);
	insert(&root, 5);
	insert(&root, 6);
	insert(&root, 7);
	insert(&root, 8);
	insert(&root, 9);
	insert(&root, 10);

	print(root);
	/*
			
      Binary tree                         
	   1  
	    \
	     2
	      \
	       3
	        \
		 4
		  \
		   5
		    \
		     6
		      \
		       7
		        \
			 8
			  \
			   9
			    \
			     10
	
	Output: 1 2 3 4 5 6 7 8 9 10
	Here the balance factor of the root node is 9                          
	AVL Tree
	   4
	 /  \
	2    8
       /\   / \
      1  3 6   9
	  / \   \
	 5   7	 10
	Output: 4 2 1 3 8 6 5 7 9 10
	Here the balance factor of the root node is 1
	*/
	deallocate(&root);
	return 0;
}
