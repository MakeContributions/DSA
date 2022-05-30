#include <iostream>

template <typename T>
class LinkedList{
	public:
		int size = 0;
		void pushfront(const T& data);
		T& front();	
		void popfront();
		void display();
		void merge(const LinkedList<T>& other);
		LinkedList<T>& operator=(const LinkedList<T>& other);

	private:
		struct node{
			T data;
			node* next;
			node(const T& data): data(data), next(nullptr){}
		};
		node* head_ = nullptr;
};

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other){

	//clearing all node in 'this' list
	while(head_ != nullptr){
		this->popfront();
	}
	node* current = other.head_;
	while(current != nullptr){
		this->pushfront(current->data);
		current = current->next;
	}
	return *this;
}

template <typename T>
T& LinkedList<T>::front(){
	//returns the first node data of the linked list

	return head_->data;
}

template <typename T>
void LinkedList<T>::popfront(){
	//sets the head pointer to nullptr and the next node as the new head
	
	//if there is no node then do nothing
	if(head_ == nullptr) return;
	if(head_->next == nullptr){
		delete head_;	
		head_ = nullptr;
		--size;
		return;
	}
	node* oldhead = head_;
	head_ = head_->next;
	delete oldhead;
	oldhead = nullptr;
	size--;
}

template <typename T>
void LinkedList<T>::pushfront(const T& data){
	node* n = new node(data);
	/*if the list is empty pointer the head pointer to 
	 newly created node */
	if(head_ == nullptr){ head_ = n; }
	else{
		n->next = head_;
		head_ = n;
	}
	size++;
}


template <typename T>
void LinkedList<T>::display(){
	node* thru = head_;
	while(thru != nullptr){
		std::cout << thru->data << std::endl;
		thru = thru->next;
	}
}

template <typename T>
void LinkedList<T>::merge(const LinkedList<T>& other) {
	LinkedList<T> l1 ;
	l1 = other;
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
	
	std::cout << "AFTER MERGE" << std::endl;
	std::cout << "LIST 1" << std::endl;
	l1.display();
	std::cout << "LIST 2" << std::endl;
	l2.display();
}
