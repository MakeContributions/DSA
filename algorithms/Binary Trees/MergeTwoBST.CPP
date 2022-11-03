#include <bits/stdc++.h>
using namespace std;

// Structure of a BST Node
class Node {
public:
	int val;
	Node* left;
	Node* right;
};

/* Utility function to create a new Binary Tree Node */
Node* newNode(int data)
{
	Node* temp = new Node;
	temp->val = data;
	temp->left = nullptr;
	temp->right = nullptr;
	return temp;
}

vector<int> mergeTwoBST(Node* root1, Node* root2)
{
	vector<int> res;
	stack<Node*> s1, s2;
	while (root1 || root2 || !s1.empty() || !s2.empty()) {
		while (root1) {
			s1.push(root1);
			root1 = root1->left;
		}
		while (root2) {
			s2.push(root2);
			root2 = root2->left;
		}
		// Step 3 Case 1:-
		if (s2.empty() || (!s1.empty() && s1.top()->val <= s2.top()->val)) {
			root1 = s1.top();
			s1.pop();
			res.push_back(root1->val);
			root1 = root1->right;
		}
		// Step 3 case 2 :-
		else {
			root2 = s2.top();
			s2.pop();
			res.push_back(root2->val);
			root2 = root2->right;
		}
	}
	return res;
}

/* Driver program to test above functions */
int main()
{
	Node *root1 = nullptr, *root2 = nullptr;

	/* Let us create the following tree as first tree
	3
	/ \
	1 5
	*/
	root1 = newNode(3);
	root1->left = newNode(1);
	root1->right = newNode(5);

	/* Let us create the following tree as second tree
	4
	/ \
	2 6
	*/
	root2 = newNode(4);
	root2->left = newNode(2);
	root2->right = newNode(6);

	// Print sorted Nodes of both trees
	vector<int> ans = mergeTwoBST(root1, root2);
	for (auto it : ans)
		cout << it << " ";
	return 0;
}

