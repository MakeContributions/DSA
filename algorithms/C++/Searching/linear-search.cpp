#include<iostream> //Header Files
using namespace std;
int main()
{
    int array[100];
    int i;
    int key;
    int n;
    int pos =0;
    cout<<"please enter the elements of array \n";
    cin>>n;

     cout<<"please enter the array elements \n";
    for (i=0;i<n;++i)
   
      cin>>array[i];
    cout<<"the elements of the array are \n";
    for (i=0;i<n;++i)
    
     cout<<array[i]<<" ";
     cout<<"\n";
    cout<<"please enter the number which you want to find in the inputted array \n";
    cin>>key;
    cout<<"the inputted no is at position \n";
    for(i=0;i<n;++i)
    {
      

      if(key==array[i]&&i<n)
        
        cout<<i+1<<"\n";
      
         
      }
}
