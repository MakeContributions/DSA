//Linear search to check for a given key in an array

public class MyLinearSearch{    
public static int linearSearch(int[] arr, int key){    
        for(int i=0;i<arr.length;i++){    
            if(arr[i] == key){    
                return i;    
            }    
        }    
        return -1;    
    }    
    public static void main(String args[]){    
        int[] arr1= {10,20,30,50,70,90};    
        int key = 30;    
        System.out.println(key+" is present and is found at index: "+linearSearch(arr1, key));    
    }    
}  

// For running in terminal rename this file to MyLinearSearch.java
//then run the commands <javac MyLinearSearch.java> followed by <java MyLinearSearch>
//It will generate and a MyLinearSearch.class file which is a file containing java bytecode that is executed by JVM.
