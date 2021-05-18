#include <iostream>
#include <cmath>

//Structure of the Tree
struct TreeNode{
	int data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(const int& data): data(data), left(nullptr), right(nullptr){}
};

TreeNode* find(TreeNode* root, const int& data){
	/**
	 * Find the node that contains the given data and
	 * return that node
	 *
	 * @params: `root` root/parent node of the tree
	 * @params: `data` data to be find in the tree
	 * @return: tree node that contains the data
	 *
	 * Average case Time Complexity: O(log(n))
	 * Worst case Time Complexity: O(n)
	 *
	 */

	if(root == nullptr) 	    { throw std::runtime_error("Error: find() cannot find the data. The data doesn't exist."); }
	else if(root->data == data) { return root; }
	else if(root->data < data)  { return find(root->right, data); }
	else 			    { return find(root->left, data); }
}

void Insert(TreeNode*& root, const int& data){
	/**
	 * Create and Insert the node in the appropriate place of the tree
	 *
	 * @params: `root` root/parent node of the tree
	 * @params: `data` data to be inserted in the tree
	 * @return: void
	 *
	 * Average case Time Complexity: O(log(n))
	 * Worst case Time Complexity: O(n)
	 *
	 */

	if(root == nullptr) 	    { root = new TreeNode(data); }
	else if(root->data == data) { throw std::runtime_error("The node already exist. Duplicates not allowed"); }
	else if(root->data < data)  { Insert(root->right, data); }
	else 			    { Insert(root->left, data); }
}


bool isfull(TreeNode* root){
        /**
         *
         * Check if a binary tree is full or not
         * A binary tree is full when every node in the 
         * tree has either two or zero child nodes.
         *
         * @params: `root` root/parent node of the tree
         *
         * @return: true if it the binary tree is full else false
         */

        if(root == nullptr)                                     { return true; }
        if(root->left == nullptr && root->right == nullptr)     { return true; }
        if((root->left != nullptr && root->right != nullptr) )  { return isfull(root->left) && isfull(root->right); }
        return false;
}

int depth(TreeNode* root){
        /**
         * Find the depth of the left most tree.
         * Here the depth of the left most tree is found but 
         * it is only a matter of preference.
         *
         * @params: `root` root/parent node of the tree
         *
         * @return: `d` returns the depth of the left most tree
         */

        int d = 0;
        while(root != nullptr){
                root = root->left;
                d++;
        }
        return d;
}


bool perfect_recursive(TreeNode* cur, int depth, int level = 0){
        /**
         * A Recursive strategy to check if a tree is perfect or not
         *
         * A binary tree is perfect if when all the inner node's
         * has two childs and the all the leaf node's are at the
         * same level.
         *
         * @params: `cur`  node of the tree
         * @params: `depth` depth of the left most tree
         * @params: `level` level of the cur node
         *
         * @return: true if the binary tree is perfect else false
         */

        if(cur == nullptr)                                { return true; }
        if(cur->left == nullptr && cur->right == nullptr) { return depth == level; }
        if(cur->left != nullptr && cur->right != nullptr) {
                return perfect_recursive(cur->left, depth, level+1) && perfect_recursive(cur->right, depth, level+1);
        }
	return false;
}

int count_nodes(TreeNode* cur){
        /**
         * Count the number of node's in the tree
         * @params: `cur`  node of the tree
         */

        if(cur != nullptr){ return 1 + count_nodes(cur->left) + count_nodes(cur->right); }
	return 0;
}


int height(TreeNode* cur){
        /**
         * Find the height of the tree
         *
         * @params: `cur`  node of the tree
         */

        if(cur != nullptr){ return 1 + std::max(height(cur->left),  height(cur->right)); }
	return 0;
}

bool perfect(TreeNode* cur){
        /**
         * Knowing the height and the number of node's of
         * the tree we can find whether the tree is perfect or not
         *
         * A binary tree is perfect if when all the inner node's
         * has two childs and the all the leaf node's are at the
         * same level.
         */

        int h = height(cur) - 1;
        int N = count_nodes(cur);
        if(N == pow(2, h+1) - 1) { return true; }
        return false;
}

bool isperfect(TreeNode* root){
        /**
         *
         * @params: `root` root/parent node of the tree
         *
         * @return: true if the binary tree is perfect else false
         */

        if(perfect(root))                           { return true; }
        //if(perfect_recursive(root, depth(root) - 1)) { return true; }
	return false;
}


void print(TreeNode* root){
	/**
	 * Print the tree in an inorder fashion
	 * 
	 * @params: `root` root/parent node of the tree
	 * @return: void
	 */
	if(root != nullptr){
		print(root->left);
		std::cout << root->data << " ";
		print(root->right);
	}	
}

void free(TreeNode* root){
	/*
	 * Free up the memory in the heap
	 *
	 * @params: `root` root/parent node of the tree
	 */

	if(root != nullptr){
		free(root->left);
		free(root->right);
		delete root;
		root = nullptr;
	}
}

int main(){
	TreeNode* root = nullptr;

	Insert(root, 37);
	Insert(root, 19);
	Insert(root, 4);
	Insert(root, 22);
	Insert(root, 51);
	Insert(root, 55);
	Insert(root, 42);
	Insert(root, 20);
	Insert(root, 11);
	Insert(root, 2);
	
	print(root);

	TreeNode* n = find(root, 19);
	std::cout << "\nValue of n: " << n->data << std::endl;

	if(isfull(root)) { std::cout << "The binary tree is FULL" << std::endl; }
	else 		{ std::cout << "The binary tree is not FULL" << std::endl; }

	if(isperfect(root)) { std::cout << "The binary tree is PERFECT" << std::endl; }
	else 		   { std::cout << "The binary tree is not PERFECT" << std::endl; }

	/* 
	Tree structure
		37
	       /  \
	      19  51
	     / \   / \
	    4  22 42 55
	   /\	/ 	
	  2 11  20

	OUTPUT:
	  2 4 11 19 20 22 37 42 51 55
	  Value of n: 19
	  The binary tree is not FULL
	  The binary tree is not PERFECT
	*/
	

	// free the memory
	free(root);
	return 0;
}
