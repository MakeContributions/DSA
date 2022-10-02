#include <stdio.h>

void hanoifun(int n, char fr, char to, char ax)//fr=from rod,to =to rod, ax=aux rod
{
    if (n == 1)
    {
        printf("\n Move disk 1 from rod %c to rod %c", fr, to);
        return;
    }
    hanoifun(n-1, fr, ax, to);
    printf("\n Move disk %d from rod %c to rod %c", n, fr, to);
    hanoifun(n-1, ax, to, fr);
}

int main()
{
    int n; // n implies the number of discs
    printf("Enter no. of discs: ");
    scanf("%d", &n);
    hanoifun(n, 'A', 'C', 'B');  // A, B and C are the name of rod
    return 0;
}
