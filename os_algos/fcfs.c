#include<stdio.h>
int main(){
    int a,b,wt[10],bt[10],tat[10],n=4,i,j;

    for(i=0;i<=n;i++){
        printf("enter bt :%d\n",i);
        scanf("%d",&bt[i]);
    }
    wt[0]=0;
    tat[0] = wt[0]+bt[0];
    for(i=1;i<=n;i++){
        wt[i]=tat[i-1];
        tat[i]=bt[i]+wt[i];
        
    }
    printf("\nprocess\t\t burst time\t\t waiting time\t\t turn around time\n");
     for(j=0;j<=n;j++){
        printf("%d\t\t %d\t\t %d\t\t %d\t\t \n",j+1,bt[j],wt[j],tat[j]);
        // printf("%d\t\t %d\t\t %d\t\t %d\t\t \n",j+1,bt[1],wt[1],tat[1]);
        // printf("%d\t\t %d\t\t %d\t\t %d\t\t \n",j+1,bt[2],wt[2],tat[2]);
        // printf("%d\t\t %d\t\t %d\t\t %d\t\t \n",j+1,bt[3],wt[3],tat[3]);
     } 


return 0;

}