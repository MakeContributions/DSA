import java.util.Scanner;

public class ElectricityBill {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter amount of Electricity consumed in units ");
        int units = in.nextInt();
        int bill, count = units/100;
        if (units < 100) {
            bill = units * 10;
        } else if (units < 200) {
            bill = 100 * 15 + (units - 100) * 10;
        } else if (units < 300) {
            bill = 100 * 20 + 100 * 15 + (units - 200) * 10;
        } else {
            bill = 100 * 25 + 100 * 15 + (units - (count * 100)) * 10;
        }
        System.out.println("Electricity bill is " + bill);
    }
}

//        Electricity Bill using Conditionals
//        1 to 100 units – Rs. 10/unit
//        100 to 200 units – Rs. 15/unit
//        200 to 300 units – Rs. 20/unit
//        above 300 units – Rs. 25/unit
