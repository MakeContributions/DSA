#include<bits/stdc++.h>
using namespace std;

typedef struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
	
	Node(int val)
	{
		data= val;
		left=right=NULL;
	}
}node;

//function for level order traversal
void levelorder(Node* root, int k)
{
	if(root==NULL)
		return;
		
	queue<Node*> q;
	
	q.push(root);
	int count=0;
	
	while(!q.empty())
	{
		count++;
		int n=q.size();
		
		for(int i=0; i<n; i++)
		{
			Node* temp=q.front();
			q.pop();
			if(count==k)                //if level is equal to the required level, then print its nodes
				cout<<temp->data<<" ";
			if(temp->left!=NULL)
				q.push(temp->left);
			if(temp->right!=NULL)
				q.push(temp->right);
		}	
	}
}

//main function
int main()
{
	node*root=new node(1);
	root->left=new node(2);
	root->right=new node(3);
	root->right->left=new node(7);
	root->right->right=new node(9);
	root->right->left->left=new node(21);
	root->right->right->right=new node(11);

	int k = 3;  // here we have taken k=3 (third level of tree)
	
	levelorder(root,k);   //calling level order function
}