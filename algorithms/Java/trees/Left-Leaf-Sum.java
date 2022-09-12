package Trees.Left_Leaf_Sum;
/*
 				3
 			 /	   \
 			9       20
 		            /    \
                  15     8
                  
       there are two left leaves(nodes which have no child) in the above tree and their sum is 24           
*/

class TreeNode{
	  int data;
	  TreeNode left,right;

	  TreeNode(int data){
	    this.data = data;
	    this.left = this.right = null;
	  }
	}
class Tree{
	TreeNode root;
	
	public Tree() {
		root=null;
	}
}
public class LeftLeafSum {
	
	 //method to check if a node is leaf or not
	static boolean isLeaf(TreeNode root)
    {
        if (root == null)   return false;
        if (root.left == null && root.right == null)    
        return true;
        
        return false;
    }
	
	//returns the sum of left leaves
        public static int leftsum(TreeNode root){
        
        int leftLeavesSum=0;
        
        //to avoid null pointer exception
        if(root!=null)
        {
        
        //if a node's left is a leaf then add its value	
        if( isLeaf(root.left) )
        leftLeavesSum+=root.left.data;
        
        //else go to left
        else
        leftLeavesSum+=leftsum(root.left);
        
        //and finally go to right
        leftLeavesSum+=leftsum(root.right);
        }
        
        return leftLeavesSum;
        
        
        
        
        
  }
	
public static void main(String[] args) {
	Tree tree = new Tree();
    tree.root = new TreeNode(1);
    tree.root.left = new TreeNode(2);
    tree.root.right = new TreeNode(3);
    tree.root.left.left = new TreeNode(7);
    tree.root.left.right = new TreeNode(8);
    tree.root.right.left = new TreeNode(81);
    tree.root.right.right= new TreeNode(75);
    
    
    int sumOfLeftLeaves = leftsum(tree.root);
    System.out.println("sum of left leaves is "+sumOfLeftLeaves);   
}
}
