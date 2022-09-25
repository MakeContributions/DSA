/** 
    problem statement:
    Given two strings- str1 and str2, check both are isomorphic or not
    Isomorphic strings: Two strings are called isomorphic,
    if there is a one to one mapping possible for every character of str1 to every character of str2 while preserving the order. 
 */

 /***
    Example 1 => Input: str1="aab", str2="xxy"
                 Output: 1
    Example 2 => Input: str1="aab", str2="xyz"
                 Output: 0
  */
/** 
 * 
 * Time Complexity: O(N)
  Space Complexity: O(1)
*/
  
  import java.util.Arrays;
import java.util.Scanner;
  public class isomorphic_strings{
    public static void main(String[] args){
        Scanner input=new Scanner(System.in);
        String str1=input.next();
        String str2=input.next();
        if(strings_are_isomorphic(str1,str2)){
            System.out.println("1");
        }else{
            System.out.println("0");
        }
    }
    public static boolean strings_are_isomorphic(String s1,String s2){
        int n=s1.length();
        int m=s2.length();
        //check length of both strings
        if(n!=m){
            return false;
        }
        // array, make for mark visited characters of s2.
        boolean visited[]=new boolean[256];
        //array, store mapping of every character from s1 to s2
        int map[]=new int[256];
        Arrays.fill(map,-1);
        for (int i=0;i<n;i++)
        {
            char c1=s1.charAt(i);
            char c2=s2.charAt(i);
            if(map[c1]==-1){
                if(visited[c2]==true){
                    return false;
                }
                visited[c2]=true;
                map[c1]=c2;
            }else if(map[c1]!=c2){
                return false;
            }
        }
        return true;
    }
  }