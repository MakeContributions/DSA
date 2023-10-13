
import java.util.Scanner;
//uncomment to see steps working....
public class InsertionSort {

    public void InsSort(int arr []) {
        int temp;

        for(int i=1;i<arr.length;i++){
            /*System.out.println("\nPass "+(i)+" gives us -> ");
            System.out.print("\nCurrent ->"+arr[i]);
            System.out.print("\nPrevious ->"+arr[i-1]);*/
            if(arr[i]<arr[i-1]){
                for(int j=1;j>0;j++){
                    if(j>i){break;}
                    //System.out.print("\nExchange -> Yes");
                    while (arr[i-j+1]<arr[i-j]){
                        temp=arr[i-j];
                        arr[i-j]=arr[i-j+1];
                        arr[i-j+1]=temp;
                        /*if(j>i-1){break;}                                 //done to eliminate error on line 24 for (i-j-1)=(-1)
                        System.out.print("\nUpdated Current ->"+arr[i-j]);
                        System.out.print("\nUpdated Previous ->"+arr[i-j-1]);*/
                    }
                }
            }else{//System.out.print("\nExchange -> No");
            }
            /*System.out.println("\n");
            for(int k=0;k<arr.length;k++){
                System.out.print(arr[k]+" ");
            }
            System.out.print("\n");*/
        }
    }
    public void Printarray(int arr []) {                                         //Function to print array
        for(int j=0;j<arr.length;j++){
            System.out.print(arr[j]+" ");
        }
    }

    public static void main(String[] args) {
        int len;
        
        InsertionSort obj = new InsertionSort();
        Scanner scan = new Scanner(System.in);
        System.out.print("No. of elements in array -> ");
        len = scan.nextInt();
        int array[] = new int[len];
        for(int i=0;i<len;i++){
            array[i]=scan.nextInt();
        }
        scan.close();
        System.out.print("\nHence, we have the input array as -> [ ");
        obj.Printarray(array);System.out.print("]");
        obj.InsSort(array);
        System.out.print("\nHence, Sorted array using Insertion sort is -> [ ");
        obj.Printarray(array);System.out.print("]");
    }
}
