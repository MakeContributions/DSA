#include <stdio.h>
#include <stdlib.h>
#define MAX 10 // size of the array is defined

// global variable
// using front and rear to keep track of the elements in the queue
int front = -1, rear = -1, circQueue[MAX];

// function to insert element in the queue
void enqueue(){
   int num;
   printf("Enter the number to be inserted: ");
   scanf("%d", &num);

   // this means the queue is full and no more element can be inserted
   if(rear == MAX-1){
      printf("Overflow");
   }
   // queue is empty
   else if(front == -1 && rear == -1){
      front = 0;
      rear = 0;
   }
   // reached the end and the beginning index is empty
   else if(rear == MAX - 1 && front != 0){
      rear = 0;
   }
   else {
      rear += 1;
   }
   //inserting the element at the rear position
   circQueue[rear] = num;
}

// function to delete an element from the queue
void dequeue(){
   // this means the queue is empty and you cannot take out more elements out of it
   if(front == -1){
      printf("Underflow");
   }
   // reached the last element
   else if(front == rear){
      front = -1;
      rear = -1;
   }
   // reached end of the array since it is circular so front = 0 again.
   else if(front == MAX - 1){
      front = 0;
   }
   else {
      front += 1;
   }
}

// to print the queue
void display(){
    int i;
    if(front == -1 || rear == -1)
    {
        printf("\nEmpty queue\n");
    }
    else {
       printf("The queue is: ");
       for (i = front; i <= rear; i++){
       printf("%d ", circQueue[i]);
    }
    printf("\n");
  }
}

int main()
{
    // asking the user for the choice
    int choice;
    while(1){
        printf("Enter your choice: \n1. Enqueue \n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);

    switch(choice){
       case 1:
          enqueue(); // if user inserts one it will call the enqueue function
          break;
       case 2:
          dequeue();  // if user inserts two it will call the dequeue function
          break;
       case 3:
          display(); //if user inserts three it will print the result
          break;
       case 4:
          return 0;  // exits from the program
       default:
          printf("Enter valid choice");
          break;
       }
    }
    return 0;
}

/*
Sample Input:
1
3
1
3
1
3
2
3

Sample Output:
Enter the number to be inserted: 3
The queue is: 3

Enter the number to be inserted: 5
The queue is: 5 3

Enter the number to be inserted: 7
The queue is: 7 5 3

The queue is: 7 5

Time Complexity of Insertion, Deletion: O(1) that is constant

To run the program simply copy the code in a notepad or code editor then save it with extension .c and run it in the terminal using gcc file_name.c or simply run in it in a code editor.
*/
