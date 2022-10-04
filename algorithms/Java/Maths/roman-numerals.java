import java.util.HashMap;

/**
 * Problem: To convert an integer to its Roman numeral equivalent and vice versa.
 * ----------------------------------------------------------------------------------------------------------------
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 *
 * ----------------------------------------------------------------------------------------------------------------
 *
 * Constraints:
 *      The input string should contain only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
 *      It is guaranteed that the input is a valid roman numeral in the range [1, 3999].
 *
 * ----------------------------------------------------------------------------------------------------------------
 *
 * Description:
 *      There are seven basic different symbols to represent roman numerals: I, V, X, L, C, D and M.
 *      Those being:
 *           Symbol       Value
 *           I             1
 *           V             5
 *           X             10
 *           L             50
 *           C             100
 *           D             500
 *           M             1000
 *
 *      Roman numerals are usually written from largest to smallest, from left to right.
 *      There are six instances where this rule does not apply and subtraction is used instead:
 *             I can be placed before V (5) and X (10) to make 4 (IV) and 9 (IX). (5 - 1 and 10 - 1, respectively)
 *             X can be placed before L (50) and C (100) to make 40 (XL) and 90 (XC). (50 - 10 and 100 - 10, respectively)
 *             C can be placed before D (500) and M (1000) to make 400 (CD) and 900 (CM). (500 - 100 and 1000 - 100, respectively)
 *
 * ----------------------------------------------------------------------------------------------------------------
 *
 * Examples:
 *      1) Input: s = "II"
 *         Output: 2
 *         Explanation: 2 = 1 + 1 = I + I.
 *
 *      2) Input: s = 31
 *         Output: "XXXI"
 *         Explanation: 31 = 30 + 1 = XXX + I.
 *
 *      3) Input: s = "CMXLI"
 *         Output: 941
 *         Explanation: 941 = 900 + 40 + 1 = CM + XL + I.
 *
**/

public class RomanNumeralConverter {

    /**
     * This method converts a roman numeral to its integer equivalent.
     * @param s The input roman numeral to be converted.
     * @return The integer equivalent of the roman numeral.
     */
    public int romanToInt(String s){
        int result = 0;
        int prev = 0;

        // for each character in the given string
        for (int i = s.length() - 1; i >= 0; i--) {
            // get the integer value of the character
            int current = switch (s.charAt(i)) {
                case 'I' -> 1;
                case 'V' -> 5;
                case 'X' -> 10;
                case 'L' -> 50;
                case 'C' -> 100;
                case 'D' -> 500;
                case 'M' -> 1000;
                default -> throw new IllegalArgumentException("Invalid roman number");
            };

            // check if the right number is greater than the left number (previous character) in the given string (case of subtraction)
            if (current < prev) {
                result -= current; // subtract the right number from the result
            } else {
                result += current;
            }
            prev = current; // update the previous number
        }
        return result;
    }

    /**
     * This method converts an integer to its roman numeral equivalent.
     * @param num The input integer to be converted.
     * @return The roman numeral equivalent of the integer.
     */
    public String intToRoman(int num) {
        // Create a hashmap to store the 7 basic roman numerals and the six special cases of subtraction
        HashMap<Integer, String> map = new HashMap<>();
        map.put(1,"I");
        map.put(4,"IV");
        map.put(5,"V");
        map.put(9,"IX");
        map.put(10,"X");
        map.put(40,"XL");
        map.put(50,"L");
        map.put(90,"XC");
        map.put(100,"C");
        map.put(400,"CD");
        map.put(500,"D");
        map.put(900,"CM");
        map.put(1000,"M");

        int[] arr = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}; // store the keys of the hashmap in an array
        int len = arr.length;

        StringBuilder result = new StringBuilder();
        while(num > 0){
            int i;
            // find the largest number in the array that is less than or equal to the given number
            for(i = 0; i < len; i++) {
                if (arr[i] <= num) break;
            }

            result.append(map.get(arr[i])); // append the equivalent roman numeral to the result
            num = num - arr[i]; // subtract the found key from the given number
        }
        return result.toString();
    }

    public static void main(String[] args) {
        RomanNumeralConverter converter = new RomanNumeralConverter();
        // Roman to Integer
        System.out.println("Roman to Integer Conversion Examples:");
        System.out.println("DCXXI = " + converter.romanToInt("DCXXI"));
        System.out.println("II = " + converter.romanToInt("II"));
        System.out.println("CCXCIV = " + converter.romanToInt("CCXCIV"));
        System.out.println("IX = " + converter.romanToInt("IX"));
        System.out.println("XXXI = " + converter.romanToInt("XXXI"));
        System.out.println("CMXLI = " + converter.romanToInt("CMXLI"));
        System.out.println("MCCXXVI = " + converter.romanToInt("MCCXXVI"));
        System.out.println("CXLVIII = " + converter.romanToInt("CXLVIII"));

        System.out.println("<------------------------------------------------------------------->");

        // Integer to Roman
        System.out.println("Integer to Roman Conversion Examples:");
        System.out.println(621 + " = " + converter.intToRoman(621));
        System.out.println(2 + " = " + converter.intToRoman(2));
        System.out.println(294 + " = " + converter.intToRoman(294));
        System.out.println(9 + " = " + converter.intToRoman(9));
        System.out.println(31 + " = " + converter.intToRoman(31));
        System.out.println(941 + " = " + converter.intToRoman(941));
        System.out.println(1226 + " = " + converter.intToRoman(1226));
        System.out.println(148 + " = " + converter.intToRoman(148));
    }
}
