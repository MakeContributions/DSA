/* Finding maximum,minimum and average of an array 

SAMPLE INPUT: 4
               5
               6
               7
               8
               
SAMPLE OUTPUT: 8
               5
               6
                       */

//Time complexity= O(n)
//Space complexity= O(n)

//DESCRIPTION
//Problem related to find the maximum, minimum and average from the given array.


#include<iostream>
using namespace std;

//function to find max element in an array

int max(int *arr, int k, int size) 
{
    int i;
for(i=1; i<size; i++)
{
    if(arr[i]>k)
    {
        k=arr[i];
    }
}
return k;
}

//function to find min element in an array

int min(int *arr, int k, int size) 
{
    int i;
for(i=1; i<size; i++)
{
    if(arr[i]<k)
    {
        k=arr[i];
    }
}
return k;
}

//function to find average of an array

int avg(int *arr, int k, int size)  
{
    int sum=0,avg;
    for(int i=0; i<size; i++)
    {
     sum=sum+arr[i];  //finding sum of every element in an array
    }
     avg=sum/size;
     return avg;
}

int main()
{
    int size;
    int k=0;
    cout<<"Enter the size of an array\n";
    cin>>size;
    int *arr=new int[size];   //dynamic memory allocation 
    cout<<"Enter elements in an array\n";
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
    k=arr[0];
    cout<<"Maximum element is:\n"<<max(arr,k,size)<<"\n";
    cout<<"Minimum element is:\n"<<min(arr,k,size)<<"\n";
    cout<<"Average will be:\n"<<avg(arr,k,size)<<"\n";
    return 0;
}
