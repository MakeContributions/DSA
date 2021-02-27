/*Circular linked list implementation in C Programming
has been used to solve this problem

Problem :
People are standing in a circle waiting to be executed. 
Counting begins at a specified point in the circle and proceeds around 
the circle in a specified direction. The problem is to find the person standing at which position
survives at the end, who is then deemed to be the winner.

*/
#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
}*first,*last;
void create (int a[],int n){// for creating nodes
    struct Node *t;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=a[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
    last->next=first;

}
void display(struct Node *p){ //displaying nodes
 printf("The Linked List is successfully created\n");
   while(p->next!=first){
       printf("->%d",p->data);
       p=p->next;
   }
   printf("->%d",p->data);
}
void josephus(int k, struct Node *first){ //josephus implementation
    struct Node *trail;
    if (k==1){
       printf("The Winner is the person standing at= %d",last->data); 
    }
    else{
    while(first->next!=first){
        int count=1;
        while(count!=k){
        trail=first;
        first=first->next;
        count++;
        }
      trail->next=first->next;
      free(first);
      first=trail->next;
    }
    printf("The Winner is the person standing at= %d",first->data);
    }
}
int main() {
   int n,a[100],k;
   printf("Enter the number of people in the circle : ");
   scanf("%d",&n);
   printf("Enter their positions in the circle: ");
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    create(a,n);
    display(first);
    printf("\n");
    printf("Enter the number of skips: ");
    scanf("%d",&k);
    josephus(k,first);
   
    return 0;
}
