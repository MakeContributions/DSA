// Implement Stack using two queues
class Stack {
  constructor() {
    this.queue1 = new Queue();
    this.queue2 = new Queue();
  }

  push(value) {
    this.queue1.enqueue(value);
  }

  pop() {
    if (!this.queue1.first) return null;
    while (this.queue1.size > 1) {
      this.queue2.enqueue(this.queue1.dequeue());
    }
    const temp = this.queue1.dequeue();
    this.queue1 = this.queue2;
    this.queue2 = new Queue();
    return temp;
  }

  printStack() {
    if (this.queue1.size === 0) return null;
    let current = this.queue1.first;
    while (current) {
      console.log(current.value);
      current = current.next;
    }
  }
}

class Node {
  constructor(value) {
    this.value = value;
    this.next = null;
  }
}

class Queue {
  constructor() {
    this.first = null;
    this.last = null;
    this.size = 0;
  }

  enqueue(value) {
    const newNode = new Node(value);
    if (!this.first) {
      this.first = newNode;
      this.last = newNode;
    } else {
      this.last.next = newNode;
      this.last = newNode;
    }
    this.size++;
  }

  dequeue() {
    if (!this.first) return null;
    const temp = this.first;
    this.first = this.first.next;
    this.size--;
    return temp.value;
  }
}

const stack = new Stack();
stack.push(1);
stack.push(2);
stack.push(3);
stack.push(4);

stack.printStack();

console.log(stack.pop());

stack.printStack();
