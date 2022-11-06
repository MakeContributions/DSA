class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
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
};