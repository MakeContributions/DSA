

public class Main {

    //to test the span stock problem
    public static void main(String[] args){
        int[] price = { 10, 4, 5, 90, 120, 80 };
        int n = price.length;
        int[] span = new int[n];

        The_Stock_Span_Problem prob = new The_Stock_Span_Problem(1000);
       // prob.alternate_approach(price,n,span);

        Balanced_Paranthesis bal = new Balanced_Paranthesis();
        bal.problem("((()))");
    }
}
