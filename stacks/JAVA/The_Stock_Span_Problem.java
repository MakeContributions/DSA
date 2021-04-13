

import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Stack ;

/**
 * Problem statement :
 * The stock span problem is a financial problem where we have a series of n daily price quotes for a stock 
 * and we need to calculate span of stock’s price for all n days.
 * The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before the given day, 
 * for which the price of the stock on
 * the current day is less than or equal to its price on the given day.
 * For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, then the span values for corresponding 
 * 7 days are {1, 1, 1, 2, 1, 4, 6}
 */
class The_Stock_Span_Problem extends stack{

    public The_Stock_Span_Problem(int Max) {
        super(Max);
    }

    /**
     * this problem is being solved with stack abstract data type.
     */
    public void problem(int[] price,int n,int[] span){
        stack st = new stack(Max);
        st.push(0);

        //span of the first day is always going to be 1
        span[0] = 1;


        for (int i = 1;i < n;i ++){
            span[i] = 1;
            st.PrintStack();
            while(!st.isEmpty() && price[st.top()] <= price[i]){
                st.pop();
            }

            if (st.isEmpty()){
                span[i] = i + 1;
            }
            else{
                span[i] = i - st.top();
            }
            st.push(i);
        }
        printArray(span);

    }

    public void printArray(int[] span){
        System.out.println("The span of the stock array :" + Arrays.toString(span));
    }

    /**
     * This is a different approach that has slightly higher time complexity than the approach used above
     * Both the methods are awesome and star struck but...xD
     */
    public void alternate_approach(int[] price,int n,int[] span){

        Stack<Integer> sta = new Stack<>();

        span[0] = 1;

        for (int i = 1;i < n;i++){
            for (int j = 0;j < i;j++){
                sta.push(j);
            }

            while(!sta.isEmpty() && price[sta.peek()] <= price[i]){
                sta.pop();
            }
            if (sta.isEmpty()){
                span[i] = i + 1;
            }
            else{
                span[i] = i - sta.peek();
            }
            sta.clear();
        }
        printArray(span);
    }
}

class Main {

    //to test the span stock problem
    public static void main(String[] args){
        int[] price = { 10, 4, 5, 90, 120, 80 };
        int n = price.length;
        int[] span = new int[n];

        The_Stock_Span_Problem prob = new The_Stock_Span_Problem(1000);
        prob.alternate_approach(price,n,span);
    }
}
