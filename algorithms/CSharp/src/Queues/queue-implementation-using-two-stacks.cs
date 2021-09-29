using System;
using System.Collections.Generic;

namespace Algorithms.Queues
{
    public class QueueImplementationUsingTwoStacks
    {
        public class MyQueue<T>
        {
            private Stack<T> _stack1, _stack2;
            
            public MyQueue()
            {
                _stack1 = new Stack<T>();
                _stack2 = new Stack<T>();
            }

            public void Push(T x)
            {
                _stack1.Push(x);
            }

            public T Pop()
            {
                if (Empty())
                {
                    throw new InvalidOperationException();
                }

                if(_stack2.Count > 0)
                {
                    return _stack2.Pop();
                }

                while(_stack1.Count > 0)
                {
                    _stack2.Push(_stack1.Pop());
                }

                return _stack2.Pop();
            }

            public T Peek()
            {
                if (Empty())
                {
                    throw new InvalidOperationException();
                }

                if (_stack2.Count > 0)
                {
                    return _stack2.Peek();
                }

                while (_stack1.Count > 0)
                {
                    _stack2.Push(_stack1.Pop());
                }

                return _stack2.Peek();
            }

            public bool Empty()
            {
                return _stack1.Count == 0 && _stack2.Count == 0;
            }

            public int Count()
            {
                return _stack1.Count + _stack2.Count;
            }
        }

        public static void Main()
        {
            MyQueue<int> myQueue = new MyQueue<int>();
            
            myQueue.Push(3);
            myQueue.Push(4);
            Console.Write($"{myQueue.Peek()} ");
            myQueue.Pop();
            Console.Write($"{myQueue.Peek()} ");
            myQueue.Push(7);
            Console.Write($"{myQueue.Peek()} ");
        }
    }
}
