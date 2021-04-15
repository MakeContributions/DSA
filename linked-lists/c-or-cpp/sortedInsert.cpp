#include <iostream>
#include <time.h>

template <typename T>
class LinkedList{
	public:
		void push(const T& data);
		void display();
		void sortedInsert(const bool& reverse = false);

	private:
		bool reverse_;
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
		std::cout << "Can only be used when the list is empty" << std::endl;	
		return;
	}

	reverse_ = reverse;
}

template <typename T>
void LinkedList<T>::push(const T& data){
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
	l1.sortedInsert(true);
	srand(time(0));
	for(int i=0; i<10; i++){
			int t = rand()%100+1;
			l1.push(t);
	}
	l1.display();
}
