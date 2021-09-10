
import java.util.Arrays;

public class cyclicSort {
    public static void main(String[] args)
    {
        int[] array1 = {4,5,2,3};
        int[] array2 = {2, 1, 5, 2, 9, 1, 2, 3, 3, 4, 4, 5, 6, 7, 8};

        Sort(array1);
        Sort(array2);


        System.out.println(Arrays.toString(array1));
        System.out.println(Arrays.toString(array2));
    }


    static void Sort(int[] array)
    {
        // step 1: loop from the beginning of the array to the second to last item
        for (int currentIndex = 0; currentIndex < array.length - 1; currentIndex++)
        {
            // step 2: save the value of the item at the currentIndex
            int item = array[currentIndex];
            // step 3: save a copy of the current index
            int currentIndexCopy = currentIndex;

            // step 4: loop through all indexes that proceed the currentIndex
            for (int i = currentIndex + 1; i < array.length; i++)
                if (array[i] < item)
                    currentIndexCopy++;

            // step 5: if currentIndexCopy has not changed, the item at the currentIndex is already in the correct position
            if (currentIndexCopy == currentIndex)
                continue;

            // step 6: skip duplicates
            while (item == array[currentIndexCopy])
                currentIndexCopy++;

            // step 7: swap
            int temp = array[currentIndexCopy];
            array[currentIndexCopy] = item;
            item = temp;

            // step 8: repeat steps 4, 6 and 7 above as long as we can find values to swap
            while (currentIndexCopy != currentIndex)
            {

                // step 9: save a copy of the currentIndex
                currentIndexCopy = currentIndex;

                // step 10: repeat step 4
                for (int i = currentIndex + 1; i < array.length; i++)
                    if (array[i] < item)
                        currentIndexCopy++;

                // step 10: repeat step 6
                while (item == array[currentIndexCopy])
                    currentIndexCopy++;

                // step 10: repeat step 7
                temp = array[currentIndexCopy];
                array[currentIndexCopy] = item;
                item = temp;
            }
        }
    }
}
