// Example program
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    while(true)
    {
        cout << "Demonstrating Pascal's triangle (iterations up to power n)" << endl;
        char choice;
        cout << "Do you wish to continue? (Y/y or N/n): ";
        cin >> choice;
        if(choice == 'Y' || choice == 'y')
        {
            cout << "Enter the desired number till which you want to continue: ";
            int n;
            cin >> n;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    cout << pow(11,i);
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
