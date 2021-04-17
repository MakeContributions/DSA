public class palindrome { 
  
    // Function that returns true if 
    // str is a palindrome 
    static boolean isPalindrome(String str) 
    { 
  
        // Pointers pointing to the beginning 
        // and the end of the string 
        int i = 0, j = str.length() - 1; 
  
        // While there are characters toc compare 
        while (i < j) { 
  
            // If there is a mismatch 
            if (str.charAt(i) != str.charAt(j)) 
                return false; 
  
            // Increment first pointer and 
            // decrement the other 
            i++; 
            j--; 
        } 
  
        // Given string is a palindrome 
        return true; 
    } 

    //new approach with case sensitive
    public static boolean isPalindrome(String str, boolean caseSensitive){
        // lowercase if not case sensitive
        if(!caseSensitive) str = str.toLowerCase();

        for(int i = 0; i < str.length() / 2; i++)
            if(str.charAt(i) != str.charAt(str.length() - 1 - i))
                return false;

        return true;
    }
  
    // Driver code 
    public static void main(String[] args) 
    { 
        String str = "Dad"; 
  
        if (isPalindrome(str)) 
            System.out.println("Yes"); 
        else
            System.out.println("No"); 
  
        if (isPalindrome(str, false)) 
            System.out.println("Yes"); 
        else
            System.out.println("No"); 
    } 
} 
