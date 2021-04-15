
import java.util.Arrays;

public class BubbleSort {
	static int temp = 0;
	static int[] nums = { 13, 34, 12, 45, 56, 32, 20 };

	public static void main(String[] args) {

		System.out.println("Before Sorting : "+Arrays.toString(nums));
		sort();

	}
  //create method sorting array
	public static void sort() {
		for (int i = 1; i < nums.length; i++) {
			for (int j = 0; j < i; j++) {
				if (nums[j] > nums[i]) {
					temp = nums[j];
					nums[j] = nums[i];
					nums[i] = temp;
				}
			}
		}
		System.out.println(Arrays.toString(nums));
	}
}