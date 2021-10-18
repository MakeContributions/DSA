// Program to print Catalan Numbers till n using recursive approach.

import java.util.*;

class CatalanNumbers{

	public static int findCat(int n){

		int val = 0;

		if (n<=1) return 1;

		for (int i=0;i<n;i++){

			val+= findCat(i)*findCat(n-i-1);
		}

		return val;
	}


	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();

		for (int i=0;i<=n;i++) System.out.print(findCat(i)+" "); 

	}



}

/* Applications of Catalan Numbers
	-Number of possible full binary trees with n+1 leaves
	-Number of possible Binary Search Trees with n nodes
	-Number of ways a convex polygon of n+2 sides can be split into triangles by connecting vertices
	-Refer this link for more :- https://iq.opengenus.org/applications-of-catalan-numbers/
*/	