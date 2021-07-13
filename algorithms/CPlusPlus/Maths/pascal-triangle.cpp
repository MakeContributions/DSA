// Example program
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    while(true)
    {
        cout << "Demonstrating Pascal's triangle (iterations upto power 10)" << endl;
        char choice;
        cout << "Do you wish to continue? (Y/y or N/n): ";
        cin >> choice;
        if(choice == 'Y' || choice == 'y')
        {
            cout << "Enter the desired number: ";
            int n;
            cin >> n;
            for(int i=0;i<10;i++)
            {
                for(int j=0;j<10;j++)
                {
                    cout << pow(n,i);
                    break;
                }
                cout << endl;
            }
            cout << endl;
        }
        else
        {
            break;
        }
    }
    return 0;

    //Expected time complexity: O(n^2);
    //Expected space complexity: O(1);
}
