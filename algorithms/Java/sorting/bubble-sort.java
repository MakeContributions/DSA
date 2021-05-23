import  java.util.Scanner;
public class sorting {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        boolean sorted = true; 

        System.out.println("Enter the size of array: ");
        int n=sc.nextInt();

        int a[]=new int[n];

        System.out.println("Enter the elements of array : "); 
        for (int i=0;i<n;i++)
        {
            a[i]=sc.nextInt();
        }

        for (int i=0;i<n-1;i++)
        {
            for(int j = 0; j < n - 1 - i; j++)
            {
                if(a[j+1]<a[j])
                {
                    int temp=a[j+1];
                    a[j+1]=a[j];
                    a[j]=temp;
                    sorted =false;
                }
            }
            if(sorted)break;
        }

        System.out.println("Array after sorting :");
        for (int item:a)
        {
            System.out.print(item+" ");
        }
    }
}
