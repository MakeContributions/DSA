class Node{  
    int value;  
    Node left;  
    Node right;  

    public Node(int value) {  
        this.value = value;  
    }  
}

public class pre_in_post_traversal{

    public static void preOrder(Node node){
        if (node == null) return;

        System.out.print(node.value + ", ");
        preOrder(node.left);
        preOrder(node.right);
    }

    public static void inOrder(Node node){
        if(node == null) return;

        inOrder(node.left);
        System.out.print(node.value + ", ");
        inOrder(node.right);
    }

    public static void postOrder(Node node){
        if(node == null) return;
        postOrder(node.left);
        postOrder(node.right);
        System.out.print(node.value + ", ");
    }


    public static void main(String [] args){
        Node root = new Node(4);
        root.left = new Node(2);
        root.right = new Node(7);
        root.left.right = new Node(6);
        root.left.left = new Node(1);
        root.right.right = new Node(9);

        System.out.print("pre order: ");
        preOrder(root);
        
        System.out.println("\n");
        System.out.print("in order: ");
        inOrder(root);

        System.out.print("\n\npost order: ");
        postOrder(root);
    }
}

/*
tree structure:
        4
      /   \
    2       7
  /   \       \
1      6       9

to run the file:
    javac .\pre_in_post_traversal.java
    java pre_in_post_traversal

results:
    pre order: 4, 2, 1, 6, 7, 9, 

    in order: 1, 2, 6, 4, 7, 9,

    post order: 1, 6, 2, 9, 7, 4,

*/
