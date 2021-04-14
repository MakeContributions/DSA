#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int size;
    /* take the size of the array from user as input */
    printf("Enter size of the array: ");
    scanf("%d", &size);
    
    /* dynamically create an array of the reqruired size */
    int *a = (int*)malloc(sizeof(int)*size);
    
    if(size<0){
        size = size*(-1);
    }
    
    /* enter the elements to the array */
    printf("Enter elements of the array: ");
    for(int k=0; k<size; k++){
        scanf("%d", &a[k]);
    }
    
    int flag;    
    printf("Unique elements of the array are : ");
    for(int i=0; i<size; i++){
        flag = 0;
        
        for(int j=0; j<=size; j++){

            if(i != j && a[i] == a[j]){
            
                flag++;
                  
            }
   
        }
        if(flag == 0){
            printf("%d ", a[i]);
        }
    }
}
