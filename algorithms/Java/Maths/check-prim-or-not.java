import java.util.*;

public class Main{
    public static void main(String[] args) {
    Scanner scn = new Scanner(System.in);
    int num = scn.nextInt();
    boolean ans = isPrime(num);
      if(ans =!  true) System.out.println("not prime");
      else System.out.println("prime");
    }
    
   
    public static boolean isPrime(int num){
        for(int i=2; i*i<num; i++){
            if(num %2 ==0){
                return false;
            }
        }
        return true;
    }
}
