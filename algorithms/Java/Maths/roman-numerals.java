import java.util.HashMap;
/*

Description: To convert an integer to its Roman numeral equivalent and vice versa.

*/
public class RomanNumeralConverter {

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

            // check if the right number is greater than the left number in the given string
            if (current < prev) {
                result -= current;
            } else {
                result += current;
            }
            prev = current;
        }
        return result;
    }

    public String intToRoman(int num) {
        // Create a hashmap to store the 7 basic roman numerals and the special cases of subtraction
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

        int[] arr = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        int len = arr.length;

        StringBuilder result = new StringBuilder();
        while(num > 0){
            int i;
            for(i = 0; i < len; i++) {
                if (arr[i] <= num) break;
            }
            result.append(map.get(arr[i]));
            num = num - arr[i];
        }
        return result.toString();
    }

    public static void main(String[] args) {
        RomanNumeralConverter converter = new RomanNumeralConverter();
        // Roman to Integer
        System.out.println("DCXXI = " + converter.romanToInt("DCXXI"));
        System.out.println("MMMMDCCCLXXXVIII = " + converter.romanToInt("MMMMDCCCLXXXVIII"));
        System.out.println("II = " + converter.romanToInt("II"));
        System.out.println("CCXCIV = " + converter.romanToInt("CCXCIV"));
        System.out.println("IX = " + converter.romanToInt("IX"));
        System.out.println("XXXI = " + converter.romanToInt("XXXI"));
        System.out.println("CMXLI = " + converter.romanToInt("CMXLI"));
        System.out.println("MCCXXVI = " + converter.romanToInt("MCCXXVI"));
        System.out.println("CXLVIII = " + converter.romanToInt("CXLVIII"));

        System.out.println("<------------------------------------------------->");

        // Integer to Roman
        System.out.println(621 + " = " + converter.intToRoman(621));
        System.out.println(4888 + " = " + converter.intToRoman(4888));
        System.out.println(2 + " = " + converter.intToRoman(2));
        System.out.println(294 + " = " + converter.intToRoman(294));
        System.out.println(9 + " = " + converter.intToRoman(9));
        System.out.println(31 + " = " + converter.intToRoman(31));
        System.out.println(941 + " = " + converter.intToRoman(941));
        System.out.println(1226 + " = " + converter.intToRoman(1226));
        System.out.println(148 + " = " + converter.intToRoman(148));
    }
}
