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
        let newNode = new Node(data);
        if(this.head == null) {
            this.head = newNode;
        } else {
            newNode.next = this.head;
            this.head = newNode;
        }
    }

    removeAtHead() {
        // check for underflow
        if(this.head == null) {
            console.log("Underflow");
            return;
        }
        // store head's reference data value in local data variable
        let data = this.head.data;
        this.head = this.head.next;
        return data;
    }

    printList() {
        // if head is null then list is empty
        if(this.head == null) {
            console.log("List is Empty");
        } else {
            // iterate through list until itr is not null
            let itr = this.head;
            while(itr != null) {
                console.log(itr.data);
                itr = itr.next;
            }
        }
    }
}

let l = new SinglyLinkedList();
l.insertAtHead(1);
l.insertAtHead('xyz');
l.insertAtHead(1.1);
l.removeAtHead();
l.printList()
