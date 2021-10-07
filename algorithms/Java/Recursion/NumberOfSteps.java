// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        System.out.println(numberOfStepsToZero(num));
    }

    private static int numberOfStepsToZero(int num) {
        if (num == 0) {
            return 0;
        }
        if (num % 2 == 0) {
            return 1 + numberOfStepsToZero(num / 2);
        }
        return 1 + numberOfStepsToZero(num - 1);
    }
}
