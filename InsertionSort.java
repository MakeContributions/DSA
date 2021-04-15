
import java.util.Arrays;

public class InsertionSort {
	static int[] nums = { 12, 43, 2, 4, 1, 0, -23, -93 };

	public static void main(String[] args) {
		System.out.println("Before sorting " + Arrays.toString(nums));
		sort(nums);
	}

	public static void sort(int[] nums) {
		int i = 1;
		while (i < nums.length) {
			int temp, j;
			temp = nums[i];
			j = i;

			while (j > 0 && nums[j - 1] > temp) {
				nums[j] = nums[j - 1];
				j--;
			}
			nums[j] = temp;
			i++;
		}
		System.out.println("After Sorting " + Arrays.toString(nums));

	}
}