#include <iostream>
#include <time.h>

template <typename T>
class LinkedList{
	public:
		void push(const T& data);
		void display();
		void sortedInsert(const bool& reverse = false);
		void pushfront(const T& data);

	private:
		bool reverse_;
		bool sortInsertInit_ = false;
		void sortedInsertALGO();
		struct node{
			T data;
			node* next;
			node(const T& data): data(data), next(nullptr){}
		};
		node* head_ = nullptr;
};

template <typename T>
void LinkedList<T>::sortedInsert(const bool& reverse){
	/*
	Sorts the list in either order as it inserts new element to the list

	@params: reverse
		false(default) - for Ascending order
		true - for Descending order
	*/
	
	if(this->head_ != nullptr){
		std::cout << "Can only be called before pushing any element to the list" << std::endl;	
		return;
	}

	reverse_ = reverse;
	sortInsertInit_ = true;
}


template <typename T>
void LinkedList<T>::pushfront(const T& data){
	node* n = new node(data);
	n->next = head_;
	head_ = n;
}

template <typename T>
void LinkedList<T>::push(const T& data){
	if(!sortInsertInit_){
		std::cout << "Initialize sortInsert before calling push" << std::endl;
		return;
	}
	node* n = new node(data);
	/*if the list is empty pointer the head pointer to 
	 newly created node */
	if(head_ == nullptr){ 
		head_ = n; 
		return;
	}
	
	node* current = head_;

	if(reverse_){
		if(data >= head_->data){
			n->next = head_;
			head_ = n;
			return;
		}
		while(current->next != nullptr && current->next->data > data){
			current = current->next;
		}
		n->next = current->next;
		current->next = n;
	}
	else{
		if(data <= head_->data){
			n->next = head_;
			head_ = n;
		}
		while(current->next != nullptr && current->next->data < data){
			current = current->next;
		}
		n->next = current->next;
		current->next = n;
	}
}


template <typename T>
void LinkedList<T>::display(){
	node* thru = head_;
	while(thru != nullptr){
		std::cout << thru->data << std::endl;
		thru = thru->next;
	}
}

int main(){
	LinkedList<int> l1, l2;
	srand(time(0));
	l1.sortedInsert(false);
	for(int i=0; i<10; i++){
			int t = rand()%100+1;
			l1.push(t);
	}
	l1.display();
}
