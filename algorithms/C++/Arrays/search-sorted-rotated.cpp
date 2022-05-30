//Description : Searching element in a sorted-rotated array using binary search
#include<bits/stdc++.h>
using namespace std;
int search_array(vector <int> arr, int item) {
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high-low)/2;                            //Calculating middle index
        if (arr[mid] == item) {                                 //If the element at middle index is equal to the item then we return the middle index
            return mid;
        } 
        else if (arr[mid] > arr[low]) {                         //Here we check whether left half of the array is sorted or not .
            if ((arr[low] <= item) && (item<arr[mid])) {        // If left half is sorted then we check whether item is greater than the lower index 
                high = mid - 1;                                 //If  item is greater than the lower index then we ignore the right half of the array
            }                     
            else {                                             //If item is less than the lower index then we ignore the left half and start our search
                low = mid + 1;                                 //in the right half of the array
            }
        } 
        else {                                                 //This execute if right half is sorted
            if ((arr[high] >= item) && (item>arr[mid])) {      //We check whether our item is smaller or equal to the upper index 
                low = mid + 1;                                 //If yes, then we start our search within the range (mid+1,high)
            } 
            else {
                high = mid - 1;                                //If item is greater than the element at higher index then we start
            }                                                  //our search in the range(low,mid-1)
        }
    }
    return -1;
}
int main() {
    int t ;
    int n;                       
    int item;
    vector <int> arr;
    cin >> t;                                                 //Size of the array
    while (t--) {
        cin >> n;
        arr.push_back(n);
    }
    cin >> item;
    int found = search_array(arr, item);
    cout << found << endl;
    return 0;
    //Time Complexity : O(log t)
    //Ex:  t=5, arr=[10,20,30,40,50,8,9], item=30
    //found = 2
}
