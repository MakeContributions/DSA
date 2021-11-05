function Node(val) {
  this.value = val;
  this.next = null;
  this.previous = null;
}

function DoubleLinkList() {
  // Initially when we create an object of DoubleLinkList(DLL),
  // we will want it to be an empty object
  // i.e its length will be 0 and head and tail will be null.
  this.length = 0;
  this.head = this.tail = null;
}

// A DLL will only have
// length, head and tail, all the other methods will be one level up.
DoubleLinkList.prototype.append = function(val) {
  if (val) {
    // Create a new node by passing it the value which the user has passed.
    const newNode = new Node(val);

    // Check if the head is null, if it is
    // that means this is the first entry, hence assign
    // hence make the newNode as the head and tail.
    if (!this.head) {
      this.head = this.tail = newNode;
    } else {
      // elsepart: if the head and tail is not null
      // then take the next pointer of tail and connect it to newNode
      this.tail.next = newNode;

      // take the previous pointer of the newNode and connect it to tail.
      newNode.previous = this.tail;

      // Now we have connected the newNode to DLL, so lets
      // So let's make the newNode as the tail.
      this.tail = newNode;
    }

    // finally increment the length of DLL.
    this.length++;
    return this;
  }

  return null;
};

// inserts a new node into dll at a particular position.
DoubleLinkList.prototype.insertAt = function(val, position = 0) {
  if (!this.head && position !== 0) return null;

  const newNode = new Node(val);
  let currentNode = this.head;

  // Boolean flag to keep track of whether we are updating
  // the dll or not, so that common code related to updation
  // is not written more than once.
  let isNodeInserted = false;

  // If position is 0 and head is empty i.e dll is empty
  // so we are assigning the newNode to head and tail
  // else we are assigning the next of newNode to head,
  // previous of head to newNode and eventually
  // we are making the head as the newNode.
  if (position === 0) {
    if (!this.head) {
      this.head = this.tail = newNode;
    } else {
      currentNode = this.head;
      newNode.next = currentNode;
      currentNode.previous = newNode;
      this.head = newNode;
      isNodeInserted = true;
    }
  }

  // Check if the position is valid.
  if (position > 0 && position <= this.length) {
    let idx = 0;

    // iterate to the node just before the position.
    while (idx < position - 1) {
      if (currentNode.next) {
        currentNode = currentNode.next;
      }
      idx++;
    }

    newNode.previous = currentNode;
    newNode.next = currentNode.next;
    currentNode.next = newNode;

    // If newNode.next exists, we are assigning its previous
    // to newNode, else we are making the newNode as tail.
    if (newNode.next) {
      newNode.next.previous = newNode;
    } else {
      this.tail = newNode;
    }
    isNodeInserted = true;
  }

  // Common code if the insertion succeeds.
  if (isNodeInserted) {
    this.length++;
  }

  // Now this is very important we are returning the instance
  // i.e the dll so that we can do something like method chaining.
  return this;
};

// Remove an element from a particular position in dll.
DoubleLinkList.prototype.removeAt = function(position) {
  if (position === null || position === undefined) return null;
  // checking if the dll is empty or the position is out of bounds.
  if (!this.head || position < 0 || position > this.length) return null;

  let currentNode = this.head;
  let iteration = 0;

  // iterating until we find the position.
  while (iteration !== position) {
    if (currentNode.next) {
      currentNode = currentNode.next;
    }
    iteration++;
  }

  let previousNode = null;
  let nextNode = null;

  if (currentNode.previous) {
    previousNode = currentNode.previous;
  }

  if (currentNode.next) {
    nextNode = currentNode.next;
  }

  if (previousNode) {
    previousNode.next = nextNode;

    if (currentNode === this.tail) {
      this.tail = previousNode;
    }
  }
  if (nextNode) {
    nextNode.previous = previousNode;

    if (currentNode === this.head) {
      this.head = nextNode;
    }
  }

  this.length--;
  return currentNode;
};

DoubleLinkList.prototype.indexOf = function(elm) {
  if (!this.head) return null;

  let currentNode = this.head;
  let idx = 0;
  while (currentNode) {
    if (currentNode.value === elm) {
      return idx;
    }
    idx++;
    currentNode = currentNode.next;
  }

  return null;
};

DoubleLinkList.prototype.delete = function(elm) {
  const idx = this.indexOf(elm);
  return this.removeAt(idx);
};

DoubleLinkList.prototype.toArray = function() {
  if (!this.head) return null;

  const arr = [];
  let currentNode = this.head;

  while (currentNode) {
    arr.push(currentNode.value);
    currentNode = currentNode.next;
  }
  return arr;
};

DoubleLinkList.prototype.toString = function() {
  if (!this.head) return null;

  let currentNode = this.head;
  let returnString = '';

  while (currentNode) {
    returnString += currentNode.value + ' ';
    currentNode = currentNode.next;
  }

  return returnString;
};

DoubleLinkList.prototype.isEmpty = function() {
  return this.length === 0;
};

DoubleLinkList.prototype.size = function() {
  return this.length;
};

DoubleLinkList.prototype.getHead = function() {
  return this.head;
};

DoubleLinkList.prototype.getTail = function() {
  return this.tail;
};

const dll = new DoubleLinkList();
console.log('Initialized an instance of DLL');
dll.append(1).append(2).append(3).append(4);

console.log(`Before insertAt : ${dll.toString()}`);
dll.insertAt(23, 4);

console.log(`After insertAt : ${dll.toString()}`);

console.log('Removing element at index 3');
dll.removeAt(3);

console.log(`After removing element at index 3 : ${dll.toString()}`);

dll.insertAt(45, 2);

console.log(`After inserting 45 at index 2 : ${dll.toArray()}`);

console.log(dll.toString());

console.log(dll.delete(3));

console.log(`After deleting element at index 3 : ${dll.toArray()}`);

console.log(`Is DLL empty : ${dll.isEmpty()}`);

console.log('Head of dll is : ');

console.log(dll.getHead());

console.log('Tail of dll is : ');

console.log(dll.getTail());
