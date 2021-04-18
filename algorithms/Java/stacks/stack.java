

 class stack {
    public int Max;
    public int Top;
    public int[] stack;

    public stack(int Max){
        this.Max = Max;
        stack = new int[Max];
        Top = -1;
    }

    /**
     * if the stack is empty then always the top will be -1
     * so this should return a boolean if value of top < 1 then returns true which means
     * stack is empty.
     */
    public boolean isEmpty(){
        return (Top < 0);
    }

    public int size(){
        return (Top+1);
    }

    public void push(int x){
        if (size() >= Max){
            System.out.println("Stack Overflow");
        }
        else{
            Top = Top + 1;
            stack[Top] = x;
        }
    }

    /**
     * pop function pops out the top element in the queue
     * returns the element that is popped out of the queue
     */
    public int pop(){
        if (size() == 0){
            System.out.println("Stack Empty Exception");
        }
        else {
            /**
             * the top element in the stack will be popped out from the stack
             */
            int popped_element = stack[Top];
            Top = Top - 1;
            return popped_element;
        }
        return -1;
    }

    public int top(){
        if(isEmpty()){
            System.out.println("Stack Empty Exception");
        }
        else{
            return stack[Top];
        }
        return -1;
    }

    public void PrintStack(){
        if (isEmpty()){
            System.out.println("Empty");
        }
        else{
            for(int i = 0;i < size();i++){
                System.out.print(stack[i] + " ");
            }
            System.out.println();
        }
    }

}
class Main {

    public static void main(String[] args){
    	max = 1000;
        stack object = new stack(max);
        object.push(1);
        object.push(2);
        object.push(3);
        object.pop();
        object.top();
        object.PrintStack();
    }
}


