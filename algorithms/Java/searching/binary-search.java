// Algorithm BinarySearch Iterative method
/*binarySearch(arr, x, low, high)
        repeat till low = high
               mid = (low + high)/2
                   if (x == arr[mid])
                   return mid
   
                   else if (x > arr[mid]) // x is on the right side
                       low = mid + 1
   
                   else                  // x is on the left side
                       high = mid - 1
 */
// Time Complexity : O(log(n)) 

public class BinarySearch {

    static int binarySearch(int arr[], int key) 
    {
        int start = 0;
        int end = arr.length - 1;
        
        while (start <= end) {
            // We use (start + (end - start)/2) rather than using (start + end)/2 to avoid
            // arithmetic overflow.
            // Arithmetic overflow is the situation when the value of a variable increases
            // beyond the maximum value of the memory location, and wraps around.
            int mid = start + (end - start) / 2; // optimised way

            if (arr[mid] == key)// key element is found at the middle of the array
                return mid;

            else if (arr[mid] < key) {// so the key lies in the right hand side of array
                start = mid + 1;
            }

            else {// so the key lies in the left subarray
                end = mid - 1;
            }
        }
        // we reach here when the key element is not present
        return -1;
    }

    public static void main(String[] args) 
    {

        int arr[] = { 1, 3, 4, 5, 6 };

        /*
         * List<ArrayList<Integer>> arr = new ArrayList<>();
         * arr.add(new ArrayList<Integer>(Arrays.asList( 1, 3, 4, 5, 6 )));
         */
        int key = 4; // element to search
        int index = binarySearch(arr, key);
        if (index == -1) {
            System.out.println("key element not found");
        }
        else {
            System.out.println("key element found at index :" + index);
        }

    }
}
