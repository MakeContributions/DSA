import java.util.Arrays;
import java.util.Scanner;
public class Knapsack_greedy_approach {
    public static void main(String[] args) {
        System.out.println("KnapSack Problem (Greedy Approach)");
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Maximum capacity of Sack");
        double cap=sc.nextDouble();
        System.out.println("Enter the no. of items : ");
        int n=sc.nextInt();
        System.out.println("Enter the weights and profits of items");
        double w[]=new double[n];
        double p[]=new double[n];
        double price_per_weight[]=new double[n];
        for (int i = 0; i < n; i++) {
            System.out.println("Enter the weight and profit of "+(i+1)+" item");
            w[i] = sc.nextDouble();
            p[i] = sc.nextDouble();
        }
        double x[]=new double[n];
        for (int i = 0; i < n; i++) {
            x[i]=0;
            price_per_weight[i]=p[i]/w[i];
        }
        System.out.println(Arrays.toString(price_per_weight));
        while (cap>0){
            int g= greatest(price_per_weight);
            if (cap>=w[g]){
                cap-=w[g];
                x[g]=1;
            }
            else{
                x[g]=cap/w[g];
                cap=0;
            }
        }
        double profit=0;
        for(int i=0;i<n;i++) {
            profit=profit+(x[i]*p[i]);
        }
        System.out.println("The profit is "+ profit);
    }
    public static int greatest(double[] price_per_weight){
        int gre =0;
        double temp=price_per_weight[0];
        for (int i = 1; i < price_per_weight.length; i++) {
            if(temp < price_per_weight[i]){
                temp=price_per_weight[i];
                gre=i;
            }
        }
        price_per_weight[gre]=0;
        return gre;
    }
}
/*
OUTPUT :
KnapSack Problem (Greedy Approach)
Enter Maximum capacity of Sack
60
Enter the no. of items : 
5
Enter the weights and profits of items
Enter the weight and profit of 1 item
5 30
Enter the weight and profit of 2 item
10 40
Enter the weight and profit of 3 item
15 45
Enter the weight and profit of 4 item
22 77
Enter the weight and profit of 5 item
25 90
[6.0, 4.0, 3.0, 3.5, 3.6]
The profit is 230.0

*/
