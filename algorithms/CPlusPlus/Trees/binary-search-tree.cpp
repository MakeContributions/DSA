#include <iostream>

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

	if(root == nullptr) 	    { throw std::runtime_error("Error: find() cannot find the data. The data dosen't exist."); }
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
	else if(root->data < data)  { Insert(root->right, data); }
	else 			    { Insert(root->left, data); }
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

int main(){
	TreeNode* root = nullptr;
	Insert(root, 37);
	Insert(root, 19);
	Insert(root, 4);
	Insert(root, 2);
	Insert(root, 11);
	Insert(root, 22);
	Insert(root, 20);
	Insert(root, 51);
	Insert(root, 55);
	Insert(root, 42);
	
	print(root);
	/* 
	Tree structure

		37
	       /  \
	      19  51
	     / \   / \
	    4  22 42 55
	   /\	/ 	
	  2 11  20

	  Output: 2 4 11 19 20 22 37 42 51 55

	*/

	TreeNode* n = find(root, 2);
	std::cout << "\nValue of n: " << n->data << std::endl; //Output: Value of n: 2
	return 0;
}
