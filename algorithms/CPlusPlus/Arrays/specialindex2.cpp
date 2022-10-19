/*
@author: nandinisahu407
special index-> if after deleting element from index i , sum of even index=sum of odd index
approach->
after deleting ,previous element at odd index will be now at even index and vice versa
s_odd= odd[0 to i]+ even[i+1 to len]
s_even=even[0 to i]+odd[i+1 to len]

*/
#include<iostream>
using namespace std;
 
int main(){
    int num;
    cout<<"enter length"<<endl;
    cin>>num;
    int arr[num];
    for(int i=0;i<num;i++){
        cin>>arr[i];
    }

    int count=0;
    int s_even,s_odd;
    for(int i=0;i<num;i++){ //checking whether special index or not
        s_even=0,s_odd=0;

        for(int j=0;j<i;j++){   // from index[0,i]
            if(j%2==0){
                s_even+=arr[j];
            }
            else{
                s_odd+=arr[j];
            }
        }
        for(int j=i+1;j<num;j++){    //from index[i+1,len]
            if(j%2==0){
                s_odd+=arr[j];
            }
            else{
                s_even+=arr[j];
            }
        }

        if(s_even==s_odd){    //checking whether sum of even index=sum of odd index
            cout<<"\n special index found at: "<<i;
            count++;
        }
        else{
            continue;
        }

    }
    cout<<"\n total special index: "<<count;   //displaying
    return 0;
}
/* ----INPUT-----
enter length 6
4 3 2 7 6 -2
----- OUTPUT------
special index found at: 0
special index found at: 2
total special index:2
*/
//time complexity:o(n^2)