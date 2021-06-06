// Calculating Factorial Using Big Integer
// https://www.hackerearth.com/practice/notes/factorial-of-large-number/
import java.math.BigInteger;
import java.util.*;
import java.io.*;
import java.lang.*;

class FactorialUsingBigInteger
{
    //Main Method
    public static void main(String[] args) throws IOException
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of times you want to calculate Factorial:");
        int t = sc.nextInt();
        HashMap<Integer,BigInteger> hashmap = new HashMap<>();
        int maxKey = -1;
        for(int i=0;i<t;i++){
            System.out.println("Enter the value of N:");
            int N = sc.nextInt();
            if(N>=0)
            {
                BigInteger f = new BigInteger("1"); // Or BigInteger assigned to ONE
                // Multiply f with number till N
                int initial = 2;
		//Checking if inputted number exists in map or not
                if (hashmap.containsKey(N)){
                    f = hashmap.get(N);
                } else {
		    // For a given number, Checking whether any sub factorial has some element present in hashmap
                    if (maxKey!=-1){
                        initial = maxKey;
                    }
                    for (int j = initial; j <= N; j++) {
                        if (hashmap.containsKey(j)) {
                            f = f.multiply(hashmap.get(j));
                        } else {
                            f = f.multiply(BigInteger.valueOf(j));
                            maxKey = j;
                            hashmap.put(j, f);
                        }
                    }
                }
                System.out.println("Factorial of given number is :"+f);
            }else{
                System.out.println("Number Should be greater than 0");
            }
        }
    }
} 
/*
Time Complexity:O(t*N)
Space Complexity:O(1)
Input:
Enter the number of times you want to calculate Factorial:
3
Enter the value of N:
20   //O(N) ==>20*19*18.....*1
Enter the value of N:
80  // O(N) ==>80*79*78.....*21*hashmap[20]
Enter the value of N:
10  // O(1) ==>hashmap[10]
Output:
Factorial of given number is : 2432902008176640000
Factorial of given number is : 71569457046263802294811533723186532165584657342365752577109445058227039255480148842668944867280814080000000000000000000
Factorial of given number is : 3628800
*/