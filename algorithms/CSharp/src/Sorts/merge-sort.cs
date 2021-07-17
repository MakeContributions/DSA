using System;

using namespace Algorithm.Sorts
{
    public class MergeSort
    {
        public static void Main()
        {
            int[] arr = { 800, 11, 50, 771, 649, 770, 240, 9 };
            Sort(arr);
            var result = string.Join(" ", arr);
            Console.WriteLine(result);
        }

        public bool sorted = false;

        public static void Sort(int[] theArray)
        {
            int p = 0;
            int q;
            int r = theArray.Length - 1;

            if (theArray.Length % 2 == 0)
            {
                q = theArray.Length / 2;
            }
            else
            {
                q = (theArray.Length / 2) + 1;
            }

            while (!sorted)
            { 
                mergeSort(theArray, p, r);
                //Check Sorting
                sorted = isSorted();
            }
        }

        public void mergeSort(int[] theArray, int start, int right)
        {
            if (start < right)
            {
                int mid = (start + right) / 2;

                mergeSort(theArray, start, mid);
                mergeSort(theArray, mid + 1, right);

                merge(arr, theArray, start, mid, right);
            }
        }

        public void merge(int[] arr, int[] theArray, int p, int q, int r)
        {
            //Create L Array[p...q]
            int n1 = q - p + 1;
            int[] LArr = new int[n1];
            //Create R Array[q+1..r]
            int n2 = r - q;
            int[] RArr = new int[n2];

            //int i -> Pointer for LArr
            //int j -> Pointer for RArr
            //int k -> Pointer for theArr
            int i, j, k;

            //Populate SubArrays
            for (i = 0; i < n1; i++)
            {
                LArr[i] = theArray[p + i];
            }
            for (j = 0; j < n2; j++)
            {
                RArr[j] = theArray[q + 1 + j]; //Access elements at J position from Q+1
            }

            i = 0;
            j = 0;
            k = p;

            sortArray(i, k, j, n1, n2, LArr, RArr,theArray);
        }

        private void sortArray(int i, int k, int j, int n1, int n2, int[] LArr, int[] RArr,int[] theArray)
        {

            while (i < n1 && j < n2)
            {
                if (LArr[i] <= RArr[j])
                {
                    theArray[k] = LArr[i];
                    i++;
                }
                else
                {
                    theArray[k] = RArr[j];
                    j++;
                }
                k++;
            }

            while (i < n1)
            {
                theArray[k] = LArr[i];
                i++;
                k++;

            }

            while (j < n2)
            {
                theArray[k] = RArr[j];
                j++;
                k++;
            }

        }

        private bool isSorted(int[] theArray)
        {
            for (int i = 0; i < theArray.Length - 1; i++)
            {
                if (theArray[i] > theArray[i + 1]) return false;
            }

            return true;
        }
    }