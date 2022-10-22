//code that convert all the lowercase character in the string to uppercase.

import java.util.*;
public class Lowercasetouppercase {
    public static String ans(String s){
        String a="";
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)>=97){
                int w = s.charAt(i)-32;
             a=a+(char)w;
            }else{
                a=a+s.charAt(i);
            }
           
        }
        return a;
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String w = in.nextLine();
        System.out.println("ans="+ ans(w));
    }
}
