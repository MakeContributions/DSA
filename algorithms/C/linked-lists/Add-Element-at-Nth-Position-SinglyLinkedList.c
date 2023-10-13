// This program will help us to add an element at any position in a singly linked list.
// Also this program will help us to insert a node at the end of the list.

#include<stdio.h>
#include<stdlib.h>

typedef struct stud
{
	int info;	//stores the data of the node
	struct stud *link;	//stores the pointer to the next node
}Node;

Node *start=NULL; // start is a pointer variable of Node type and it stores the address of first node

void add_node(int data) // to add the data at the end of the linked list
{
	Node *newptr=NULL,*ptr;
	newptr=(Node*)malloc(sizeof(Node));//A new node will be created and the adrress is stored in newptr
	newptr->info=data;
	newptr->link=NULL;
	if(start==NULL)// If true, it means there is no Linked list at all
	{
		start=newptr; // start and newptr both are pointing to the same node
	}
	else
	{
		ptr=start;// It means start and ptr both are pointing to the same node
	
	while(ptr->link!=NULL)
	{
		ptr=ptr->link;// the value/ address of ptr->link will be stored in ptr
	}
	ptr->link=newptr;// store the address of newptr to ptr->link.  
	//That is link the new node with the linked list
}
}

void add_anypos(int pos,int data) // to add a the data at a particular position(stored in pos) of the linked list
{
	int step=1;
    Node *newptr=NULL;
    newptr=(Node*)malloc(sizeof(Node));//A new node will be created and the adrress is stored in newptr
	newptr->info=data;
	Node *tptr=start;
    
    if(pos == 1){
        newptr->link=start;
        return;
    }

	while(step<pos-1) 
	{	
		tptr=tptr->link;
        ++step;
	}

    newptr->link=tptr->link;	//newptr->link points to the rest of the linked list after the given position
	tptr->link=newptr;			//newptr is now added to the required position
}


void display()// to display the linked list
{
	Node *ptr;
	ptr=start;// It means start and ptr both are pointing to the same node

    printf("\nThe linked list is : \n");

	while(ptr)
	{
		printf("%d->",ptr->info);
		ptr=ptr->link;
	}
	printf("NULL\n");
}


int main()
{
 int value,pos,count=0;
 char choice,choice_pos;

 while(1)// while loop will execute for infinite time if the choice=='y'. 
 //If choice=='n' or choice=='N' it will stop
{
  	printf("\nDo you want to insert(y/n)?");
  	scanf("%c",&choice);	//accepting user's choice if they want to add more data to the linked list or not

  	if(choice == 'y'||choice == 'Y')
	{

  	printf("\nEnter the info:");
    scanf("%d",&value);// the value to be added to the linked list

    fflush(stdin);

    printf("\nDo you want to insert the data at a particular position(y/n)?");
  	scanf("%c",&choice_pos);	//accepting user's choice if they want to add the data to a particular position or not
    fflush(stdin);

    if(choice_pos == 'y'||choice_pos == 'Y'){
        printf("\nEnter the position: ");
  	    scanf("%d",&pos);	// the position at which the value is to be added
        add_anypos(pos,value);
    }
    else    add_node(value);	

  	fflush(stdin);

	}

	else    break;

}

display();// It will display the entire linked list

return 0;

}
