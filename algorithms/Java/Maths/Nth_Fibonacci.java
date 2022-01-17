import java.io.*;
import java.util.*;
import java.math.*;

/**
 * Problem : Find the n-th fibonacci number. Let's call it F(n).
 *           As we know F(n) grows exponentially. So, we need to find 
 *           the F(n) % mod, where mod is [10^9 + 7]. 
 * 
 * Constraints : 0 <= n <= 10^19
 * 
 * ---------------------------------------------------------------------------
 * 
 * Solution : nth-Fibonacci is nothing but a sum of previous two fibonacci numbers
 * 
 * i.e. F(0) = 0, if n == 0;
 *      F(1) = 1, if n == 1;
 *      F(n) = F(n-1) + F(n-2) , For all n>1;
 * 
 * Let's take n = 5 for dry run purpose and analyse the time complexity.
 * 
 * Approach 1: Just iteratively calculate using loop.
 *             
 *              fprev_2 = 0;
 *              fprev_1 = 1;
 * 
 *              if n is equal to 0, then return fprev_2
 *              if n is equal to 1, then return fprev_1            
 * 
 * 
 *              if both above conditions fail, then
 *              
 *              while n greater than 1:
 *                 fcur = fprev_2 + f_prev1
 *                 fprev_2 = fprev_1
 *                 fprev_1 = fcur
 *                 n = n-1
 * 
 *              return fprev1;
 *
 * As expected time complexity of this approach is O(n), 
 * which simply gives TLE(Time Limit Exceeded) for the above constraints.
 * So we need something faster.
 * ......................................................................
 * 
 * Approach 2: Use Matrix Exponentiation, this idea comes from 
 *             binary exponentiation and associativity property 
 *             of matrix multiplication.
 * 
 * Let's understand ASSOCIATIVITY:
 * 
 *             A * (B * C) = (A * B) * C 
 *  
 * where A, B, C are operands of some data type, 
 * it simply indicates final result is independent of order of operations.
 * 
 * BINARY EXPONENTIATION:
 *       
 *       
 *       pow(base, exponenent):
 *          result = 1
 *          while  exponent greater than 0:
 *             if exponent is odd: result = result * base
 *             base = base * base
 *             exponent = exponent / 2
 *             
 *          return result
 *          
 * what it does is that it calculates the power using log(exponent) operations only 
 * because each time exponent becomes half. Time complexity - O(log(exponent))
 * which is must faster than O(exponent).
 * 
 * Now apply this idea,
 * 
 * we know that F(n) = F(n-1) + F(n-2)
 *              
 *            F(n-1) = 0 * F(n-2) + 1 * F(n-1)
 *            F(n) = 1 * F(n-1) + 1 * F(n-2)
 *          
 * 
 *            [[F(n-1)], [F(n)]] = [[0 1],[1 1]] * [[F(n-1)], [F(n-2)]]
 *            [[F(n-1)], [F(n)]] = { [[0 1],[1 1]] } ^ 2 * [[F(n-2)], [F(n-3)]]
 *                           .
 *                           .
 *                           .
 *                           .
 *            [[F(n-1)], [F(n)]] = { [[0 1],[1 1]] } ^ (n-1) * [[F(1)], [F(0)]]
 *            
 * Thus we can calculate the F(n) using time complexity O(8 * log(n)) the constant
 * 8 comes because of matrix multiplication of two 2x2 matrices.     
 * 
 * Below is the implementation in JAVA.
 * 
 * First few terms of fibonacci sequence
 * 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89...
 * 
 * */


public class Nth_Fibonacci {
    
  static class Matrix {
         /*data member*/  
         public long[][] matrix;
         
	  
	 /*Constructor*/
         public Matrix(int n) {
		matrix=new long[n][n];			
	 }
		   
      /**
       *  @param other Matrix 
       *  @param mod
       * 
       * this method performs matrix multiplication of this.matrix 
       * and other.matrix and returns the product matrix
       * */
	public Matrix multiply(Matrix other,int mod) {

	       Matrix product = new Matrix(matrix.length);

	       for (int i = 0; i < matrix.length; i++) {
		    for (int j = 0; j < matrix.length; j++) {
		         for (int k = 0; k < matrix.length; k++) {
			     product.matrix[i][k] = (product.matrix[i][k] + matrix[i][j] * other.matrix[j][k])%mod;
			 }
		    }
	        }

	        return product;
	 }
	  
      }

      /*binary exponentiation using matrices*/
      public static Matrix exponentiation(Matrix m,BigInteger n,int mod) {

	    Matrix expo = new Matrix(m.matrix.length);

	    for (int i = 0; i < m.matrix.length; i++) expo.matrix[i][i]=1;

	    while(n.compareTo(BigInteger.valueOf(0))>0) {

		    if(n.remainder(BigInteger.valueOf(2)).compareTo(BigInteger.valueOf(1)) == 0) expo = expo.multiply(m,mod);

		    m = m.multiply(m,mod);

		    n = n.divide(BigInteger.valueOf(2));
	    }

	    return expo;
     }

     public static void main(String []args) throws IOException {
    
           /*for taking input.*/
	   BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
           /*because of constraints ,I read the number in string since it does not fit in long as well.*/
	   String s = br.readLine().trim();
    
           /*convert the string to bigInteger to be able to perform some arithmetic operations*/
	   BigInteger n = new BigInteger(s);

		
           int mod = (int)1e9+7;

	   Matrix A = new Matrix(2);
           A.matrix[0][0] = 0;
           A.matrix[0][1] = A.matrix[1][0] = A.matrix[1][1] = 1;
    
           Matrix ans = exponentiation(A,n,mod);

           int result = (int)(ans.matrix[0][1] % mod) ;
    
           System.out.println(n + "-th Fibonacci number is : " + result);
   }
	
}
