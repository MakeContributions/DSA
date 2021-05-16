/* Given a Binary Tree, print Left view of it. 
Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. */
import java.util.LinkedList; 
import java.util.Queue; 
import java.io.*;
import java.util.*;

class Node{
    int data;
    Node left;
    Node right;
    Node(int data){
        this.data = data;
        left=null;
        right=null;
    }
}
//Main Class
class Main {
    
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
            }
                
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
    static void printInorder(Node root) {
        //Print inorder of tree.
        if(root == null)
            return;
            
        printInorder(root.left);
        System.out.print(root.data+" ");
        
        printInorder(root.right);
    }
    
	public static void main (String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //number of testcases.
        int t=Integer.parseInt(br.readLine());

        while(t > 0){
            //Input a string for tree
            String s = br.readLine();
            Node root = buildTree(s);
            Tree g = new Tree();
            //calculate in left view of tree by calling function
            ArrayList<Integer> result1 = g.leftViewIterative(root);
            ArrayList<Integer> result2 = g.leftViewRecursive(root);
            //print the result
            System.out.println("Iterative Solution:");
            for(int value : result1){
                System.out.print(value + " ");
            }
            System.out.println("Recursive Solution:");
            for(int value : result2){
                System.out.print(value + " ");
            }
            System.out.println();
            t--;
        }
    }
}

class Tree {
    ArrayList<Integer> al;
    //Iterative Approach
    ArrayList<Integer> leftViewIterative(Node root) {
        al = new ArrayList<Integer>();
        if(root==null) return al;
        //create a queue to store the node of treees
        Queue<Node> q = new LinkedList<>();
        q.add(root);
        while(!q.isEmpty()){
            int n = q.size();
            //loop through available nodes in queue.
            for(int i=1;i<=n;i++){
                Node temp = q.poll();
                //add first node from queue as it would be left most node
                if(i==1) al.add(temp.data);
                if(temp.left!=null) q.add(temp.left);
                if(temp.right!=null) q.add(temp.right);
            }
        }
        return al;
    }

    //Recursive Approach
    int maxlvl=0;
    ArrayList<Integer> leftViewRecursive(Node root) {
        al = new ArrayList<Integer>();
        //start from root of the tree
        leftViewUtil(root, 1);
        return al;
    }
    void leftViewUtil(Node node, int lvl){
        if(node==null) return;
        //first occurrence of the level will get added
        if(maxlvl<lvl){
            al.add(node.data);
            //make the max level to curr level
            maxlvl = lvl;
        }
        //increment the level of tree to get left most of next level
        leftViewUtil(node.left, lvl+1);
        leftViewUtil(node.right, lvl+1);
    }
}

/* Input : 
                 1
               /   \
              2     3
             / \     \
            4   5     6             
Output : 
Iterative Approach:
1 2 4
Recursive Approach:
1 2 4

Input :
        1
      /   \
    2       3
      \   
        4  
          \
            5
             \
               6
Output :
Iterative Approach:
1 2 4 5 6
Recursive Approach:
1 2 4 5 6

Time Complexity: O(n) , where n is the number of nodes in the binary tree.
Auxiliary Space: O(n), due to the stack space during recursive call. 
*/