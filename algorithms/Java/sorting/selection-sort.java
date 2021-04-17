class Selection
{

    int minIndex(int Array[] , int start, int end)
    {
        int minIndex = start;

        for (int i = start+1; i < end; i++) 
        {
            if ( Array[i] < Array[minIndex] ) 
            {
                minIndex = i;    
            }    
        }
        return minIndex;
    }
     int[] sorting(int Array[],int length)
    {
        for (int i = 0; i < length-1; i++) 
        {
                int minI = minIndex(Array, i, length);
                int temp = Array[minI];
                Array[minI] = Array[i];
                Array[i] = temp;
            }
        return Array;
    }
}

/**
 * SelectionSort
 */
public class SelectionSort {

    public static void main(String[] args) {
        
        int Array[] = {1,2,3,4,5,6,7,8,9};

        Selection s1 = new Selection();
        long startTime = System.nanoTime();
        int sortedArray[] = s1.sorting(Array, 9);
        long endTime = System.nanoTime();

        for (int i = 0; i < 9; i++) {
            System.out.println(sortedArray[i]);
        }
        System.out.println("Total Time in Neno Second: "+ (endTime-startTime));

    }
}
