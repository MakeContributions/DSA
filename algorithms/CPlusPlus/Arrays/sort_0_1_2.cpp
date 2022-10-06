#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// method to print the array
void printArray(vector<int> array)
{
    for (auto element : array)
    {
        cout << element << " ";
    }
}

/*
    Method to sort the array using only 3 variables and single traversal
    Also known as Dutch National Flag Algorithm.
*/
vector<int> sortArray(vector<int> array)
{
    int low = 0;
    int mid = 0;
    int high = array.size() - 1;

    //  Taking 4 ranges:
    //  1 to low will contain only 0s
    //  low to mid will contain only 1s
    //  mid to high will contain unknown elements
    //  high to size of array will contain 2s

    while (mid <= high)
    {
        // case 1: if the mid is pointing to 0, then swap the array values of low and high and
        // increment both low and mid
        if (array[mid] == 0)
        {
            swap(array[low], array[mid]);
            low++;
            mid++;
        }
        // case 2: if the mid is pointing to 1, then increrment only mid
        else if (array[mid] == 1)
        {
            mid++;
        }
        // case 3: if the mid is pointing to 2, then swap mid and high and then decrease high
        else
        {
            swap(array[mid], array[high]);
            high--;
        }
    }
    return array;
    // Time Complexity: O(n)
    // Space Complexity: O(1)
}

// main function
int main()
{
    vector<int> array;
    int totalInputs;
    cout << "Enter the number of inputs for the array: \n";
    cin >> totalInputs;
    cout << "Enter " << totalInputs << " elements in the array:\n";
    while (totalInputs--)
    {
        int inputElement;
        cin >> inputElement;
        array.push_back(inputElement);
    }
    vector<int> sortedArray = sortArray(array);
    cout << "Unsorted Array is: ";
    printArray(array);
    cout << "\nSorted array is: ";
    printArray(sortedArray);

    // Test case 1
    /*
    vector<int> array1 = {0, 1, 2, 2, 1, 1, 1};
    vector<int> sortedArray1 = sortArray(array1);
    cout << "Unsorted Array for test case 1: ";
    printArray(array1);
    cout << "\nSorted array for test case 1: ";
    printArray(sortedArray1);
    */

    // Test case 2
    /*
    vector<int> array2 = {0, 1, 0, 2, 1, 1, 1};
    vector<int> sortedArray2 = sortArray(array2);
    cout << "\nUnsorted Array for test case 2: ";
    printArray(array2);
    cout << "\nSorted array for test case 2: ";
    printArray(sortedArray2);
    */

    // Test case 3
    /*
    vector<int> array3 = {2, 1, 1, 0, 1, 2, 2, 1, 1, 1};
    vector<int> sortedArray3 = sortArray(array3);
    cout << "\nUnsorted Array for test case 3: ";
    printArray(array3);
    cout << "\nSorted array for test case 3: ";
    printArray(sortedArray3);
    */
    return 0;
}