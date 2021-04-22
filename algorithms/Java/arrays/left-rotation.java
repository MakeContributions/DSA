public class left_rotation{

    public static void rotateToLeft(int [] arr){
        if(arr == null || arr.length == 0){
            System.out.println("no rotation possible");
            return;
        }
        //take the first element
        int firstElement = arr[0];
        //move everything in the left
        for(int i = 0; i < arr.length -1; i++){
            arr[i] = arr[i + 1];
        }
        //the first element become the last element
        arr[arr.length - 1] = firstElement;
    }

    public static void print(int [] arr){
        System.out.print("[");
        for(int i = 0; i < arr.length; i++)
            System.out.print(arr[i] + ", ");
        System.out.println("]");
    }

    public static void main(String [] args){
        int [] arr = {1,2,3,4,5,6,7,8,9};
        int n = 3;  //number of times to rotate the array

        System.out.print("before: ");
        print(arr);

        System.out.println("rotating " + n + " times to left");
        for(int i = 0; i < n; i++)
            rotateToLeft(arr);  //move to left n times

        System.out.print("after: ");
        print(arr);
    }
}

/*
    to run the file:
        javac left_rotation.java
        java left_rotation
    
    result:
        before: [1, 2, 3, 4, 5, 6, 7, 8, 9, ]
        rotating 3 times to left
        after: [4, 5, 6, 7, 8, 9, 1, 2, 3, ]
        
*/