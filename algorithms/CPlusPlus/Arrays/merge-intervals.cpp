/*
https://leetcode.com/problems/merge-intervals/
time complexity: O(nlogn)
*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> merge(vector<vector<int>>& a) {
        if(a.size()<=1)return a; //return if only one interval vector
        // sort according to the starting intervals
        sort(a.begin(),a.end());
        vector<vector<int>>v;
        v.push_back(a[0]);
        for(int i=1;i<a.size();i++){
            if(v.back()[1]>=a[i][0])
                v.back()[1]=max(v.back()[1],a[i][1]);
            else v.push_back(a[i]);
        }
        return v;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> intervals(n);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        intervals[i].push_back(a);
        intervals[i].push_back(b);
    }
    vector<vector<int>> ans = merge(intervals);
    cout<<"Intervals after merge operation are:\n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i][0]<<" "<<ans[i][1]<<"\n";
    }
}
