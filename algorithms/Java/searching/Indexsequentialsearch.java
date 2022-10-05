@@ -0,0 +1,57 @@
import java.util.*;
public class Indexsequential  {
    public static void main(String[] args) {
        int n,c;
        Scanner sc=new Scanner(System.in);
        n=sc.nextInt();
        int ar[]=new int[n];
        for(int i=0;i<ar.length;i++)
        ar[i]=sc.nextInt();
        c=sc.nextInt();
            indexsearch(ar,c);
    }
   public static void indexsearch(int[] ar,int s)
   {
    int l=(ar.length/3)+1,a=0;
            int arr[]=new int[l];
            for(int i=0;i<ar.length;i+=3)
            {
                arr[a++]=i;
            }
            int j=0,f=0;;
            while(j<l)
            {
                if(ar[arr[j]]==s)
                {
                    f=1;
                    break;
                }
                else if(ar[arr[j]]<s)
                {
                j++;
                if(j==l) 
                for(int i=arr[j-1];i<ar.length;i++)
                {
                    if(ar[i]==s)
                    {f=1;
                    j++;
                    break;
                    }
                }
            }
            else
            for(int i=arr[j-1];i<ar.length;i++)
                {
                    if(ar[i]==s)
                    {f=1;
                    j++;
                    break;
                    }
                }
            }
            if(f==1)
            System.out.println("Element found.");
            else 
            System.out.println("Element not found. ");
        }
    }
