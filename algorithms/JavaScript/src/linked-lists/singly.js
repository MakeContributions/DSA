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

  insertAtHead(data) {
    const newNode = new Node(data);
    if (this.head == null) {
      this.head = newNode;
    } else {
      newNode.next = this.head;
      this.head = newNode;
    }
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
array.printList();
