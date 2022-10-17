/* given a long route containing N,S,E,W direction
   find the shortest path to reach the location
 sample input : S,N,N,N,E,W,E
 Sample Output : N,N,E
*/

/* simply analyze the problem in the form of a graph and you are at the origin at (0,0)
and x is east , -x is west , y is south , -y is north now if its south you will move on y 
axis by one position and keep on doing as per the input once you reach destination you 
will get a quadrant and your exact location supose you are at (2,-4) position  now you 
know you have to move 2 position east and 4 position south to reach the destination  */


#include <bits/stdc++.h>
using namespace std;

int main()
{
    char direction[1000];
    cout << "Enter the direction in caps without space " << endl;
    cin.getline(direction, 1000);

    int x = 0;
    int y = 0;

    for (int i = 0; direction[i] != '\0'; i++)
    {

        switch (direction[i])
        {

        case 'E':
            x++;
            break;
        case 'W':
            x--;
            break;
        case 'N':
            y++;
            break;
        case 'S':
            y--;
            break;
        }
    }

    if (x >= 0 && y >= 0)
    {
        while (y--)
        {
            cout << "N"
                 << " ";
        }
        while (x--)
        {
            cout << "E"
                 << " ";
        }
    }

    else if (x <= 0 && y <= 0)
    {
        while (x++)
        {
            cout << "E"
                 << " ";
        }
        while (y++)
        {
            cout << "S"
                 << " ";
        }
    }

    else if (x <= 0 && y >= 0)
    {
        while (x++)
        {
            cout << "w"
                 << " ";
        }
        while (y--)
        {
            cout << "N ";
        }
    }
    else
    {
        while (x--)
        {
            cout << "E ";
        }
        while (y++)
        {
            cout << "S ";
        }
    }

    return 0;
}