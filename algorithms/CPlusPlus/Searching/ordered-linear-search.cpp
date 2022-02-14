#include <iostream>
using namespace std;
int main()
{
    int array[100];
    int i;
    int key;
    int n;
    int x =0;
    cout<<"Please enter the elements of array \n";
    cin>>n;

     cout<<"Please enter the array elements in ascending order \n";
     for (i=0;i<n;++i)
      cin>>array[i]
    
    cout<<"Please enter the number which you want to find in the inputted array \n";
    cin>>x;
    for(i=0;i<n;++i)
    {
      if(array[i]==x)
      {
        cout<<i;
        break;
      }
      if(array[i]>x)
      {
        cout<<"Element is absent";
        break;
      }
    }

}
