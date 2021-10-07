class Node {
  constructor(data) {
    this.data = data;
    this.next = null;
  }
}

class SinglyLinkedList {
  constructor() {
    this.head = null;
  }

  // Will return the element at that particular index in linklist starting
  // from head.
  getByIndex(idx) {
    if (!this.head) {
      return 'List is Empty';
    }

    let currentNode = this.head;
    let iterationCount = 0;

    for (
      currentNode = this.head;
      currentNode != null;
      currentNode = currentNode.next
    ) {
      if (iterationCount == idx) {
        return currentNode;
      }
      iterationCount++;
    }

    return null;
  }

  setByIndex(idx, newValue) {
    const nodeElem = this.getByIndex(idx);
    if (nodeElem) {
      nodeElem.data = newValue;
      return nodeElem;
    }

    return null;
  }
  insertAtHead(data) {
    const newNode = new Node(data);
    if (this.head == null) {
      this.head = newNode;
    } else {
      newNode.next = this.head;
      this.head = newNode;
    }
  }

  // idx : index of the node after which you want to
  // insert the new node;
  // data: value associated with new node.
  insertAfterByIndex(idx, data) {
    let afterNode;
    let newNode;

    const beforeNode = this.getByIndex(idx);

    if (beforeNode) {
      afterNode = beforeNode.next;
      newNode = new Node(data);

      beforeNode.next = newNode;
      newNode.next = afterNode;

      return this;
    }

    return null;
  }

  // idx: index of the node which you want to remove from linklist.
  removeFromMiddle(idx) {
    const beforeNode = this.getByIndex(idx - 1);
    let afterNode;
    let nodeToRemove;

    if (beforeNode) {
      nodeToRemove = beforeNode.next;

      if (nodeToRemove) {
        afterNode = nodeToRemove.next;
        beforeNode.next = afterNode;

        return this;
      }
    }
    return null;
  }

  removeAtHead() {
    // check for underflow
    if (this.head == null) {
      console.log('Underflow');
      return;
    }
    // store head's reference data value in local data variable
    const data = this.head.data;
    this.head = this.head.next;
    return data;
  }

  insertAtEnd(data) {
    const newNode = new Node(data);
    if (!this.head) {
      this.head = newNode;
      return this;
    }

    let currentNode = this.head;

    while (currentNode.next) {
      currentNode = currentNode.next;
    }

    currentNode.next = newNode;

    return this;
  }

  // Removes elements which are at the end of the linklist.
  removeFromEnd() {
    if (!this.head) {
      console.log('List is Empty');
      return this;
    }

    let returnNode;
    if (!this.head.next) {
      returnNode = this.head;
      this.head = null;
      return returnNode;
    }

    let currentNode = this.head.next;
    let previousNode = this.head;

    while (currentNode) {
      if (currentNode.next) {
        previousNode = currentNode;
      }
      currentNode = currentNode.next;
    }
    returnNode = previousNode.next;
    previousNode.next = null;
    return returnNode;
  }

  rotate() {
    if (!this.head) {
      return;
    }

    let currentNode = this.head;
    let previousNode = null;
    let tempNextRefNode;

    while (currentNode) {
      tempNextRefNode = currentNode.next;
      currentNode.next = previousNode;

      previousNode = currentNode;
      currentNode = tempNextRefNode;
    }

    this.head = previousNode;

    return this;
  }

  printList() {
    // if head is null then list is empty
    if (this.head == null) {
      console.log('List is Empty');
    } else {
      // iterate through list until itr is not null
      let itr = this.head;
      while (itr != null) {
        console.log(itr.data);
        itr = itr.next;
      }
    }
  }
}

const array = new SinglyLinkedList();
array.insertAtHead(1);
array.insertAtHead('xyz');
array.insertAtHead(1.1);
array.removeAtHead();
array.insertAtEnd(99);
array.insertAtEnd(100);
array.insertAtEnd(101);
array.insertAtEnd(102);
array.insertAtEnd(103);
array.insertAtEnd(104);
array.insertAtEnd(105);

array.printList();

array.removeFromEnd();

array.printList();

array.rotate();

array.printList();
