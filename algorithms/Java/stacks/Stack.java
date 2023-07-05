public class Stack<E> {

    private int MAX;
    private int top;
    private Object[] array;

    public Stack (int MAX) {
        this.MAX = MAX;
        this.array = (E[]) new Object[MAX];
        this.top = -1;
    }

    public boolean isEmpty() {
        return this.top < 0;
    }

    public boolean isFull() {
        return this.top >= MAX-1;
    }

    public E pop() {
        if (isEmpty()) {
            try {
                throw new Exception("EmptyStackException");
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        return (E) this.array[top--];
    }

    public E push(E val) {
        if (isFull()) {
            try {
                throw new Exception("StackOutOfBoundException");
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        this.array[++top] = val;
        return val;
    }

    public E peek() {
        if(isEmpty()) {
            try {
                throw new Exception("EmptyStackException");
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        return (E) this.array[top];
    }

    public int size() {
        return this.top+1;
    }

    public void display() {
        System.out.print("[ ");
        for (int i = 0; i <= top; i++) {
            System.out.print(this.array[i] + ", ");
        }
        System.out.print("]\n");
    }

}


class Runner{
    public static void main(String[] args) {
        Stack<Integer> stack = new Stack<Integer>(10);
        stack.push(45);
        stack.push(34);
        stack.display();

        System.out.println(stack.pop());
        stack.display();
        System.out.println(stack.peek());
        stack.display();
    }
}