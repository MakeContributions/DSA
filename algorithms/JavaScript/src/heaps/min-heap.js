
// A binary heap is a partially ordered binary tree
// that satisfies the heap property.
// The heap property specifies a relationship between parent and child nodes.
// In a min heap, all child nodes are larger than
// or equal to their parent nodes.
// Heaps are represented using arrays because
// it is faster to determine elements position and it needs
// less memory space as we don't need to maintain references to child nodes.
// An example:
// consider this min heap: [null, 0, 3, 1, 10, 35, 25, 47, 15].
// The root node is the first element 0. its children are 3 and 1.
// The general indexes formula for an element of index i are:
// the parent is at: Math.floor(i / 2)
// the left child is at:  i * 2
// the right child is at:  i * 2  + 1

const isDefined = (value) => value !== undefined && value !== null;

class MinHeap {
  constructor() {
    this.heap = [null];
  }

  // Insert a new element  method
  // this is a recursive method, the algorithm is:
  //  1. Add the new element to the end of the array.
  //  2. If the element is less large than its parent, switch them.
  //  3. Continue switching until the new element is either
  // larger than its parent or you reach the root of the tree.

  insert(value) {
    // add the new element to the end of the array
    this.heap.push(value);
    const place = (index) => {
      const parentIndex = Math.floor(index / 2);
      if (parentIndex <= 0) return;
      if (this.heap[index] < this.heap[parentIndex]) {
        // the switch is made here
        [this.heap[parentIndex], this.heap[index]] = [
          this.heap[index],
          this.heap[parentIndex],
        ];
        place(parentIndex);
      }
    };
    // we begin the tests from the new element we added
    place(this.heap.length - 1);
  };

  // Print heap content method
  print() {
    return this.heap;
  };

  // Remove an element from the heap
  // it's also a recursive method, the algorithm will reestablish
  // the heap property after removing the root:
  // 1. Move the last element in the heap into the root position.
  // 2. If either child of the root is less large than it,
  // swap the root with the child of the least large value.
  // 3. Continue swapping until the parent is less great than both
  // children or you reach the last level in the tree.

  remove() {
    // save the root value element because this method will return it
    const removed = this.heap[1];
    // the last element of the array is moved to the root position
    this.heap[1] = this.heap[this.heap.length - 1];
    // the last element is removed from the array
    this.heap.splice(this.heap.length - 1, 1);

    const place = (index) => {
      if (index === this.heap.length - 1) return;
      const child1Index = 2 * index;
      const child2Index = child1Index + 1;
      const child1 = this.heap[child1Index];
      const child2 = this.heap[child2Index];
      let newIndex = index;
      // if the parent is greater than its two children
      // then the heap property is respected
      if (
        (!isDefined(child1) || this.heap[newIndex] <= child1) &&
        (!isDefined(child2) || this.heap[newIndex] <= child2)
      ) {
        return;
      }
      // test if the parent is larger than its left child
      if (isDefined(child1) && this.heap[newIndex] > child1) {
        newIndex = child1Index;
      }
      // test if the parent is larger than its right child
      if (isDefined(child2) && this.heap[newIndex] > child2) {
        newIndex = child2Index;
      }
      // the parent is switched with the child of the least value
      if (index !== newIndex) {
        [this.heap[index], this.heap[newIndex]] = [
          this.heap[newIndex],
          this.heap[index],
        ];
        place(newIndex);
      }
    };
    // start tests from the beginning of the array
    place(1);
    return removed;
  };

  // Sort an array using a min heap
  // the elements of the array to sort were previously added one by one
  // to the heap using the insert method
  // the sorted array is the result of removing the heap's elements one by one
  // using the remove method until it is empty
  sort() {
    const arr = [];
    while (this.heap.length > 1) {
      arr.push(this.remove());
    }
    return arr;
  };
  // Verify the heap property of a given max heap
  verifyHeap() {
    const explore = (index) => {
      if (index === this.heap.length - 1) return true;
      const child1Index = 2 * index;
      const child2Index = 2 * index + 1;
      const child1 = this.heap[child1Index];
      const child2 = this.heap[child2Index];
      return (
        (!isDefined(child1) ||
          (this.heap[index] <= child1 && explore(child1Index))) &&
        (!isDefined(child2) ||
          (this.heap[index] <= child2 && explore(child2Index)))
      );
    };
    return explore(1);
  };
}

const test = new MinHeap();
test.insert(1);
test.insert(3);
test.insert(0);
test.insert(10);
test.insert(35);
test.insert(25);
test.insert(47);
test.insert(15);
// display heap elements
console.log(test.print());
// verify heap property
console.log(test.verifyHeap());
// display the sorted array
console.log(test.sort());
