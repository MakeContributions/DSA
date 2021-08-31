package CyclicSort;
import java.util.Arrays;

// when given nos. range from 1 - n then use cyclic sort..
public class CyclicSort {
    public static void main(String[] args) {
        int[] arr ={4,2,5,3,1};
        sort(arr);
        System.out.println(Arrays.toString(arr));
    }
    static void sort(int[] arr){
        int i =0;
        while(i<arr.length){
            int correctLoc = arr[i] - 1;// because array starting from 1 to n  that's why we -1 to make it 0 to n
            if(arr[i] != arr[correctLoc]){
                swap(arr,i,correctLoc);
            }
            else{
                i++;
            }
        }
    }

   static void swap(int[]arr,int first, int second) {
        int temp = arr[first];
       arr[first] = arr[second];
       arr[second] = temp;
    }
}
