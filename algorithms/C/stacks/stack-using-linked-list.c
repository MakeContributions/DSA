// Implementation of stack using Linked List

/*
Implement the following stack operations : 
1. Push 
2. Pop 
3. Peek
4. Display
*/

#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int data;
    struct Stack *next;
};

struct Stack *top = NULL;

// Push Element at the top of stack
void push()
{
    int x;
    printf("Enter Element to be pushed\n");
    scanf("%d", &x);
    struct Stack *newNode = (struct Stack *)malloc(sizeof(struct Stack));
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

// Pop the top-element from the stack
void pop()
{
    struct Stack *temp = (struct Stack *)malloc(sizeof(struct Stack));
    temp = top;
    if (top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Popped Element is %d\n", top->data);
        top = top->next;
        free(temp);
    }
}

// Prints the top-most element
void peek()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Top element is %d\n", top->data);
    }
}

// Prints The Stack
void display()
{
    struct Stack *temp = (struct Stack *)malloc(sizeof(struct Stack));
    temp = top;
    if (top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}

int main()
{
    int opt;
    while (1)
    {

        printf("which operation do you want to perform?\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.Display\n");
        printf("5.Exit\n");

        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Unknown operation\n");
        }
    }
    return 0;
}

/*
which operation do you want to perform?
1.Push
2.Pop
3.Peek
4.Display
5.Exit
1
Enter Element to be pushed
12
which operation do you want to perform?
1.Push
2.Pop
3.Peek
4.Display
5.Exit
1
Enter Element to be pushed
10
which operation do you want to perform?
1.Push
2.Pop
3.Peek
4.Display
5.Exit
1
Enter Element to be pushed
3
which operation do you want to perform?
1.Push
2.Pop
3.Peek
4.Display
5.Exit
4
3 10 12 
which operation do you want to perform?
1.Push
2.Pop
3.Peek
4.Display
5.Exit
2
Popped Element is 3
which operation do you want to perform?
1.Push
2.Pop
3.Peek
4.Display
5.Exit
4
10 12 
which operation do you want to perform?
1.Push
2.Pop
3.Peek
4.Display
5.Exit
5
*/