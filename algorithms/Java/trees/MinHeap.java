/*
Min-Heap is a binary tree structure such that every node in the tree will be
lesser or equal to the child node. It is used when you need quick access to
the smallest number in the array.
Time complexity to build the heap: O(n)
Time complexity to remove min: O(log(n))
Time complexity to remove all elements: O(n*log(n))
*/

import java.util.ArrayList;
import java.util.Collections;
import java.util.stream.Collectors;

public class MinHeap<T extends Comparable<? super T>> {

    // Example of MinHeap usage
    public static void main(String[] args) {
        MinHeap<Integer> myHeap = new MinHeap<>();

        // adding elements to the heap
        myHeap.insert(4);
        myHeap.insert(10);
        myHeap.insert(2);
        myHeap.insert(22);
        myHeap.insert(45);
        myHeap.insert(18);

        System.out.println(myHeap);
        // output: 2, 10, 4, 22, 45, 18

        myHeap.removeMin();
        System.out.println(myHeap);
        // output: 4, 10, 18, 22, 45

        myHeap.removeMin();
        System.out.println(myHeap);
        // output: 10, 22, 18, 45

        myHeap.removeMin();
        System.out.println(myHeap);
        // output: 18, 22, 45

        myHeap.removeMin();
        System.out.println(myHeap);
        // output: 22, 45

        myHeap.removeMin();
        System.out.println(myHeap);
        // output: 45

        myHeap.removeMin();
        System.out.println(myHeap);
        // output: 
        // (empty output)

    }

    // Array representing the binary tree,
    // where the first element is the smallest element and the root
    ArrayList<T> items;

    public MinHeap() {
        this.items = new ArrayList<>();
    }

    /*
    takes index of the node as argument,
    and returns the index of its parent.
    Returns -1 if the element is a root.
     */
    public int getIndexOfParent(int index) {
        return (index == 0) ? -1 : (index - 1) / 2;

    }

    /*
    Takes index of the node as argument,
    and returns the index of its first child.
    The index of its second child is greater by one
    than the index of the first child.
    Returns -1 if the element at given index has no children
     */
    public int getIndexOfFirstChild(int index) {
        int result = (index * 2) + 1;
        return (result >= items.size()) ? -1 : result;
    }

    /* swaps the element at given index with the its parent
    until the order of the heap is restored (the parent is smaller or equal)
    */
    public void siftUp(int index) {
        if (index == 0) return;
        T element = items.get(index);
        int indexOfParent = getIndexOfParent(index);
        while (indexOfParent != -1 && items.get(indexOfParent).compareTo(element) > 0) {
            Collections.swap(items, index, indexOfParent);
            index = indexOfParent;
            indexOfParent = getIndexOfParent(index);
        }
    }

    /* swaps the element at given index with the smallest of its children
    until the order of the heap is restored (both children are greater or equal)
     */
    public void siftDown(int index) {
        int firstChildIndex = getIndexOfFirstChild(index);
        int secondChildIndex = firstChildIndex + 1;
        T element = items.get(index);

        /*  minIndex is the index of the smallest child

            minIndex is the index of the first child, if the element doesn't
            have children (so firstChildIndex=-1), or if the element only has one
            child, or if the first child is smaller than the second child.

            minIndex is the index of the second child, if the second child
            is smaller than the first child. */
        int minIndex = (firstChildIndex != -1 &&
                secondChildIndex < items.size() && items.get(firstChildIndex).compareTo(
                items.get(secondChildIndex)) > 0) ?
                secondChildIndex : firstChildIndex;
        while (minIndex != -1 && element.compareTo(items.get(minIndex)) > 0) {
            Collections.swap(items, minIndex, index);
            index = minIndex;
            firstChildIndex = getIndexOfFirstChild(index);
            secondChildIndex = firstChildIndex + 1;

            /* see above for explanation of minIndex */
            minIndex = (firstChildIndex != -1 &&
                    secondChildIndex < items.size() && items.get(firstChildIndex).compareTo(
                    items.get(secondChildIndex)) > 0) ?
                    secondChildIndex : firstChildIndex;
        }
    }

    /* Insert an element into the heap, preserving the correct order
    of elements (children of a node have to be greater or equal to the node) */
    public void insert(T element) {
        items.add(element);
        siftUp(items.size() - 1);
    }

    /* Remove the smallest element and return it.
    The smallest element in a MinHeap
    is always the root.
    Correct order of elements has to be restored after removing the root.
     */
    public T removeMin() {
        if (items.isEmpty()) throw new IllegalStateException(
                "Cannot remove an element from an empty heap!");

        T result = items.get(0); //smallest element

        //If the heap only has one element, no reordering needed after removing
        if (items.size()==1) {
            items.remove(0);
            return result;
        }
        Collections.swap(items, 0, items.size() - 1);
        items.remove(items.size() - 1);
        siftDown(0);
        return result;
    }

    public T getMin() {
        return items.get(0);
    }

    /* Print the elements in the heap in the order they are stored
    separated by , */
    @Override
    public String toString() {
        return items.stream().map(Object::toString)
                .collect(Collectors.joining(", "));
    }

}
