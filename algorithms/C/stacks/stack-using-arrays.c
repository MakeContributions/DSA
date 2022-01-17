// Implementation of stack using array

/*
Implement the following stack operations : 
1. Push 
2. Pop 
3. Peek 
4. Display
*/

#include <stdio.h>
#include <stdlib.h>

#define N 50

int stack[N];
int top = -1;

// Push Element at the top of stack
void push()
{
    int x;
    printf("Enter The Element to push: ");
    scanf("%d", &x);
    if (top == N - 1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        top++;
        stack[top] = x;
        printf("%d pushed to Stack\n", x);
    }
}

// Pop the top-element from the stack
void pop()
{
    if (top == -1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        int item = stack[top];
        top--;
        printf("Popped: %d\n", item);
    }
}

// Prints the top-most element
void peek()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Top Element: %d\n", stack[top]);
    }
}

// Prints the stack
void display()
{
    printf("Displaying Stack....\n");
    for (int i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main()
{
    int ch;

    while (1)
    {

        printf("\n*** Stack Menu ***");
        printf("\n\n1.Insert\n2.Delete\n3.Display\n4.Peek\n5.Exit");
        printf("\n\nEnter your choice(1-4):");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            peek();
            break;
        case 5:
            exit(0);
        default:
            printf("\nWrong Choice!!");
        }
    }
    return 0;
}

/*
Output:
*** Stack Menu ***

1.Insert
2.Delete
3.Display
4.Peek
5.Exit

Enter your choice(1-4):1
Enter The Element to push: 4
4 pushed to Stack      

*** Stack Menu ***     

1.Insert
2.Delete
3.Display
4.Peek
5.Exit

Enter your choice(1-4):1
Enter The Element to push: 3
3 pushed to Stack

*** Stack Menu ***

1.Insert
2.Delete
3.Display
4.Peek
5.Exit

Enter your choice(1-4):1
Enter The Element to push: 2
2 pushed to Stack

*** Stack Menu ***

1.Insert
2.Delete
3.Display
4.Peek
5.Exit

Enter your choice(1-4):2
Popped: 2

*** Stack Menu ***

1.Insert
2.Delete
3.Display
4.Peek
5.Exit

Enter your choice(1-4):4
Top Element: 3

*** Stack Menu ***

1.Insert
2.Delete
3.Display
4.Peek
5.Exit

Enter your choice(1-4):3
Displaying Stack....
3 4

*** Stack Menu ***

1.Insert
2.Delete
3.Display
4.Peek
5.Exit

Enter your choice(1-4):5
*/
