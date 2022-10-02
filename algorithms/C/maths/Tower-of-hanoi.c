//Tower of Hanoi is a mathematical puzzle where we have three rods (A, B, and C) and N disks. 
//Initially, all the disks are stacked in decreasing value of diameter 
//The objective of the puzzle is to move the entire stack to another rod, obeying the following simple rules: 

    // 1.Only one disk can be moved at a time.
    // 2.Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack i.e. a disk can only be moved if it is the uppermost disk on a stack.
    // 3.No disk may be placed on top of a smaller disk.

// time complexity is O(2n)
//It is a GP series, and the sum is 2^n - 1   
//T(n)= O( 2^n - 1), or you can say O(2^n)   which is exponential

//sample input: number of discs: 5
//number of steps taken are: 31


#include <stdio.h>

int count = 0;
void hanoifun(int n, char fr, char to, char ax)//fr=from rod,to =to rod, ax=aux rod
{

    if (n == 1)
    {
        printf("\n Move disk 1 from rod %c to rod %c", fr, to);
        count +=1;
        return;
    }
    hanoifun(n-1, fr, ax, to);
    printf("\n Move disk %d from rod %c to rod %c", n, fr, to);
    count +=1;
    hanoifun(n-1, ax, to, fr);
}

int main()
{
    int n; // n implies the number of discs
    printf("Enter no. of discs: ");
    scanf("%d", &n);
    hanoifun(n, 'A', 'C', 'B');  // A, B and C are the name of rod
    printf("\nNumber of steps taken are: %d", count);
    return 0;
}
