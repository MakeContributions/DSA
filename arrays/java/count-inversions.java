// Algorithm Type: Divide & Conquer
// Time Complexity: O(n*log(n))

import java.io.File;
import java.lang.reflect.Array;
import java.util.*;

public class inversions {
  private static long count_split_inv(int[] arr, int[] left, int[] right) {
    long split_inv = 0;
    int ridx = 0, lidx = 0;
    int size = arr.length;
    int rsize = right.length;
    int lsize = left.length;
    for (int i = 0; i < size; i++) {
      if (lidx != lsize && ridx != rsize) {
        if (right[ridx] <= left[lidx]) {
          arr[i] = right[ridx];
          ridx++;
          split_inv += lsize - lidx;
        } else {
          arr[i] = left[lidx];
          lidx++;
        }
      } else if (lidx == lsize) {
        arr[i] = right[ridx];
        ridx++;
      } else if (ridx == rsize) {
        arr[i] = left[lidx];
        lidx++;
      }
    }
    return split_inv;
  }

  private static long count_inversions(int[] arr) {
    int size = arr.length;
    if (size == 1) {
      return 0;
    }
    int[] left = Arrays.copyOfRange(arr, 0, size / 2);
    int[] right = Arrays.copyOfRange(arr, size / 2, size);
    long left_inv = count_inversions(left);
    long right_inv = count_inversions(right);
    long split_inv = count_split_inv(arr, left, right);

    return left_inv + right_inv + split_inv;
  }

  public static void main(String[] args) {
    try {
      int[] arr = {8, 2, 1, 5, 7, 3, 9, 2, 0, 1};
      System.out.println(count_inversions(arr));
    } catch (Exception e) {
      System.out.println("Err... ");
    }

  }
}
