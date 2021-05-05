//Statement
// 1. You are given a number n, representing the size of array a.
// 2. You are given n numbers, representing the elements of array a.
// 3. You are given a number k, representing the size of window.
// 4. You are required to find and print the maximum element in every window of size k.

// e.g.
// for the array [2 9 3 8 1 7 12 6 14 4 32 0 7 19 8 12 6] and k = 4, the answer is [9 9 8 12 12 14 14 32 32 32 32 19 19 19]

//solution
import java.io.*;
import java.util.*;

public class Main{
  

public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int n = Integer.parseInt(br.readLine());
    int[] arr = new int[n];
    for(int i = 0; i < n; i++){
       arr[i] = Integer.parseInt(br.readLine());
    }
    int k = Integer.parseInt(br.readLine());

    // code
	//nge is next Greater Element
    // nge begin 
    int[] nge = new int[arr.length];

    Stack<Integer> st = new Stack<>();
    st.push(arr.length - 1);
    nge[arr.length - 1] = arr.length;

    for(int i = arr.length - 2; i >= 0; i--){
      while(st.size() > 0 && arr[i] >= arr[st.peek()]){
        st.pop();
      }

      if(st.size() == 0){
        nge[i] = arr.length;
      } else {
        nge[i] = st.peek();
      }

      st.push(i);
    }

    // nge end

    int j = 0;
    for(int i = 0; i <= arr.length - k; i++){
      if(j < i){
        j = i;
      }

      while(nge[j] < i + k){
        j = nge[j];
      }
      System.out.println(arr[j]);
    }
 }
}
                        