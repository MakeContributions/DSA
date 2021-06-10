//Reversing a linked-list

#include<stdio.h>
#include<stdlib.h>

/*Structure definition
        data : holds the integer value of node
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


/*Function to reverse a linked-list.
    head         - pointer, pointing to the head of the linked-list that we need to reverse
    Return value - pointer, pointing to the head of the reversed linked-list
*/
struct node* reverseList(struct node* head){
    /*We will need three pointers 
        previous : to keep track of the node previous to present node
        present  : to keep track of the present node
        after    : to keep track of the next node
        Initially we will be in the present in the head (first) node
    */
    struct node* previous = NULL;
    struct node* present = head;
    struct node* after = NULL;
    while (present != NULL) {
        //Making 'after' node, point to the next node of 'present' node
        after = present->next;
 
        // Making 'present' node, point to the previous node (REVERSING)
        present->next = previous;
 
        //Going one step further in the linked-list
        previous = present;
        present = after;
    }

    /*After the loop termination, the 'head' will point to the last node of the linked-list.
      All other nodes will also be reversed.
    */
    head = previous;
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

//Driver function
int main()
{   
    //Our linked-list
    struct node* list = NULL;
    int n = 0;

    //Getting the size of the linked-list
    while(n<1){
        printf("\nEnter the number of nodes: ");
        scanf("%d",&n);
        if(n<1) printf("\n\tSize cannot be less than 1. Enter a valid input!\n\n");
    }
    
    printf("\n");

    //Creating the linked-list of given size (n)
    list = createList(list,n);

    //Making sure the linked-list is created.
    if(list!=NULL){
        //Original list
        printf("\nOriginal Linked-list: ");
        display(list);

        //Reversing the linked-list
        list =  reverseList(list);
        printf("\nReversed Linked-List: ");
        display(list);
    }
  
    printf("\n");   
    
    //De-allocating memory
    free(list);
    return 0;
}
