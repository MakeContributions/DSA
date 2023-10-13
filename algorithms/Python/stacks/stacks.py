class Stack:
    def __init__(self):
        self.stack_list = []
        self.stack_size = 0
    def is_empty(self):
        return self.stack_size == 0
    def peek(self):
        if self.is_empty():
            return None
        return self.stack_list[-1]
    def size(self):
        return self.stack_size
    def push(self, value):
        self.stack_size += 1
        self.stack_list.append(value)
    def pop(self):
        if self.is_empty():
            return None
        self.stack_size -= 1
        return self.stack_list.pop()
if __name__ == "__main__":
    stack_obj = Stack()
    limit = 5
    print("Pushing elements into the stack")
    for i in range(limit):
        print(i)
        stack_obj.push(i)
    print("is_empty(): " + str(stack_obj.is_empty()))
    print("peek(): " + str(stack_obj.peek()))
    print("size(): " + str(stack_obj.size()))
    print("Popping elements from the stack")
    for x in range(limit):
        print(stack_obj.pop())
    print("is_empty():"  + str(stack_obj.is_empty()))
    print("peek(): " + str(stack_obj.peek()))
    print("size(): " + str(stack_obj.size()))