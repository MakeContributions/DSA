import java.util.*;
public class Duplicate_element {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the size of array");
        int n=sc.nextInt();
        System.out.println("Enter the array elements");
        int[] a=new int[n];
        for (int i = 0; i <n ; i++)
            a[i]=sc.nextInt();
        System.out.println(findDuplicates(a));


    }
        static List<Integer> findDuplicates(int[] arr) {
            int i=0;
            while(i<arr.length)
            {
                int correct=arr[i]-1;
                if(arr[i]!=arr[correct])
                    swap(arr,i,correct);
                else
                    i++;
            }
            List<Integer> ans=new ArrayList<>();
            for(int index=0;index<arr.length;index++)
            {
                if(arr[index]!=index+1)
                    ans.add(arr[index]);
            }
            return ans;


        }
        static void swap(int[] arr,int s,int e)
        {
            int temp=arr[s];
            arr[s]=arr[e];
            arr[e]=temp;
        }
    }

