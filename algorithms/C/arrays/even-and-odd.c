#include <stdio.h>
int main()
{
 int n;
 printf("Enter n : "); //n is number of elements in the array
 scanf("%d", &n); 
 int arr[n];
 for (int i = 0; i < n; i++)
 {
 scanf("%d", &arr[i]);
 }
 int arr_odd[n], arr_even[n]; //arr_odd[] for odd elements and arr_even[] for even elements
 int o = 0, e = 0;
 for (int i = 0; i < n; i++)
 {
 if (arr[i] % 2 != 0)
 {
 arr_odd[o] = arr[i]; //Putting odd numbers in arr_odd[] array.
 o++;
 }
 else if (arr[i] % 2 == 0)
 {
 arr_even[e] = arr[i]; //Putting even numbers in arr_even[] array.
 e++;
 }
 }
 
 printf("Even array : [ ");
 for (int i = 0; i < e; i++)
 {
 printf("%d ", arr_even[i]);
 }
 printf("]\nOdd array : [ ");
 for (int i = 0; i < o; i++)
 {
 printf("%d ", arr_odd[i]);
 }
 printf("]");
 return 0;
}
