/***
 * Problem Statement:
 * Given an array arr[] of size N having distinct elements, the task is to find the next greater element for each element of the array in order of their appearance in the array.
 * Next greater element means nearest element on right side which is greater than current element, 
 * if there is no suxh element, then put -1 for that.
 *
 */


 /***
  * Example 1: Input: arr=[1,3,2,4] n=4
               Output: 3 4 4 -1
    
    Example 2: Input: arr=[6 8 0 1 3] n=5
               Output: 8 -1 1 3 -1
  */

  /***
   * Time Complexity: O(N)
   * Space Complexity: O(N)
   */
  import java.util.Scanner;
import java.util.Stack;
  
  public class Next_Greater_Element {
      public static void main(String[] args){
          Scanner input=new Scanner(System.in);
          int n=input.nextInt();
          long arr[]=new long[n];
          for (int i=0;i<n;i++){
              arr[i]=input.nextLong();
          }
          long ans[]=nextLargerElement(arr,n);  // functions that print array for calculating next greater element
          for (int i=0;i<ans.length;i++){
            System.out.print(ans[i]+" ")
          }
    }
      public static long[] nextLargerElement(long[] arr, int n)
      { 
          // Your code here

        /****
         * Approach: for element at index i,
         * there were two posiibilities that there is greater element than this
         * at right side of array or not.
         * if there is no greater element in right side is indicated by Empty stack
         * if there is greater ekement in right side is indicated by stack peek element.
         */


          long ans[]=new long[n];
          ans[n-1]=-1;
          Stack<Long> st=new Stack<>();
          st.push(arr[n-1]);
          for (int i=n-2;i>=0;i--)
          {
              if(st.isEmpty())
              {
                  st.push(arr[i]);
                  ans[i]=-1;
              }
              else
              {
                  while(st.isEmpty()==false && arr[i]>=st.peek())
                  {
                      st.pop();
                  }
                  if(st.size()==0){
                      ans[i]=-1;
                  }else{
                      ans[i]=st.peek();
                  }
                  st.push(arr[i]);
              }
          }
          return ans;
      } 
  }
  