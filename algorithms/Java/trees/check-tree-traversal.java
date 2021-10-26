/** Author : Suraj Kumar
 * Github : https://github.com/skmodi649
 */



/** PROBLEM DESCRIPTION :
 * Given Preorder, Inorder and Postorder traversals of some tree of size N.
 * The task is to check if they are all of the same tree or not
 */



/** ALGORITHM :
 * The root element will be the first element of preorder.
 * Search for root in the inorder array and store it’s index as idx.
 * Use this idx to determine elements of left and right subtree in all three traversal arrays.
 * Call function recursively for both left and right sub tree.
 */




import java.lang.*;
import java.util.*;

class Tree{
    int val;
    Tree left, right;
    Tree(int val){
        this.val = val;
        left = null; right = null;
    }
}

class Main{
    static int idx;
    static boolean isPossible;

    public boolean checktree(int[] preorder, int[] inorder, int[] postorder, int N){
        idx = 0;
        isPossible = true;
        Map<Integer, Integer> hmap = new HashMap<>();
        for(int i = 0; i < inorder.length; i++) hmap.put(inorder[i], i);
        Tree root = buildTree(inorder, preorder, hmap, 0, N-1);
        if(!isPossible) return false;
        List<Integer> post = new ArrayList<>();
        buildPost(root, post);

        return Arrays.equals(post.stream().mapToInt(i->i).toArray(), postorder);
    }

    private static void buildPost(Tree root, List<Integer> post){
        if(root == null) return;
        buildPost(root.left, post);
        buildPost(root.right, post);
        post.add(root.val);
    }

    private static Tree buildTree(int[] inorder, int[] preorder, Map<Integer, Integer> hmap, int start, int end){
        if(start > end) return null;
        if(!isPossible) return null;
        int val = preorder[idx++];
        Tree root = new Tree(val);
        if(!hmap.containsKey(val)){
            isPossible = false;
            return null;
        }
        int pos = hmap.get(val);
        if(pos < start || pos > end){
            isPossible = false;
            return null;
        }
        root.left = buildTree(inorder, preorder, hmap, start, pos-1);
        root.right = buildTree(inorder, preorder, hmap, pos+1, end);
        return root;
    }

    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the value of N : ");
            int n = sc.nextInt();
            int[] preorder = new int[n];
            int[] inorder = new int[n];
            int[] postorder = new int[n];
            System.out.println("Enter the elements of preorder array : ");
            for(int i=0; i<n; i++)
                preorder[i] = sc.nextInt();
            System.out.println("Enter the elements of inorder array : ");
            for(int i=0; i<n; i++)
                inorder[i] = sc.nextInt();
            System.out.println("Enter the elements of postorder array : ");
            for(int i=0; i<n; i++)
                postorder[i] = sc.nextInt();
            Main ob = new Main();
            if(ob.checktree(preorder, inorder, postorder, n) )
                System.out.println("Yes");
            else
                System.out.println("No");
        }
    }



/** TEST CASES :
 * Test Case 1 :
 * Input : N = 5 , preorder[] = {1, 2, 4, 5, 3} , inorder[] = {4, 2, 5, 1, 3} and postorder[] = {4, 5, 2, 3, 1}
 * Output : Yes
 *
 * Test Case 2 :
 * Input : N = 5 , preorder[] = {1, 5, 4, 2, 3} , inorder[] = {4, 2, 5, 1, 3} and postorder[] = {4, 1, 2, 3, 5}
 * Output : No
  */



/** Explanation for Test Case 1 :
 * All the three traversals
 * are of the same tree.
 *            1
 *          /   \
 *         2     3
 *       /   \
 *      4     5
 * hence the output is Yes
 */


/** Time Complexity : O(N^2)
 * Auxiliary Space Complexity : O(N)
 * Constraints : 1 ≤ N ≤ 103
 *               Node values are unique.
 */



