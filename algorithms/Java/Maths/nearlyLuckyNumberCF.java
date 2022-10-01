import java.util.*;
public class nearlyLuckyNumberCF {
    public static void main(String args[]){
        Scanner in = new Scanner(System.in);
        long n = in.nextLong();
        int count = 0;
        while(n > 0){
            if(n % 10 == 4 || n % 10 == 7){
            count++;
            }
            n = n/10;
        }
        if(count == 7 || count == 4)
        System.out.print("YES");
        else
        System.out.print("NO");
    }
}
