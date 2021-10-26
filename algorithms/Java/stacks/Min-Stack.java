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

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
