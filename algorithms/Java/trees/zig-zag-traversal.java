//Given a Binary Tree. Find the Zig-Zag Level Order Traversal of the Binary Tree.

import java.util.*;
import java.util.HashMap;
import java.io.*;

class Node{
    int data;
    Node left,right;
    Node(int data){
        this.data = data;
        left=null;
        right=null;
    }
}

//Main Class
public class Main {
    static Node buildTree(String str){
        if(str.length()==0 || str.charAt(0)=='N'){
            return null;
        }
        String ip[] = str.split(" ");
        // Create the root of the tree
        Node root = new Node(Integer.parseInt(ip[0]));
        // Push the root to the queue
        Queue<Node> queue = new LinkedList<>(); 
        queue.add(root);
        // Starting from the second element
        int i = 1;
        while(queue.size()>0 && i < ip.length) {
            // Get and remove the front of the queue
            Node currNode = queue.peek();
            queue.remove();
            // Get the current node's value from the string
            String currVal = ip[i];
            // If the left child is not null
            if(!currVal.equals("N")) {
                // Create the left child for the current node
                currNode.left = new Node(Integer.parseInt(currVal));
                // Push it to the queue
                queue.add(currNode.left);
            
            // For the right child
            i++;
            if(i >= ip.length)
                break;    
            currVal = ip[i];
            // If the right child is not null
            if(!currVal.equals("N")) {
                // Create the right child for the current node
                currNode.right = new Node(Integer.parseInt(currVal));
                // Push it to the queue
                queue.add(currNode.right);
            }
            i++;
        }
        return root;
    }
	public static void inorder(Node root) {
	    if(root==null)
	    return;
	    inorder(root.left);
	    System.out.print(root.data);
	    inorder(root.right);
	}
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t=Integer.parseInt(br.readLine());
        while(t > 0){
            String s = br.readLine();
            Node root = buildTree(s);
            GFG g = new GFG();
            ArrayList<Integer> res = g.zigZagTraversal(root) ;
            for (int i = 0; i < res.size (); i++)
                System.out.print (res.get (i) + " ");
            System. out. println();  
            t--;
        }
	}
}
// Print the zig zag traversal of tree.
class GFG {
    // return an array containing the zig zag level order traversal of the given tree
	ArrayList<Integer> zigZagTraversal(Node root) {
	    ArrayList<Integer> al = new ArrayList<>();
        // if null then return empty list
        if (rootNode == null)
            return al;
        // declare two stacks
	    Stack<Node> currlvl = new Stack<>();
	    Stack<Node> nextlvl = new Stack<>();
        // push the root
	    currlvl.push(root);
	    boolean leftToRight = true;
        // check if stack is empty
	    while(!currlvl.empty()){
            // pop out of stack
	        Node curr= currlvl.pop();
            // add the data in it
	        al.add(curr.data);
            // store data according to current order
	        if(leftToRight){
	            if(curr.left!=null) nextlvl.push(curr.left);
	            if(curr.right!=null) nextlvl.push(curr.right);
	        }
	        else{
	            if(curr.right!=null) nextlvl.push(curr.right);
	            if(curr.left!=null) nextlvl.push(curr.left);
	        }
            // once currlvl is empty, put nextlvl data to currlvl and make nextlvl empty
	        if(currlvl.empty()){
	            leftToRight = !leftToRight;
	            Stack<Node> temp = currlvl;
	            currlvl = nextlvl;
	            nextlvl = temp;
	        }
	    }
	    return al;
	}
}
/* Input:
        3
      /   \
     2     1
Output:
3 1 2

Input:
           7
        /     \
       9       7
     /  \     /   
    8    8   6     
   /  \
  10   9 
Output:
7 7 9 8 8 6 9 10  

Time Complexity: O(n) where n is number of nodes
Space Complexity: O(n)+(n)=O(n)

*/