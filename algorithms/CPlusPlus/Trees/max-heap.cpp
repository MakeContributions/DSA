/*

----Implementation of a Max Heap using priority queue from the STL library----

List of member functions from the STL library for priority queues:
-> empty() - returns whether the queue is empty
-> size() - returns the size of the queue
-> top() - access to the topmost element of the queue with a pointer
-> push() - inserts element
-> emplace() constructs and inserts element
-> pop() - removes the top element
-> swap()- swaps contents
More information on this can be found at https://www.cplusplus.com/reference/queue/priority_queue/
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std; //can also use std with the scope operator :: throughout the code or type "using namespace std::priority_queue" here

void maxHeap() {
    //creating the priority queue
    //using a priority queue as is creates a max heap by default
    std::priority_queue<int> pq;

    // Push your values into the queue (the one's being used here are for testing purposes)
    vector<int> values = {15,26,30,38,55,23,2,4,7,19,44,3,21,12,6}; //a vector of values of size 15

    for(int i=0; i < values.size(); i++) { //going through the array in a for loop and pushing the values onto the priority queue
        pq.push(values[i]);
    }

    // Printing out the size of the queue and the queue itself
    std::cout << "The size of the max-heap is " << pq.size() << endl;

    std::cout << "The elements of the max-heap are:" << endl;
    while(!pq.empty()) {
        std::cout << pq.top() << " "; //accessing the top element then popping it
        pq.pop();
    }
    std::cout << endl;
}

int main() {
    maxHeap();
};
/*the first element should be the highest number added to the queue,
  in a priority queue it will also be from arranged from greatest to least,
  though a max heap's requirement is that it needs the key at the root to be
  the maximum element among all the keys in the tree, and this must be true
  for all the nodes in the tree as well
*/