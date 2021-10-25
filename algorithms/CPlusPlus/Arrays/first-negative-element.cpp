//c++ program to find the first negative element of every window of size k,this question is the variation of silding window maximum
//sample input :
//arr[]={-8,2,3,-6,10}
//sample output:
// -8 0 -6 -6
//time complexity:outer loop runs n-k+1 times and inner loops will run k time so,O((n-k+1)*k).

#include<bits/stdc++.h>
using namespace std;
void negativeelement(int arr[],int n,int k)
{
	int i,j;
	int size=n-k+1;
	bool flag; // flag for checking if the element found negative set it to true else set it to false
	for(i=0;i<size;i++)
	{    
	      flag=false;
		for(j=0;j<k;j++)
		{
			
			if(arr[i+j]<0)
			{
				cout<<arr[i+j]<<" ";
				flag=true;
				break;
			}
		
		}
		    if(!flag)
			cout<<"0"<<" ";
	}
}
int main()
{
	//array Declartion
int arr[]={-8,2,3,-6,10};
int n= sizeof(arr)/sizeof(arr[0]);
int k=2; //Window size of k
// funtion call
negativeelement(arr,n,k);
return 0;
} 
