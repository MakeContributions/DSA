//Print the list of all the nodes visible when the binary tree is observed from the right side. 
//Starting from the top , i.e. the root node. 

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Node structure for tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) {
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};


void rightsideview(TreeNode * root)
{
	vector<int> ans;

        TreeNode* curr;
        
        curr=root;
        queue<TreeNode*> que;

        que.push(curr);

        while(!que.empty())
        {
            int s=que.size();

            for(int i=0;i<s;i++)
            {
                curr=que.front();
                que.pop();
                if(curr->left!=NULL)
                    que.push(curr->left);
                if(curr->right!=NULL)
                    que.push(curr->right);
            }

            ans.push_back(curr->val);
        }


	
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<"\t";
	}
	cout<<endl;

}

int main()
{
	TreeNode * root= new TreeNode(1), * curr;
	root->left=new TreeNode(2);
	root->right= new TreeNode(3);

	curr=root->right;
	curr->left= new TreeNode(4);

	curr=root->left;

	curr->left= new TreeNode(5);
	
	curr->left->left= new TreeNode(6);

	curr=curr->left->left;

	curr->left= new TreeNode(7);
	curr->left->right= new TreeNode(8);
	curr->left->left=new TreeNode(9);


	//			 1
	//			/ \
	//		       2   3
	//		      /    /
	//		      5   4
	//		     /
	//		     6
	//		    /
	//		    7
	//		   / \
	//		   9  8

	
	// 		The Output Should be -> 1, 3, 4, 6, 7, 8;
	
	

	rightsideview(root);  // This function prints the result;
	return 0;
}
