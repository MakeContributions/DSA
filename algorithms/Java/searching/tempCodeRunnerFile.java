import java.util.Scanner;

class Solution {
    public static boolean searchMatrix(int matrix[][], int target) {
            
            int m = matrix.length;
            int n = matrix[0].length;
            
            if(target<matrix[0][0] || target>matrix[m-1][n-1])
                return false;
            
            int low = 0;
            int high = m * n;
            
            while(low<=high){
                
                int mid = (low+high)/2;
                
                if(matrix[mid/n][mid%n] == target)
                    return true;
                
                if(matrix[mid/n][mid%n] < target) low = mid+1;
                else high = mid-1;
            }
            
            return false;
        }

    public static void main(String args[]){

        int m,n;
        System.out.println("Enter the number of rows and the number of columns : ");
        try (Scanner sc = new Scanner(System.in)) {
            m = sc.nextInt();
            n = sc.nextInt();

            int arr[][] = new int[m][n];

            System.out.println("Enter the array elements : ");

            for(int i=0 ; i<m ; ++i){
                for(int j=0 ; j<n ; ++j){
                    arr[i][j] = sc.nextInt();
                }
            }

            System.out.println("Enter the target element : ");

            int target = sc.nextInt();

            if(searchMatrix(arr,target))
                System.out.println("Element present in matrix.");
            else
                System.out.println("Element not present in matrix.");
        }
    }

    }