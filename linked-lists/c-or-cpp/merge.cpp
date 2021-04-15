#include <iostream>

template <typename T>
class LinkedList{
	public:
		int size = 0;
		void pushfront(const T& data);
		T& front();	
		void popfront();
		void display();
		void merge(const LinkedList<T>& list2) ;

	private:
		struct node{
			T data;
			node* next;
			node(const T& data): data(data), next(nullptr){}
		};
		node* _head = nullptr;
};

template <typename T>
T& LinkedList<T>::front(){
	//returns the first node data of the linked list

	return _head->data;
}

template <typename T>
void LinkedList<T>::popfront(){
	/*
		sets the head pointer to nullptr
		and the next node as the new head
	*/
	//if there is no node then do nothing
	if(_head == nullptr) return;
	if(_head->next == nullptr){
		_head = nullptr;
		#delete _head;
		--size;
		return;
	}
	node* oldhead = _head;
	_head = _head->next;
	#delete oldhead;
	oldhead = nullptr;
	size--;
}

template <typename T>
void LinkedList<T>::pushfront(const T& data){
	node* n = new node(data);

	/*if the list is empty pointer the head pointer to 
	 newly created node */
	if(_head == nullptr){
		_head = n;
	}
	else{
		n->next = _head;
		_head = n;
	}
	size++;
}


template <typename T>
void LinkedList<T>::display(){
	node* thru = _head;
	while(thru != nullptr){
		std::cout << thru->data << std::endl;
		thru = thru->next;
	}
}

template <typename T>
void LinkedList<T>::merge(const LinkedList<T>& other) {
	LinkedList<T> l1 = other;
	while(l1.size > 0){
		//inserting the data of the other list to the current list
		this->pushfront(l1.front());
		//removing the first node of the list
		//this will continue until there is no more node in the other list
		l1.popfront();
	}
}

int main(){
	LinkedList<int> l1, l2;

	l1.pushfront(1);
	l1.pushfront(2);
	l1.pushfront(3);
	l2.pushfront(21);
	l2.pushfront(11);
	l2.pushfront(31);

	l2.merge(l1);

	l1.display();
	std::cout << "####################" << std::endl;
	l2.display();
	
}
