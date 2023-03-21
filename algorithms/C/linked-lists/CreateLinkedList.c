#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node*start=NULL;
void create_list(int);
void display();
struct node *delete(int);

void main()
{
    int choice,n,m,i,l;
    while (1)
    {
        printf("1.create list\n");
        printf("2.display\n");
        printf("3.Delete\n");
        printf("4.Quit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("How many nodes you want to enter:-");
            scanf("%d",&n);
            for ( i = 0; i < n; i++)
            {
                printf("enter the element %d:",i+1);
                scanf("%d",&m);
                create_list(m);
            }
            break;
        case 2:
            display();
            break;
        case 3:
            printf("enter element you want to delete:-");
            scanf("%d",&l);
            delete(l);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("-------invalid option-------\n");
            break;
        }
    }
    getch();
}
void create_list(int m)
{
    struct node*q,*tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->data=m;
    tmp->link=NULL;
    if (start==NULL)
    {
        start=tmp;
    }
    else
    {
        q=start;
        while (q->link!=NULL)
        {
            q=q->link;
        }
        q->link=tmp;
    }
}
struct node*delete(int l)
{
    struct node *q,*tmp;
    if (start->data==l)
    {
        tmp=start;
        start=start->link;
        free(tmp);
        return start;
    }
    q=start;
    while (q->link!=NULL)
    {
        if (q->link->data==l)
        {
            tmp=q->link;
            q->link=tmp->link;
            free(tmp);
            return start;
        }
        q=q->link;
    }
}
void display()
{
    struct node*q;
    if (start==NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        q=start;
        printf("your list is:");
        while (q!=NULL)
        {
            printf("%d\n",q->data);
            q=q->link;
        } 
        printf("\n");   
    }
}