//Merging two Linked-List

#include<stdio.h>
#include<stdlib.h>

/*Structure definition:
     data : holds the integer value of the node
     next : holds the pointer to the next node
*/
struct node
{
    int data;
    struct node *next;
}*la,*lb;                         
//We have two linked-lists: la (List A) and lb (List B)


//Function to create List A of given size
void lista(int size)
{
    int a,i;
    struct node *temp,*newnode;

    //Head node of List A
    la=(struct node*)malloc(sizeof(struct node));

    //Getting values to enter into List A
    printf("\nEnter the value for A: ");
    scanf("%d",&a);
    la->data=a;
    la->next=NULL;
    temp=la;
    for(i=1; i<size; i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the value for A: ");
        scanf("%d",&a);
        newnode->data=a;
        newnode->next=NULL;
        temp->next=newnode;
        temp=newnode;
    }
    printf("\n");
}

//Function to create List B of given size
void listb(int size)
{
    int b,i;
    struct node *temp,*newnode;

    //Head node of List B
    lb=(struct node*)malloc(sizeof(struct node));
    
    //Getting values to enter into List B
    printf("\nEnter the value for B: ");
    scanf("%d",&b);
    lb->data=b;
    lb->next=NULL;
    temp=lb;
    for(i=1; i<size; i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the value for B: ");
        scanf("%d",&b);
        newnode->data=b;
        newnode->next=NULL;
        temp->next=newnode;
        temp=newnode;
    }
    printf("\n");
}

//Function to display the Merged Linked-lists
void display()
{
    struct node *temp=la;
    while(temp!=NULL)
    {
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

/*Function to merge the two linked-lists:
        List A -> List B
 */
void merge()
{
    struct node *temp=la;

    //Making the last node of List A , to point to the head node of List B
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=lb;
}


//Driver function
int main()
{
    int sizeOfListA;
    int sizeOfListB;

    //Getting the size of List A
    printf("Enter the size of List A: ");
    scanf("%d",&sizeOfListA);

    //Creating List A of given size
    lista(sizeOfListA);

    //Getting the size of List B
    printf("\nEnter the size of List B: ");
    scanf("%d",&sizeOfListB);

    //Creating List B of given size
    listb(sizeOfListB);

    //Merging List A and List B
    merge();

    //Displaying the merged list
    printf("\nAfter merging List A and List B:\n\n");
    display();

    return 0;
}
