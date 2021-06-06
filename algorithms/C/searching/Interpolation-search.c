/*
Program to search data in array using interpolation search
Interpolation search: Used to search data in a sequence stored array
*/

#include <stdio.h>

#include <stdlib.h>
 // Function to search data in a given array
int interpolation_search(int * arr, int low, int high, int to_search) {
  if (low <= high && to_search >= arr[low]) {
        if(arr[high]==arr[low]&&to_search==arr[high]&&arr[low]==to_search)
        return high;
    // formula to find index
    int pos = low + (to_search - arr[low]) * (high - low) / (arr[high] - arr[low]);

    // if data found
    if (arr[pos] == to_search)
      return pos;
    // if data is less than current position
    else if (arr[pos] > to_search)
      high = pos - 1;
    // if data is greater than the current position
    else if (arr[pos] < to_search)
      low = pos + 1;
    // recursive call
    return interpolation_search(arr, low, high, to_search);
  }
  // return -1 if the if condition fails
  return -1;
}
//driver code
int main() {
  int * arr, size, index, to_search, i;

  printf("Enter the size: ");
  // taking size
  scanf("%d", & size);
  // dynamically locating memory
  arr = (int * ) malloc(sizeof(int) * size);
    if(arr==NULL)
    {
        printf("Memory not allocated Please try again");
        exit(0);
    }
  for (i = 0; i < size; i++) {
    scanf("%d", & arr[i]);
  }
  printf("Enter the number to search: ");
  // taking the number to search
  scanf("%d", & to_search);
  // calling interpolation search
  index = interpolation_search(arr, 0, size - 1, to_search);
  // If element was found
  if (index != -1)
    printf("Element found at index number: %d", index);
  // If element was not found
  else
    printf("Element not found");

  return 0;
}
/*
Input: Enter the size: 5
10 20 30 40 50
Enter the data to search: 40
Output: Element found at index number: 3

Time complexity: O(log2(log2 n))
Space Complexity: O(1)

*/
