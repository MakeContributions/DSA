public class Sumqueries {
    static int tree[];
    public static void init(int n){
        tree=new int [4*n];

    }

    public static int buildst(int arr[], int i, int start, int end){

        if(start==end){
          return  tree[i]=arr[start];

        }

        int mid=(start+end)/2;
        buildst(arr,2*i+1,start,mid);
        buildst(arr,2*i+2,mid+1,end);
        tree[i]=tree[2*i+1]+tree[2*i+2];
        return tree[i];
    }

    public static void main(String args[]){
        int arr[]={1,2,3,4,5,6,7,8};
        int n=arr.length;
        init(n);
        buildst(arr,0,0,n-1);
        for(int i=0;i< tree.length;i++){
            System.out.print(tree[i]+" ");
        }


    }
}
