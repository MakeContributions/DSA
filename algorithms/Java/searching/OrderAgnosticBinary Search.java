public class OrderAgnosticBS {
    public static void main(String[] args) {
        int[] arr={1,2,3,4,5,6,7,8,9};
        int target=7;
        int ans=orderAgnosticBS(arr,target);
        System.out.println(ans);
    }
    static int orderAgnosticBS(int[] arr,int target){
        int start=0;
        int end=arr.length-1;
        //find arr sorted in ascend or descend order
        boolean isAsc;// boolean isAsc = arr[start]<arr[send];
        if(arr[start]<arr[end]){
            isAsc=true;
        }
        else{
            isAsc=false;
        }
        while(start<=end){
            int mid=start+(end-start)/2;
            if(arr[mid]==target){
                return mid;
            }
            if(isAsc) {
                if(arr[mid]>target) {                  
                    end=mid-1;
                }
                else if(arr[mid]<target){
                    start=mid+1;
                }
            }
            else{
                if(arr[mid]<target) {
                    end=mid-1;
                }
                else if(arr[mid]>target){
                    start=mid+1;
                }
            }
        }
        return -1;
    }
}
