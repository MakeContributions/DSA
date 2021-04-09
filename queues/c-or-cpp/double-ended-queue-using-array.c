/* this is a double ended queue implementation using array
means you can insert or delete data from both front and rear */
//included necessary header file
#include<stdio.h>
#include<stdlib.h>
// creating non-primitive named deque using structure concept
struct deque
{
    //declaring necessary variable
    int front;
    int rear;
    int capacity;
    int *arr;

};
// clear function for different platforms ( currently only windows and unix based os are supported )
void clear_screen()
{
    #ifdef _WIN32
        system("cls");
    #elif __unix__
        system("clear");
    #else
        printf("clear screen not supported\n");
    #endif
}
//create deque function mainly give memory to the non-primitive variable deque
struct deque* create_dequeue(int cap)
{
 struct deque *array;
 // dynamically giving memory
 array=(struct deque*)malloc(sizeof(struct deque));
 // declaring default value of cap front rear
 array->capacity=cap;
 array->front=-1;
 array->rear=-1;
// dynamically giving memory
 array->arr=(int*)malloc(sizeof(int)*cap);
 return(array);
}
// insertion front just insert data from front of queue
void insertion_front(struct deque *array,int data)
{
    // checking that whether the queue is not full
if(array->rear+1==array->front||array->rear==array->capacity-1&&array->front==0)
    printf("queue is full");
//checking is the front equal to -1 means queue is empty or not
    else if(array->front==-1)
    {
        array->front=0;
        array->rear=0;
        array->arr[array->front]=data;
    }
    // checking whether the queue has 1 data or not
    else if(array->front==0)
{
 array->front=array->capacity-1;
array->arr[array->front]=data;
}
// normal condition
else
{
    array->front--;
    array->arr[array->front]=data;
}
}
// insertion rear basically insert data from end of a queue
void insertion_rear(struct deque *array,int data)
{
    //checking is the front equal to -1 means queue is empty or not
    if(array->rear==array->capacity-1&&array->front==0||array->rear+1==array->front)
    printf("queue is full");
    //checking is the rear equal to -1 means queue is empty or not
else if(array->rear==-1)
	{
	    array->rear++;
	    array->arr[array->rear]=data;
	    array->front=array->rear;
	}
	// checking whether queue is full from rear but not from front
	else if(array->rear==array->capacity-1&&array->front!=0)
	{
	    array->rear=0;
	    array->arr[array->rear]=data;
	}
	// normal condition
	else
	{
	    array->rear++;
	    array->arr[array->rear]=data;
	}

}
// deletion front basically delete data from front of queue
void deletion_front(struct deque *array)
{
    // queue empty condition
    if(array->front==-1)
	printf("queue is empty");
    else
    {
        // printing the value which is going to be deleted
    printf("deleted value is %d",array->arr[array->front]);
    // checking whether the queue has only one data
	if(array->front==array->rear)
	{
	    array->front=-1;
	    array->rear=-1;
	}
	// checking whether front is equal to capacity-1
	else if(array->front==array->capacity-1)
	    array->front=0;
	// normal condition
	else
	    array->front++;


 }
}
// deletion rear basically delete data from end of queue
void deletion_rear(struct deque *array)
{
    //empty condition
    if(array->rear==-1)
      printf("queue is empty");
      else
      { printf("deleted value is %d",array->arr[array->rear]);
    // checking whether the queue has only one data
          if(array->rear==array->front)
          {
        array->front=-1;
	    array->rear=-1;
          }
          // checking whether rear is 0 but there not only one data left that means that data are at end of queue
          else if(array->rear==0)
            array->rear=array->capacity-1;
            //normal condition
          else
            array->rear--;
      }
}
// menu basically provide the no. of task can be performed so you can choose one of them
int menu(void)
{
    int choice;
    printf("\n1: Insertion at Front");
    printf("\n2: Insertion at Rear");
    printf("\n3: Deletion at Front");
    printf("\n4: Deletion at Rear");
    printf("\n5: exit");
    printf("\n\n enter your choice");
    scanf("%d",&choice);
    return(choice);
}
// driver code
int main()
{
    struct deque *array;
    int cap,data;
    printf("enter the capacity");
    scanf("%d",&cap);
    array=create_dequeue(cap);
    while(1)
    { clear_screen();
        switch(menu())
        {
        case 1:
            printf("enter value");
            scanf("%d",&data);
            insertion_front(array,data);
            break;
        case 2:
            printf("enter value ");
            scanf("%d",&data);
            insertion_rear(array,data);
            break;
        case 3:
            deletion_front(array);
            break;
        case 4:
            deletion_rear(array);
            break;
        case 5:
            exit(0);
        }

    }
return 0;

}
/*
Input: Insert 3 at front
       Insert 2 at rear
       Insert 5 at rear
       Delete from rear
       delete from front
Output:
5 had been deleted
3 had been deleted
Time complexity:O(n)

*/

