using NUnit.Framework;
using System.Collections.Generic;

namespace Algorithms.Tests.Queues
{
    [TestFixture]
    class QueueImplementationUsingTwoStacks
    {
        [Test]
        public void TestQueueUsingTwoStacks1_ShouldGetExpectedResult()
        {
            Algorithms.Queues.QueueImplementationUsingTwoStacks.MyQueue<int> myQueue;
            myQueue = new Algorithms.Queues.QueueImplementationUsingTwoStacks.MyQueue<int>();

            List<int> result = new List<int>();

            myQueue.Push(7);
            result.Add(myQueue.Peek());
            result.Add(myQueue.Count());

            myQueue.Push(118);
            result.Add(myQueue.Count());
            result.Add(myQueue.Peek());

            myQueue.Push(107);
            result.Add(myQueue.Count());
            result.Add(myQueue.Peek());

            myQueue.Pop();
            result.Add(myQueue.Peek());
            result.Add(myQueue.Count());

            myQueue.Pop();
            result.Add(myQueue.Peek());
            result.Add(myQueue.Count());

            myQueue.Pop();
            result.Add(myQueue.Count());

            Assert.AreEqual("7 1 2 7 3 7 118 2 107 1 0", string.Join(" ", result));
        }
    }
}
