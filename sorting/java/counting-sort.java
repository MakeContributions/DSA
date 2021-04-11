public class CountingSort {

    /**
     * Public method to use the counting sort algorithm
     * @param arr - the array in input
     */
    public void sort(int[] arr){

        int[] sortedArray = new int[arr.length + 1];

        // Search max element
        int max = arr[0];
        for(int i = 0; i < arr.length; i++){
            if(arr[i] > max){
                max = arr[i];
            }
        }

        // Create counting array
        int[] countArray = new int[max + 1];
        for(int i = 0; i < countArray.length; i++){
            countArray[i] = 0;
        }

        // Count elements in array
        for(int i = 0; i < arr.length; i++){
            countArray[arr[i]]++;
        }


        for(int i = 1; i < countArray.length; i++){
            countArray[i] += countArray[i - 1];
        }

        for (int i = arr.length - 1; i >= 0; i--) {
            sortedArray[countArray[arr[i]] - 1] = arr[i];
            countArray[arr[i]]--;
        }

        System.arraycopy(sortedArray, 0, arr, 0, arr.length);
    }

    /**
     * Main method for testing
     * @param args
     */
    public static void main(String[] args) throws Exception {
        CountingSort count = new CountingSort();

        int[] test = {1,9,8,7,6,5,4,3,2,12,546,23,123,5768,689,45,6342,0,76,856,34,412,12,32,353,46,568,456,234,3456,467,345345,345,345,};

        count.sort(test);

        for(int i = 1; i < test.length; i++){
            if(test[i] < test[i - 1]){
                throw new Exception("[ERROR] Ops! Counting sort not work!");
            }
        }

        printArray(test);
    }

    /**
     * Print an array
     * @param arr
     */
    public static void printArray(int[] arr){

        System.out.println("Sorted array: ");
        for(int i = 0; i < arr.length; i++){
           System.out.println(" " + i);
        }
    }
}
