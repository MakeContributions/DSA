
function DoubleLinkedList() {
    const Node = function (element) {
      this.element = element
      this.next = null
      this.prev = null
    }
  
    let length = 0
    let head = new Node('head')
    let tail = head
  
    // Add new element
    this.append = function (element) {
      const node = new Node(element)
  
      node.prev = tail
      tail.next = node
      tail = node
  
  
      length++
    }
  
    // Add element
    this.insert = function (position, element) {
      // Check of out-of-bound values
      if (position >= 0 && position <= length) {
        const node = new Node(element)
        let current = head;
        let index = 0;
  
        while (index < position) {
          current = current.next;
          index++;
        }
        node.next = current.next;
        if (node.next !== null) {
          node.next.prev = node;
        }
        node.prev = current;
        current.next = node;
  
        length++
        return true
      } else {
        return null
      }
    }
  
    // Remove element at any position
    this.removeAt = function (position) {
      // look for out-of-bounds value        
  
      if (position > -1 && position < length) {
  
        let current = head;
        let index = 0;
  
        while (index < position) {
          current = current.next;
          index++;
        }
        if (current.next.next !== null) {
          current.next.next.prev = current
        }
  
        current.next = current.next.next
  
        length--
        return current.element
      } else {
        return null
      }
    }
  
    // Get the indexOf item
    this.indexOf = function (elm) {
      let current = head
      let index = -1
  
      // If element found then return its position
      while (current.next) {
        if (elm === current.next.element) {
          return ++index
        }
  
        index++
        current = current.next
      }
  
      // Else return -1
      return -1
    }
    
    // Delete an item from the list
    this.delete = (elm) => {
      return this.removeAt(this.indexOf(elm))
    }
  
    this.toString = function () {
      let current = head.next
      let string = ''
  
      while (current) {
        string += current.element + ' '
        current = current.next
      }
  
      return string
    }
  
    // Convert list to array
    this.toArray = function () {
      const arr = []
      let current = head.next
  
      while (current) {
        arr.push(current.element)
        current = current.next
      }
  
      return arr
    }
  
    // Check if list is empty
    this.isEmpty = function () {
      return length === 0
    }
  
    // Get the size of the list
    this.size = function () {
      return length
    }
  
    // Get the head
    this.getHead = function () {
      return head.next
    }
  
    // Get the tail
    this.getTail = function () {
      return tail
    }
  }
  
  
  const newDoubleLinkedList = new DoubleLinkedList()
  newDoubleLinkedList.append(5)
  newDoubleLinkedList.append(3)
  newDoubleLinkedList.append(20)
  console.log(newDoubleLinkedList.toString())
    