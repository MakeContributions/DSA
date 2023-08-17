import java.util.List;
import java.util.ArrayList;

class Subsets {
    // Given an integer array nums of unique elements, return all possible 
    // subsets (the power set).
    // The solution set must not contain duplicate subsets. Return the solution in any order.

    static void dfs(
            List<Integer> subset,          
            List<List<Integer>> subsets,   
            int[] nums,                   
            int i                        
    ) {
        // Base case: when we have processed all elements in the array
        if (i == nums.length) {
            // Add the current subset to the list of subsets
            subsets.add(new ArrayList<>(subset));
            return;
        }

        // Include the current element in the subset
        subset.add(nums[i]);

        // Recursively generate subsets including the current element
        dfs(subset, subsets, nums, i + 1);

        // Backtrack: Remove the last element to explore subsets without it
        subset.remove(subset.size() - 1);

        // Recursively generate subsets without the current element
        dfs(subset, subsets, nums, i + 1);
    }

    static List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> subsets = new ArrayList<>();

        dfs(new ArrayList<>(), subsets, nums, 0);

        return subsets;
    }

    public static void main(String[] args) {
        // Example usage
        System.out.println(subsets(new int[]{1, 2, 3}));
        System.out.println(subsets(new int[]{0}));

        // time complexity is : O(2^n) where n is the size of input array
    }
}
