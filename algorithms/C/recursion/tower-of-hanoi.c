#include <stdio.h>

void towerOfHanoi(int disk, char from, char by, char to)
{
	if (disk == 1)
	{
		printf("Move disk 1 from %c to %c \n", from, to);
	}
	else
	{
		towerOfHanoi(disk - 1, from, to, by);
		printf("Move disk %d from %c to %c \n", disk, from, to);
		towerOfHanoi(disk - 1, by, from, to);
	}

}

int main()
{
	int disk;
	
	printf("Enter the number of disks you want : ");
	scanf("%d", &disk);

	towerOfHanoi(disk, 'A', 'B', 'C');
	
	return 0;
}