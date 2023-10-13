// lOWEST NUMBER HAS THE HIGHEST PRIORITY
// using a linked list

class Node {
    constructor(value, priority) {
        this.value = value;
        this.priority = priority;
        this.next = null;
    }
}

class PriorityQueue {
    constructor() {
        this.first = null;
        this.size = 0;
    }

    enqueue(value, priority) {
        const newNode = new Node(value, priority);
        if (!this.first || priority < this.first.priority) {
            newNode.next = this.first;
            this.first = newNode;
        } else {
            let current = this.first;
            while (current.next && priority > current.next.priority) {
                current = current.next;
            }
            newNode.next = current.next;
            current.next = newNode;
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

    printQueue() {
        let current = this.first;
        while (current) {
            console.log(current.value);
            current = current.next;
        }
    }
}

const priorityQueue = new PriorityQueue();
priorityQueue.enqueue('Hnzaxw4', 4);
priorityQueue.enqueue('Hnzaxs3', 2);
priorityQueue.enqueue('Hnzaxws3', 3);
priorityQueue.enqueue('Hnzaxs1', 1);
priorityQueue.enqueue('Hnzaxs1', 1);

priorityQueue.printQueue();

priorityQueue.dequeue();
priorityQueue.dequeue();
priorityQueue.printQueue();


// Implementations of a priority queue using a array

class PriotyQueueArray {
    constructor() {
        this.values = [];
    }
    enqueue(val, priority) {
        this.values.push({ val, priority });
        this.sort();
    }
    dequeue() {
        return this.values.shift();
    }
    sort() {
        this.values.sort((a, b) => a.priority - b.priority);
    }
    showItems() {
        console.log(this.values);
    }
}

const priorityQueueArray = new PriotyQueueArray();
priorityQueueArray.enqueue('Hnzaxw4', 4);
priorityQueueArray.enqueue('Hnzaxs3', 2);
priorityQueueArray.enqueue('Hnzaxws3', 3);
priorityQueueArray.enqueue('Hnzaxs1', 1);
priorityQueueArray.enqueue('Hnzaxs0', 0);
priorityQueueArray.showItems();

priorityQueueArray.dequeue();
priorityQueueArray.dequeue();

priorityQueueArray.showItems();