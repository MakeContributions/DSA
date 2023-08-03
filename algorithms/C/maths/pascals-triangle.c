
#include<stdio.h> 
long factorial(int);  
int main()  
{  
    int i, n, c;  
    printf("Enter the number of rows you wish to see in pascal triangle\n");  
    scanf("%d", & n);  
    for (i = 0; i < n; i++) {  
        for (c = 0; c <= (n - i - 2); c++) printf(" ");  
        for (c = 0; c <= i; c++) printf("%ld ", factorial(i) / (factorial(c) * factorial(i - c)));  
        printf("\n");  
    }  
    return 0;  
}  
long factorial(int n) {  
    int c;  
    long result = 1;  
    for (c = 1; c <= n; c++) result = result * c;  
    return result;  
}  