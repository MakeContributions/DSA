#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int wateringPlants(vector<int>& plants, int capacity) {
    int sum=capacity;
    int steps=0;
    for(int i=0;i<plants.size();i++){
        if(plants[i]<=sum){
            sum-=plants[i];
            steps+=1;
        }
        else{
            sum=capacity;
            sum-=plants[i];
            steps+=i;
            steps+=i+1;
        }
      }
        return steps;

}





int main(){
	vector<int> a{2,2,3,3};
	int capacity=5;
	int number_of_steps=wateringPlants(a,capacity);
	cout<<"Number of steps needed ";
	cout<<number_of_steps;
	cout<<"\n";
	return 0;
}
