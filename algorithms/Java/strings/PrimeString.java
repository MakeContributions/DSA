//PROBLEM STATEMENT:
//To check whether a string is prime string or not.

//A string is known as prime string if the absolute difference of summation of ascii values of 
//odd indexed letters and even indexed letters is divisible by odd prime integers less than 9, otherwise it
//is a Casual string.

//INPUT: a string
//OUTPUT: Entered string is Prime String or Casual String

//ALGORITHM:
//STEP 1: Start
//STEP 2:Initialize the variables with integer data type
//STEP 3:Declare variables with integral data type as 0
//STEP 4:Accept a string as an input from the user.
//STEP 5:Convert the string to its lower case in case the entered string is in upper case.
//STEP 6:Use of for loop where the loop iterates takes place till the value of i is less than the length of the string.
//STEP 7:Inside for loop, calculate the sum of ascii values of the characters at odd (int O) 
//       and even indexed position(int E) of the string separately.
//STEP 8:After the completion of for loop calculate the absolute difference of O and E.
//STEP 9:Use of if else control structure, to check whether the absolute difference is divisible by odd prime numbers 
//       less than 9, or not divisible.
//STEP 10:If the condition is true then statements inside if structure is executed that is: 
//        Output: Prime String
//        else
//        Output: Casual String
//STEP 11:END


package Hacktoberfest_MakeContributions_Solutions;
import java.io.*;
import java.util.*;
public class PrimeString 
{

	public static void main(String[] args)
	{
		
		
		       Scanner sc=new Scanner(System.in);
		        
		        int ch,ch1;
		        int O=0;
		        int E=0;
		        int diff,abs_diff;
		       
		         
		        String S=sc.next();
		        S=S.toLowerCase();
		        int len=S.length();
		       
			     for(int i=0;i<len;i++)
		        {
		           if((i+1)%2==0)
		           {
		            ch=S.charAt(i);
		            
		            E=E+ch;
		           
		           }
		            else
		            {
		               ch1=S.charAt(i);
		              
		               O=O+ch1;
		                
		            }
		        }
		        
		        abs_diff=Math.abs(O-E);
		        
		        if((abs_diff%3==0) || (abs_diff%5==0) || (abs_diff%7==0))
		        {
		           System.out.println("Prime String");
		        }
		        else
		        {
		            System.out.println("Casual String");
		        }
		      


		   }
		}
//************************************************************************************************************
//OUTPUT:
//Sample Test 1:
//abbde
//Prime String

//Sample Test 2:
//abcd
//Casual String

//*************************************************************************************************************

	