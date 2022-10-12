public class Solution {
    public static int binary(int[] array, int target) {
        if(array.length==0) {
            return -1;
        }
        int start = 0;
        int end = array.length - 1;
        while(start<=end) {
            int middle = start + ((end-start)/2); // this is equal to (start + end) /2
            if(array[middle]>target) {
                end = middle - 1;
            }
            else if(array[middle]<target) {
                start = middle + 1;
            }
            else
                return middle;
        }
        return -1;
    }
    public static void main(String args[]){    
        int[] arr1= {10,20,30,50,70,90};    
        int key = 30;    
        int ans = reachNumber(30);
        System.out.println(ans); 
    }   
}
