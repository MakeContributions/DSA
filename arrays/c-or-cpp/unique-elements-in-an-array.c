#include<stdio.h>

int main(){
    int a[1000];
    int size;
    printf("Enter size of the array: ");
    scanf("%d", &size);
    
    printf("Enter elements of the array: ");
    for(int k=0; k<size; k++){
        scanf("%d", &a[k]);
    }
    int flag;

    for(int i=0; i<7; i++){
        flag = 0;
        
        for(int j=0; j<=7; j++){

            if(i != j && a[i] == a[j]){
            
                flag++;
                  
            }
            
            
            
            
        }
        if(flag == 0){
            printf("Unique elements of the array are %d", a[i]);
        }
    }
}
