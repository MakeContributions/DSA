// Java implementation of recursive Binary Search 
class BinarySearch { 
    // Returns index of x if it is present in arr[l..r], 
    //  else return -1 
    int binarySearch(int arr[], int l, int r, int x) 
    { 
        if (r >= l) { 
            int mid = l + (r - l) / 2;  
            //We use (l + (r - l)) rather than using (l - r) to avoid arithmetic overflow. 
            //Arithmetic overflow is the situation when the value of a variable increases
            //beyond the maximum value of the memory location, and wraps around.
  
            // If the element is present at the 
            // middle itself 
            if (arr[mid] == x) 
                return mid; 
  
            // If element is smaller than mid, then 
            // it can only be present in left subarray 
            if (arr[mid] > x) 
                return binarySearch(arr, l, mid - 1, x); 
  
            // Else the element can only be present 
            // in right subarray 
            return binarySearch(arr, mid + 1, r, x); 
        } 
  
        // We reach here when element is not present 
        // in array 
        return -1; 
    } 
  
    // Driver method to test above 
    public static void main(String args[]) 
    { 
        BinarySearch ob = new BinarySearch(); 
        int arr[] = { 2, 3, 4, 10, 40 }; 
        int n = arr.length; 
        int x = 10; 
        int result = ob.binarySearch(arr, 0, n - 1, x); 
        if (result == -1) 
            System.out.println("Element not present"); 
        else
            System.out.println("Element found at index " + result); 
    } 
} 

// For running in terminal rename this file to BinarySearch.java
//then run the commands <javac BinarySearch.java> followed by <java BinarySearch>
//It will generate and a BinarySearch.class file which is a file containing java bytecode that is executed by JVM.
