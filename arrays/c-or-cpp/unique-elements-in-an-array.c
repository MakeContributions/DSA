#include<stdio.h>

int main(){
    int a[7];
    
    for(int k=0; k<7; k++){
        scanf("%d", &a[k]);
    }
    int flag;

    for(int i=0; i<7; i++){
        flag = 0;
        
        for(int j=0; j<=7; j++){

            if(i != j){
            
                if(a[i] == a[j]){
                    flag++;
                    
                }
            }
            
            
            
            
        }
        if(flag == 0){
            printf("%d", a[i]);
        }
    }
}