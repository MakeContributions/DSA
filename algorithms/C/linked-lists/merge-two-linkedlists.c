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
};

/*Function to create a linked-list of given size with passed head pointer.
    head          - pointer to the first node of the linked-list
    size          - number of nodes in the linked-list
    Return value  - Returns a pointer, pointing to the head node of the linked-list
*/
struct node* createList(struct node* head,int size)
{
    struct node* prev = NULL;

    //To store value (user-input)
    int a;
    for(int i=1;i<=size;i++){
        //If head node
        if(i==1){
            head = (struct node*)malloc(sizeof(struct node));     //Allocating memory
            if(head!=NULL){
                printf("\nEnter a value: ");
                scanf("%d",&a);
                head->data = a;
                head->next = NULL;
                prev = head;
            }
            //If memory cannot be allocated
            else{
                printf("\nCannot allocate memory!");
                return head;
            }
        }
        else{
            struct node* current = NULL;
            current = (struct node*)malloc(sizeof(struct node));
            if(current!=NULL){
                printf("\nEnter a value: ");
                scanf("%d",&a);
                current->data = a;
                current->next = NULL;
                prev->next = current;
                prev = current;
            }
            //If memory cannot be allocated
            else{
                printf("\nCannot allocate memory!");
                return head;
            }
        }        
    }
   printf("\n");
   return head;
}


//Function to display a linked-list from the passed head pointer
void display(struct node* head)
{
    struct node *temp = head;
    while(temp!=NULL)
    {
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("\n\n");
}


/*Function to merge linked-lists of given order.
    a_list  - head pointer of List A
    b_list  - head pointer of List B
    first   - number specifying the order of merging
        if first==1:
            Order of merging will be List A -> List B
        if first==2:
            Order of merging will be List B -> List A
    Return value - Returns a pointer, pointing to the head node of the merged linked-list
*/
struct node* merge(struct node* a_list,struct node* b_list,int first)
{   
    struct node* temp1;
    struct node* temp2;

    if(first==1){
        temp1 = a_list;
        temp2 = b_list;
    }
    else{
        temp1 = b_list;
        temp2 = a_list;
    } 

    while(temp1->next!=NULL)
    {
        temp1=temp1->next;
    }
    temp1->next=temp2;

    return (first==1)?a_list:b_list;
}


//Driver function
int main()
{
    //Our two linked-lists
    struct node* lista = NULL;
    struct node* listb = NULL;

    int sizeOfListA = 0;
    int sizeOfListB = 0;

    //Getting the sizes of the linked-list
    while(sizeOfListA<1 || sizeOfListB<1){
        printf("\nEnter the size of List A: ");
        scanf("%d",&sizeOfListA);

        printf("Enter the size of List B: ");
        scanf("%d",&sizeOfListB);
        if(sizeOfListA<1 || sizeOfListB<1)  printf("\n\tSize cannot be less than 1. Enter a valid size!\n\n");
    }

    //Displaying List A
    printf("\nFor List A: ");
    lista = createList(lista,sizeOfListA);
    printf("\nList A: \n");
    display(lista);

    //Displaying List B
    printf("\nFor List B: ");
    listb = createList(listb,sizeOfListB);
    printf("\nList B: \n");
    display(listb);

    //Checking whether both the linked-lists are not NULL
    if(lista!=NULL && listb!=NULL){
        //Getting the order of merging
        int option;
        
        while(option!=1 && option!=2){
             printf("\nOptions for Merging:\n\n\t1. List A -> List B (Enter 1)\n\t2. List B -> List A (Enter 2)\n");
             printf("\nEnter the option: ");
             scanf("%d",&option);
             if(option!=1 && option!=2) printf("\n\tInvalid option!\n");
        }
        
        //Merging the two linked-lists
        struct node* output = merge(lista,listb,option);
        printf("\nAfter Merging:\n\n");
        display(output);        
        
    }

    printf("\n");
    
    //De-allocating the memory
    free(lista);
    free(listb);
    
    return 0;
}
