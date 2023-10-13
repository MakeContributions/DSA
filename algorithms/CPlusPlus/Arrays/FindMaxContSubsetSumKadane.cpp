//kadane's algorithim is used to find out the max sum in the array
// contiguos sum,this technique takes O(n)time complexibility and 0(1) space complexibility

#include<iostream>
using namespace std;

 //kadane's algorithim
int kadaneAlgo(int *arr,int size){
int max_end_here=0;
  int best_so_far=0;

  for (int i = 0; i < size; i++)
  {
  	if (arr[i]>0) //checking the element is positive or not
  	{
  	  max_end_here +=arr[i];   //if positive add to max_end_till_now
	  	 
	  	 if (max_end_here>best_so_far)  //if till_now_max is greater than best_max then assign that value to best_so_far
	  	 {
	  	 	best_so_far=max_end_here;    	
	  	 }
  	}
    else
  		{max_end_here=0; } //if the no. is negative then assign 0 to max_end

  }
  return best_so_far; //returning the max sum
}//kadane ensds


int main(){
  int n;          //no. of elements in the array
  cin>>n;

  int *p=NULL;
  p = new int [n];
  for (int i = 0; i < n; i++)
  {
  	cin>>p[i];   	
  }//for loop ends to take the array elements

  //kadane's algorithim
  
cout<<kadaneAlgo(p,n);

}