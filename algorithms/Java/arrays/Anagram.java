@@ -0,0 +1,35 @@
import java.util.*;
public class Anagram {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        String s=sc.nextLine();
        String r=sc.nextLine();
        char ch[]=s.toCharArray();
        char dh[]=r.toCharArray();
        int d=ch.length;
        int e=dh.length;
        int c=0;
        int dat[]=new int[26];
        for(int i=0;i<ch.length;i++)
        dat[i]=0;
        int i=0;
        if(d!=e)
        System.out.println("Not anagram");
        else
        {
            while(d-->0)
        {
            dat[ch[i]-97]++;
            dat[dh[i]-97]--;
            i++;
        }
    }
        for(int j=0;j<26;j++)
        if(dat[j]>0)
        c++;
        if(c==0)
        System.out.println("Anagram");

        }
    }
    
