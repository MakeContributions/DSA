/*
A doubly linked list is a linked data structure that consists of 
a set of sequentially linked records called nodes. 
Each node contains three fields: two link fields 
(references to the previous and to the next node in the sequence of nodes) 
and one data field.
*/

#include <stdio.h>
#include <stdlib.h>

#define HEAD(x) (x->head)
#define TAIL(x) (x->tail)
#define INC_NODE_COUNT(x) (x->count++)
#define DEC_NODE_COUNT(x) (x->count--)
#define SIZE(x) (x->count)

typedef struct node_{
	int val;
	struct node_* next;
	struct node_* prev;
}node;

typedef struct{
	unsigned int count;
	node* head;
	node* tail;
}dll;

void init(dll* list){
	list->count = 0;
	list->head = NULL;
	list->tail = NULL;
}

node* createnode(int val){
	node* n = (node*)malloc(sizeof(node));
	n->val = val;
	return n;
}

void push_front(dll* list, int val){
	node* new = createnode(val);
	node* cur = HEAD(list);
	INC_NODE_COUNT(list);
	if(cur == NULL){
		HEAD(list) = new;
		TAIL(list) = new;
		return;
	}
	cur->prev = new;
	new->next = cur;
	list->head = new;
}

void push_back(dll* list, int val){
	node* new = createnode(val);
	node* cur = TAIL(list);
	INC_NODE_COUNT(list);
	if(cur == NULL){
		HEAD(list) = new;
		TAIL(list) = new;
		return;
	}
	cur->next = new;
	new->prev = cur;
	list->tail = new;
}

int pop_front(dll* list){
	if(HEAD(list) == NULL){
		return -1;
	}
	node* cur = HEAD(list);
	int val = cur->val;
	HEAD(list) = HEAD(list)->next;
	free(cur);
	cur = NULL;
	HEAD(list)->prev = NULL;
	DEC_NODE_COUNT(list);
	return val;
}

int pop_back(dll* list){
	if(TAIL(list) == NULL){
		return -1;
	}
	node* cur = TAIL(list);
	int val = cur->val;
	TAIL(list) = TAIL(list)->prev;
	free(cur);
	cur = NULL;
	TAIL(list)->next = NULL;
	DEC_NODE_COUNT(list);
	return val;
}

void delete(dll* list){
	if(HEAD(list) == NULL){
		return;
	}
	node* cur = HEAD(list);
	node* temp = NULL;
	while(cur != NULL){
		temp = cur->next;
		free(cur);
		cur = NULL;
		cur = temp;
	}
	SIZE(list) = 0;
}

void print(dll* list){
	node* cur = list->head;
	while(NULL != cur){
		printf("%i ", cur->val);
		cur = cur->next;
	}
}

int main(){
	dll* list = (dll*)malloc(sizeof(dll));
	init(list);

	push_front(list, 3);
	push_front(list, 2);
	push_front(list, 1);

	push_back(list, 4);
	push_back(list, 5);
	push_back(list, 6);

	pop_front(list);
	pop_back(list);

	print(list);

	delete(list);
	
	/*
	
	Time Complexity
	---------------
	push_front: O(1)
	push_back: O(1)
	pop_front: O(1)
	pop_back: O(1)
	delete: O(N)
	
	*/
	
	return 0;
}
