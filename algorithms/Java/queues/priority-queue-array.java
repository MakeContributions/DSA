// Class implementation of Priority-Queue using an array

import java.util.*;


class PriorityQueue {      
	private int max_size;     // To provide maximum size of Array
	private int[] arr;
	private int no_items;

	public PriorityQueue(int s){
		max_size = s;
		arr = new int[max_size];
		no_items = 0;
	}

	public void insert(int val){   //Method to insert element into Priority Queue

		int j;
		if (no_items == 0){
			arr[no_items++] = val;
		}
		else {

			for ( j=no_items-1;j>=0;j--){

				if (val<arr[j])    // To get in ascending order change to '>' operator
				{
					arr[j+1] = arr[j];
				}
				else break;

			}

			arr[j+1] = val;
			no_items++;
		}

	}
	public void remove(){      // Method to remove front element in Priority Queue
		--no_items;
	}

	public int front(){          // Method to retrieve front element
		return arr[no_items-1];
	}

	public boolean isEmpty() {   // Method to check if queue is empty
		return no_items == 0;
	}
	public boolean isFull() {    // Method to check if queue is full
		return no_items == max_size;
	}


}

class Main {   // Class containing main method.

	public static void main(String[] args) {
		PriorityQueue pq = new PriorityQueue(5);
		pq.insert(23);                     // [23]
		pq.insert(56);                     // [56,23]
		pq.insert(25);                     // [56,25,23]
		System.out.println(pq.front());    // 56
		pq.remove();                       // [25,23]
		System.out.println(pq.front());    // 25
		System.out.println(pq.isEmpty());  // False
		pq.insert(100);                    // [100,25,23]
		pq.insert(98);                     // [100,98,25,23]
		pq.insert(99);                     // [100,99,98,25,23]
		System.out.println(pq.front());    // 100
		System.out.println(pq.isFull());   // True

		
	}

}
