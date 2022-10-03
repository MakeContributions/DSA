#include <iostream>
int main(){
    
    int arr[5]{1,2,3,4,5};
     
    int value = [&]() mutable{ //lambda function & symbol gives assess to outside objects's variable 
        for(int i = 0 ; i<= sizeof(arr) ; i++){
            if(arr[i] == 5) return i; //if the current element 'i' is equal to the value return the index of it. 
        }
    return -1; // it not return -1
    }();
    
    if (value != -1) printf("Value Found Index : %d ",value); 
    else printf("Value Not Found!");
    
}
