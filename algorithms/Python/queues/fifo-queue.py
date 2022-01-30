class FIFOqueue:

    def __init__(self, item = 0) -> None:
        """
        creates the FIFOqueue object given an item,
        will default to 0 if no item is passed.

        firstNum: any
        """
        self.arr = [item]
        

    def enqueue(self, n) -> None:
        """
        adds n to the end of the queue in O(1) time

        n: Any
        """
        self.arr.append(n)

    def dequeue(self):
        """
        removes the first element from the queue and returns it in O(1) time
        """
        return self.arr.pop(0)
    
    def front(self):
        """
        returns the first element of the queue in O(1) time
        """
        return self.arr[0]
    
    def rear(self):
        """
        returns the last element of the queue in O(1) time
        """
        return self.arr[-1]

# main
if __name__ == '__main__':
    exampleFIFO = FIFOqueue(1)
    # now our queue should look like [1] after initialization
    print(f"queue after initialization: {exampleFIFO.arr}")

    exampleFIFO.enqueue(5)
    # now our queue should look like [1, 5]
    print(f"queue after enqueueing 5: {exampleFIFO.arr}")

    print(f"If we dequeue, we are removing {exampleFIFO.dequeue()} from the queue")
    # now our queue should look like [5]
    print(f"queue after dequeue: {exampleFIFO.arr}")

    exampleFIFO.enqueue(7)
    # now our queue should look like [5, 7]
    print(f"queue after enqueueing 7: {exampleFIFO.arr}")

    exampleFIFO.enqueue(8)
    # now our queue should look like [5, 7, 8]
    print(f"queue after enqueueing 8: {exampleFIFO.arr}")

    # front
    print(f"If we try looking at the front of the queue we get: {exampleFIFO.front()}")

    #rear
    print(f"If we try looking at the rear of the queue we get: {exampleFIFO.rear()}")