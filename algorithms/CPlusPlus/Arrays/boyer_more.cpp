//majorty element of an array 
// element with frequency > (n/2) {n: size of array}
//time complexity : O(n) || space complexity : O(1)


#include<iostream>



using namespace std;


void ismaj(int arr[],int n,int exp_maj){

    int i=0;
    int len = n;

    int count =0;
    for(i=0;i<len;i++){
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


int majelement(int arr[],int n){ // maj element function

     int len = n;
     int i=0;

     int ans_index=0; // setting ans_index initially as the first element
     int count =1; // setting count of first element as 1

    for(i=0;i<len;i++){
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
    int arr[5] = {2,2,2,5,6};

    int result = majelement(arr,5);
    ismaj(arr,5,result);
    return 0;
}
