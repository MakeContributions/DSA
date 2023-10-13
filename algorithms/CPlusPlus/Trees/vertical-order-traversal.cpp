#include<bits/stdc++.h>
using namespace std;


// Basic Structure of a Tree
struct Node {
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

    //Function to find the vertical order traversal of Binary Tree.
vector<int> verticalOrder(Node *root)
{
    list<pair<int,Node*>>l;//queue having hd and node
    map<int,vector<int>>mp;// a vertical level mapped to ele in that level
    vector<int>ans;//ans vector
    if(!root)return ans;
    l.push_back({0,root});
    while(!l.empty()){
            
        pair<int,Node*>p=l.front();
        //frst is hd and second is node
        mp[p.first].push_back(p.second->data);//map data to the vertical level it belongs to 
        if(p.second->left)l.push_back({p.first-1,p.second->left});//hd=current-1 for left
        if(p.second->right)l.push_back({p.first+1,p.second->right});//hd=current +1 for right
        l.pop_front();
    }
        // now map has elements acc to level
        // make a vector each for a level
        //push that vector to ans vector
        
        /* map looks like this
                   frst     snd
           begin:  (-1)->  [9]
           begin+1: (0)->  [3,15]
           begin+2: (1)->  [20]
           begin+3: (2)->  [7]       */
    for(auto it=mp.begin();it!=mp.end();it++){
        pair<int,vector<int>>q=*it;
        int size=q.second.size();
        vector<int>level;
        for(int i=0;i<size;i++){
            ans.push_back(q.second[i]);
        }
        //ans.push_back(level);
    }
    return ans;
}


int main()
{   

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);
    root->right->right->right = new Node(9);

    vector<int>ans;
    ans=verticalOrder(root);

    for(int i:ans){
        cout<<i<<" ";
    }

    return 0;
}


//// Time Complexity:
// O(nlogn)
// Space Complexity:
// O(n)

// Output:
// 4 2 1 5 6 3 8 7 9 
