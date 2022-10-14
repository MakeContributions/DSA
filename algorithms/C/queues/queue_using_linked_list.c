#include <stdio.h>
#include <stdlib.h>
struct node *enqueue(struct node*);
struct node *dequeue(struct node*);
void display(struct node*);
void peek(struct node*);
struct node{
    int data;
    struct node *next;
};

int main(){
    struct node *front=0,*rear=0;
    int choice;
    printf("Press 1 for Enqueue\nPress 2 for Dequeue\nPress 3 for Display\nPress 4 for Peek\nPress 5 for Exit\n");
    do{
        printf("\nEnter the choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: rear=enqueue(rear);
            if(front==0){
                front=rear;
            }
            break;

            case 2: if(front==0 && rear==0){
                printf("Queue is Empty");
                break;
            }
            else{
                front=dequeue(front);
                if(front==0){
                    rear=0;
                }
                break;
            }

            case 3: if(front==0){
                printf("Queue is Empty");
                break;
            }
            else{
                display(front);
                break;
            }

            case 4: if(front==0){
                printf("Queue is Empty");
                break;
            }
            else{
                peek(front);
                break;
            }

            case 5: break;
            default: printf("Invalid Choice");
        }
    }while(choice!=5);
}
struct node *enqueue(struct node *rear){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d",&newnode->data);
    newnode->next=0;
    if(rear==0){
        rear=newnode;
    }
    else{
        rear->next=newnode;
        rear=newnode;
        return rear;
    }
}
struct node *dequeue(struct node *front){
    struct node*temp=front;
    printf("The enqueued element is %d",front->data);
    front=front->next;
    free(temp);
    return front;
}
void display(struct node *front){
    struct node *temp=front;
    printf("The elements in the queue are: ");
    while(temp!=0){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
void peek(struct node *front){
    printf("The Peek element is %d",front->data);
}
