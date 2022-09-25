#include <stdio.h>
/*
	*Tower of Hanoi*

	*Rule:
	
	1. Only one disk can be moved at a time.
	2. Each move consists of taking the upper disk from one of the stacks 
	   and placing it on top of another stack i.e. 
	   a disk can only be moved if it is the uppermost disk on a stack.
	3. No disk may be placed on top of a smaller disk.

	* Time Complexity : O(2^n) 
	* Space Complexity: O(n) 
*/


void towerOfHanoi(int disk, char from, char by, char to)
{
	if (disk == 1) // If the number of disks to move is one
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

	// Move N disks of Tower A to Tower C via Tower B
	towerOfHanoi(disk, 'A', 'B', 'C');
	
	return 0;
}

/*
                                Sample

                input             |                     output
                                  |
              disk : 3            |             Move disk 1 from A to C
                                  |             Move disk 2 from A to B
                                  |             Move disk 1 from C to B
                                  |             Move disk 3 from A to C
                                  |             Move disk 1 from B to A
                                  |             Move disk 2 from B to C
                                  |             Move disk 1 from A to C


---------------------------------------------------------------------------


                   **Image illustration for 3 disks**


        standby                                         step 1

    A      B      C                             A         B        C

    |      |      |                             |         |        |
    |      |      |                             |         |        |
   ###(1)  |      |                             |         |        |
  #####(2) |      |                           #####       |        |
_#######(3)|______|__                       _#######______|_______###_



         step 2                  step 3	                 step 4

    A      B      C        A       B      C        A       B       C

    |      |      |        |       |      |        |       |       |
    |      |      |        |       |      |        |       |       |
    |      |      |        |       |      |        |       |       |
    |      |      |        |      ###     |        |      ###      |
_#######_#####___###__  #######__#####____|___   __|_____#####__#######__



         step 5                  step 6	                    step 7

    A      B      C         A      B      C          A        B	       C

    |      |      |         |      |      |          |	      |	       |
    |      |      |         |      |      |          |        |        |
    |      |      |         |      |      |          |        |	      ###
    |      |      |         |      |    #####        |        |	     #####
___###___#####_#######_	___###_____|___#######_    __|________|_____#######__


*/
