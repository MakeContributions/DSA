#ifndef ARRAYLINKEDLIST_H_
#define ARRAYLINKEDLIST_H_
#include "Node.h"

class ArrayLinkedList {
private:
	int length ;
	Node* head ;

	Node* get_node(int index_, bool wantCreat) ;

public:
	ArrayLinkedList(int length_) ;
	void set_value(int index, int data) ;
	void printNonZero() ;
	int get_index(int index) ;
	void printAll() ;
	void add(ArrayLinkedList &another) ;
};

#endif /* ARRAYLINKEDLIST_H_ */


