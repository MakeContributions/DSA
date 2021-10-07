public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        int k = sc.nextInt();
        System.out.println(findTheKthBitInString(num, k));
    }

    private static char findTheKthBitInString(int num, int k) {
        if (num == 1) {
            return '0';
        }
        int length = (int) Math.pow(2, num);
        if (k < length / 2) {
            return findTheKthBitInString(num - 1, k);
        } else if (k == length / 2) {
            return '1';
        } else {
            return findTheKthBitInString(num - 1, length - k) == '0' ? '1' : '0';
        }
    }
}
