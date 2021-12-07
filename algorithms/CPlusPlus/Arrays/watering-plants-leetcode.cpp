//Problem Description:You want to water n plants in your garden with a watering can. The plants are arranged in a row and are labeled from 0 to n - 1 from left to right where the ith plant is located at x = i. There is a river at x = -1 that you can refill your watering can at.
//Each plant needs a specific amount of water. You will water the plants in the following way:
//Water the plants in order from left to right.
//After watering the current plant, if you do not have enough water to completely water the next plant, return to the river to fully refill the watering can.
//You cannot refill the watering can early.
//You are initially at the river (i.e., x = -1). It takes one step to move one unit on the x-axis.
//Given a 0-indexed integer array plants of n integers, where plants[i] is the amount of water the ith plant needs, and an integer capacity representing the watering can capacity, return the number of steps needed to water all the plants.

//Time complexity=O(n), space complexity=O(1)

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int wateringPlants(vector<int>& plants, int capacity) { //function block
    int sum=capacity;
    int steps=0;
    for(int i=0;i<plants.size();i++){
        if(plants[i]<=sum){
            sum-=plants[i];
            steps+=1; //incrementing steps by 1
        }
        else{
            sum=capacity; //refilling it 
            sum-=plants[i];
            steps+=i; //refilling requires moving i steps backwards
            steps+=i+1; // coming back to the i th plant takes i+1 steps in forward direction.
        }
      }
        return steps;

}
int main(){ //main function begins here
	vector<int> a{2,2,3,3};
	int capacity=5;
	int number_of_steps=wateringPlants(a,capacity); //function wateringplants called the output number of steps required is returned;
	cout<<"Number of steps needed ";
	cout<<number_of_steps; // output will be 14
	cout<<"\n";
	return 0;
}
