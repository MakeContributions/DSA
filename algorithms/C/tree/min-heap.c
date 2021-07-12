/*
Min-Heap is a binary tree structure such that every node in the tree will be
lesser or equal to the child node. It is used when you need quick access to
the smallest number in the array.

Time complexity to build the heap: O(n)
Time complexity to remove min: O(log(n))
Time complexity to remove all elements: O(n*log(n))
*/

#include <stdio.h>

#include <stdlib.h>

struct HEAP {
  int * items, size, capacity;
}* heap;

void swap(int * a, int * b) {
  int temp = * b;
  * b = * a;
  * a = temp;
}

void init(struct HEAP ** heap) {
  * heap = (struct HEAP * ) malloc(sizeof(struct HEAP));
  ( * heap) -> capacity = 2;
  ( * heap) -> size = 0;
  ( * heap) -> items = (int * ) malloc(sizeof(int) * ( * heap) -> capacity + 1);
}

void allocate(struct HEAP ** heap) {
  ( * heap) -> capacity *= 2;
  ( * heap) -> items = (int * ) realloc(( * heap) -> items, sizeof(int) * ( * heap) -> capacity + 1);
}

void heapify_up(struct HEAP ** heap, int size) {
  if (size > 1) {
    if (( * heap) -> items[size / 2] > ( * heap) -> items[size]) {
      swap( & ( * heap) -> items[size / 2], & ( * heap) -> items[size]);
      heapify_up(heap, size / 2);
    }
  }
}

void insert(struct HEAP ** heap, int val) {
  if (( * heap) -> size == ( * heap) -> capacity) {
    allocate(heap);
  }
  ( * heap) -> items[++( * heap) -> size] = val;
  heapify_up(heap, ( * heap) -> size);
}

int child(struct HEAP * heap, int index) {
  int left = index * 2;
  int right = index * 2 + 1;

  if (right > heap -> size) {
    return left;
  } else if (heap -> items[left] <= heap -> items[right]) {
    return left;
  }
  return right;
}

void heapify_down(struct HEAP ** heap, int index) {
  int childindex = child( * heap, index);
  if (index * 2 <= ( * heap) -> size) {
    if (( * heap) -> items[index] > ( * heap) -> items[childindex]) {
      swap( & ( * heap) -> items[index], & ( * heap) -> items[childindex]);
      heapify_down(heap, childindex);
    }
  }
}

void removemin(struct HEAP ** heap) {
  swap( & ( * heap) -> items[1], & ( * heap) -> items[( * heap) -> size--]);
  heapify_down(heap, 1);
}

void print(struct HEAP * heap) {
  for (int i = 1; i <= heap -> size; i++) {
    printf("%i ", heap -> items[i]);
  }
  printf("\n");
}

void deallocate(struct HEAP ** heap) {
  free(( * heap) -> items);
  free( * heap);
}

int main(void) {
  init( & heap);

  insert( & heap, 4);
  insert( & heap, 10);
  insert( & heap, 2);
  insert( & heap, 22);
  insert( & heap, 45);
  insert( & heap, 18);

  // Before removemin
  print(heap);

  removemin( & heap);

  // After removemin
  print(heap);
  /*
  	(before removemin)Output:2 10 4 22 45 18
  	(after removemin)Output: 4 10 18 22 45
  */

  deallocate( & heap);

  return 0;
}
