//majority element of an array 
// element with frequency > (n/2) {n: size of array}
//time complexity : O(n) || space complexity : O(1)

#include<iostream>

using namespace std;

void ismaj(int arr[],int n,int exp_maj){ // checks the if the candidate element is actually the majority element or not

    int i=0;
    int count =0;
    for(i=0;i<n;i++){
        if(arr[i]==arr[exp_maj]){
            count++;
        }
    }

    if(count>(n/2)){
        cout<<"majority element : "<<arr[exp_maj];
    }
    else{
        cout<<"no majority element found\n";
    }
}


int majelement(int arr[],int n){ // majority element function to find the candidate majority element 

     int ans_index=0; // setting ans_index initially as the first element
     int count =1; // setting count of first element as 1

    for(int i=0;i<n;i++){
        if(arr[i]==arr[ans_index]){
            count++;
        }
        else{
            count--;
        }

        if(count ==0){ 
            ans_index=i; // updating ans_index as the ith element
            count =1; // resetting count
         }
    }

    return ans_index;// expected majority element
} 


int main(){ // main function begins here
    int size;
    cout<<"enter the size of the array : ";
    cin>>size;

    int *arr = new int[size];

    for(int i=0;i<size;i++){
        cout<<"enter "<<i<<" th element of array : ";
        cin>>arr[i];
    }

    int result = majelement(arr,size);
    ismaj(arr,size,result);
    return 0;
}
