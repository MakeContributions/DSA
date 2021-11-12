/*
STACK - Stack of something in real world is the same as the stack data structure. Like you put things on top of other things. Stack is a data structure that follows the rule Last In First Out (LIFO) i.e. element inserted at the end is taken out first and they have this condition that no element can be taken out without the element on the top being removed.

STack can be implemented using arrays and linked list.

Here, We will see the implementation using arrays.

A menu-driven program to push, pop and display the elements of the stack.

Sample Input:
1 (push operation)
2 (input value)
3 (display)
1 (push)
3 (input)
1 (push)
4 (input)
3 (display)
2 (pop)
2 (pop)
2 (pop)
2 (pop)

Sample Output:
Enter the element you want to push: 2
The elements are: 2
Enter the element you want to push: 3
Enter the element you want to push: 4
The elements are: 4 3 2
The elements are: 3 2
The elements are: 2
The elements are: 
Underflow

Time Complexity: O(1)

*/

#include <stdio.h>
#include <stdlib.h>

# define MAX 5 // size of the array you can change it to any size you want

// global variables
int top = -1, stack[MAX];

// function for pushing element
void push(int value){
   if(top == MAX - 1){
      printf("Overflow, Insertion not possible!"); // that means the stack is full and no more elements can be added to it (StackOverflow)
   }
   else {
      top++; // increasing size
      stack[top] = value; // assigning the top the value to be inserted
   }
}

//popping the top element out
char pop(){
  if(top == -1){
     printf("Underflow"); // that means no more element can be popped out of the stack
  }
  else {
  return stack[top--];
}
}

// function to display the elements present in the stack
void display(){
   if(top == -1){
      printf("Stack is empty");
   }
   else {
     printf("The elements are: \n");
     for (int i = top; i >= 0; i--){ // since stack uses LIFO pattern so the element must be printed from the top to bottom
        printf("%d ", stack[i]);
     }
   }
}

int main()
{
    while(1){
       int choice, val;

       printf("\nEnter your choice: \n1. Push Element \n2. Pop Element \n3. Display element \n5. Exit\n");
       scanf("%d", &choice);

       if(choice == 1){
          printf("Enter the element you want to push:  ");
          scanf("%d", &val);
          push(val);
       }
       else if(choice == 2){
           pop();
       }
       else if(choice == 3){
           display();
       }
       else {
           printf("Exiting...");
           return 0;
       }

    }

    return 0;
}