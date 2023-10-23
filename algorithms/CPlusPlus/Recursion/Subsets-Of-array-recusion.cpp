//Program to get all the subsets/powersets of any array



#include <iostream>
#include <vector>
using namespace std;


void GetSubsets(int nums[],int index,vector<int> arr1,int n){
    
    
    if(index == n){
        for(auto it:arr1){
            cout<< it<<" ";
        }
        cout<<endl;
        return ;
    }else{
        arr1.push_back(nums[index]);
      
        GetSubsets(nums,index+1,arr1,n);

        arr1.pop_back();
        
        GetSubsets(nums,index+1,arr1,n);
    }    
}
//Test case
int main(){
    int arr2[]={3,1,2};
    int index=0;
    int n=3;
    vector<int> arr3;
    GetSubsets( arr2 ,index,arr3,n);
}









