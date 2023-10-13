#include <stdio.h>
#include <stdlib.h>
// KHUSHBOO NIJAHWAN
typedef struct Node{
    int data;
    struct Node *next, *prev;
}node;

node *BML(int n)
{
    node *head = NULL;
    node *ptr =  head, *ptr_prev = head;

    for(int i=0; i<n; i++){
        if(i == 0){
            head = (node*)malloc(sizeof(node));
            head->data = i+1;
            head->next = head->prev = head;
            ptr_prev = head;
        }
        else{
            ptr = (node*)malloc(sizeof(node));
            ptr->data = i+1;
            ptr_prev->next = ptr;
            ptr->prev = ptr_prev;
            ptr_prev = ptr;
        }
    }
    ptr->next = head;
    head->prev = ptr;
    return head;
}

void display(node *head)
{
    node *ptr = head;
    do{
        printf("%d-> ", ptr->data);
        ptr = ptr->next;
    }while(ptr != head);
    printf("\b\b\b  \n");
}

void display_rev(node *head)
{
    node *ptr = head;
    do{
        printf("%d-> ", ptr->data);
        ptr = ptr->prev;
    }while(ptr != head);
    printf("\b\b\b  \n");
}

int josephus_Khushboo(node *head, int k)
{
    display(head);
    node *ptr = head;
    if(ptr->next == head)
        return ptr->data;
    
    node *todel=ptr, *todel_prev = todel->prev;
    for(int i=1; i< k; i++){
        todel_prev = todel;
        todel = todel->next;
    }
    node *new_head = todel->next;
    new_head->prev = todel_prev;
    todel_prev->next = new_head;
    
    free(todel);
    return josephus_Khushboo(new_head, k);
}

int main()
{
    node *head = NULL;
    int n, k;

    printf("Enter n: ");
    scanf("%d", &n);
    head = BML(n);
    printf("Enter k: ");
    scanf("%d", &k);
    printf("Survival: %d\n", josephus_Khushboo(head, k));
    printf("By Khushboo Nijhawan\n");
     printf("20BML0035");
    return 0;
}