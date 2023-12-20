//description: Implementing a function that counts the frequency of each element in an array/vector
//Time Complexity : O(n), where n is the size of the vector
//Auxiliary Space : O(n), map data structure is used to store the frequency of element in an array

#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<int,int> count_frequency(vector<int> &vec){
    map<int,int> mp;
    for(int i=0;i<vec.size();i++){
        mp[vec[i]]++;
    }
    return mp;
}

int main(){
    vector<int> vec;
    map<int,int> mp;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        vec.push_back(temp);
    }
    mp = count_frequency(vec);
    map<int,int>::iterator it = mp.begin();
    while(it != mp.end()){
        cout<<it->first<<"--"<<it->second<<endl;
        it++;
    }
    return 0;
}
