// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// Implement the MinStack class:

// MinStack() initializes the stack object.
// void push(int val) pushes the element val onto the stack.
// void pop() removes the element on the top of the stack.
// int top() gets the top element of the stack.
// int getMin() retrieves the minimum element in the stack.
 

// Java program to implement a stack that supports
// getMinimum() in O(1) time and O(1) extra space.
import java.util.*;

// A user defined stack that supports getMin() in
// addition to push() and pop()
class MinStack {
    long min = 0;
    Stack<Long> stack = new Stack<>();
    
    public void push(int x) {
        // only push the old minimum value when the current 
        // minimum value changes after pushing the new value x
        if(stack.size() == 0){
            stack.push((long) x);
            min = x;
        }
        else if(x < min){          
            stack.push((long) 2*x - min);
            min=x;
        }else
        stack.push((long) x);
    }

    public void pop() {
        // if pop operation could result in the changing of the current minimum value, 
        // pop twice and change the current minimum value to the last minimum value.
        if(stack.peek() < min) {
            min = 2*min - stack.pop();
        }else
            stack.pop();
    }

    public int top() {
        if (stack.peek() < min)
            return (int) min;
        else
            return (int) (long) stack.peek();
    }

    public int getMin() {
        return (int) min;
    }
}

// Driver Code
public class Main
{
  public static void main(String[] args)
  {
    MinStack s = new MinStack();
    s.push(3);
    s.push(5);
    System.out.println("Min element present is: "+ s.getMin());
    s.push(2);
    s.push(1);
    System.out.println("Min element present is: "+ s.getMin());
    s.pop();
    System.out.println("Min element present is: "+ s.getMin());
    s.pop();
    System.out.println("Top element present is: " + s.top());
  }
}

//TC: O(1)
//SC: O(1)
// Output
// Min element present is: 3
// Min element present is: 1
// Min element present is: 2
// Top element present is: 5

