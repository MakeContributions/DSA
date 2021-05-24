#include <iostream>

struct TreeNode{
	TreeNode* left;
	TreeNode* right;
	int data, height;
	TreeNode(const int& data): data(data), left(nullptr), right(nullptr), height(-1){}
};
 
int height(TreeNode* node){
	if(node == nullptr){ return -1; }
	return node->height;
}

void updateheight(TreeNode*& node){
	if(node == nullptr){ return; }
	node->height = 1 + std::max(height(node->left), height(node->right));
}

int balance_factor(TreeNode* node){
	if(root != nullptr){ return height(node->right) - height(node->left); }
	return 0;
}

void leftrotation(TreeNode*& node){
	if(node == nullptr){ return; }

	TreeNode* a = node;
	TreeNode* b = node->right;

	a->right = b->left;
	b->left = a;
	node = b;

	updateheight(a);
	updateheight(b);
}

void rightrotation(TreeNode*& node){
	if(node == nullptr){ return; }

	TreeNode* a = node;
	TreeNode* b = node->left;

	a->left = b->right;
	b->right= a;
	node = b;

	updateheight(a);
	updateheight(b);
}

void insert(TreeNode*& root, const int& data){
	if(root == nullptr) { 
		root = new TreeNode(data);
	}
	else if(root->data < data){ insert(root->right, data); }
	else{ insert(root->left, data); }

	updateheight(root);

	const int initial_bal = balance_factor(root) ; 

	if(initial_bal > 2 || initial_bal < -2){ throw std::runtime_error(" Error "); }

	if(initial_bal == 2){
		l_bal = balance_factor(root->left);
		if(l_bal == 1 || l_bal == 0){ leftrotation(root); }	
		else if(l_bal == -1){ right_leftrotation(root); }
	}
	else if(initial_bal == -2){
		r_bal = balance_factor(root->right); 
		if(r_bal == 1 || r_bal == 0){ left_rigtrotation(root); } 
		else if(r_bal == -1){ rightrotation(root); }
	}
}

TreeNode* find(TreeNode* root, const int& data){
	if(root == nullptr){ throw std::runtime_error("Item not found"); }
	else if(root->data == data){ return root; }
	else if(root->data < data){ return find(root->right, data); }
	else{ return find(root->left, data); }
}

void ensureBalance(TreeNode* node){
	if(node == nullptr){ return; }

}

void print(TreeNode* root){
	if(root != nullptr){
		print(root->left);
		std::cout << root->data << " "; 
		print(root->right);
	}
}

int main(){
	TreeNode* root = nullptr;
	insert(root, 37);
        insert(root, 19);
        insert(root, 4);
        insert(root, 22);
        insert(root, 51);
        insert(root, 55);
        insert(root, 42);
        insert(root, 20);
        insert(root, 11);
        insert(root, 2);

	print(root);

}
