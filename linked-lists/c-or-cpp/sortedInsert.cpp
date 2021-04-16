#include <iostream>
#include <ctime>

template <typename T>
class LinkedList{
	public:
		void push(const T& data);
		void display();
		void pushfront(const T& data);
		bool sortInsertRev = false;

	private:
		struct node{
			T data;
			node* next;
			node(const T& data): data(data), next(nullptr){}
		};
		node* head_ = nullptr;
};


template <typename T>
void LinkedList<T>::pushfront(const T& data){
	node* n = new node(data);
	n->next = head_;
	head_ = n;
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

	if(!sortInsertRev){
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
	l1.sortInsertRev = true;
	for(int i=0; i<10; i++){
			int t = rand()%100+1;
			l1.push(t);
	}
	l1.display();
}
