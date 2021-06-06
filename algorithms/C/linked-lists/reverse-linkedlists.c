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

//Head pointer of the linked-list
struct node* head;


//Function to create the list of given size
void createList(int size){   
    
    head = (struct node*)malloc(sizeof(struct node));
   
    int new_data;

    //Getting values to enter into linked-list
    printf("Enter the value: ");
    scanf("%d",&new_data);

    head->data = new_data;
    head->next = NULL;
    struct node* temp = head;

    for(int i=1;i<size;i++){
        struct node* new_node = (struct node*)malloc(sizeof(struct node));
        printf("Enter the value: ");
        scanf("%d",&new_data);
        temp->next = new_node;
        new_node->data =  new_data;
        new_node->next = NULL;        
        temp = new_node;
    }
}


//Function to reverse the linked-list
void reverseList(){
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
}


//Function to display the linked-list
void display()
{
   struct node* temp = head;

   while(temp!=NULL){
       printf("%d -> ",temp->data);
       temp = temp->next;
   }

   printf("\n");
}

//Driver function
int main()
{
    int n;

    //Getting the size of the linked-list
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    printf("\n");

    //Creating the linked-list of given size (n)
    createList(n);
    printf("\nOriginal Linked-list: ");
    display();

    //Reversing the linked-list
    reverseList();
    printf("\nReversed Linked-List: ");
    display();
    
    return 0;
}
