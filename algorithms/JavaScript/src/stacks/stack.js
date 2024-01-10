class Stack {
  constructor() {
    this.items = [];
  }

//creating push method
  push(element) {
    this.items.push(element);
  }

//creating pop method
  pop() {
    return this.items.pop();
  }

  //creating printStack method
  printStack() {
    console.log(this.items);
  }
}

//creating Stack object
const stack = new Stack();
stack.push(1);
stack.push(2);
stack.push(3);
stack.push(4);

stack.printStack();

console.log(stack.pop());

stack.printStack();
