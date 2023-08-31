
// Singly Linked List Implementation as a header file
//------------------------------------------------------
#ifndef SLL_H_
#define SLL_H_

typedef struct Node Node;
typedef struct SLL SLL;

struct Node {
  int data;
  Node *next;
};

struct SLL {
  Node *head;
  int size;
};

Node *newNode (int _data);

// Initialisation and destruction
void SLL_INIT(SLL *_sll);
void SLL_DEST(SLL *_sll);

// SLL functions 
void InsertAtBeg (SLL *_sll, int _data);
void InsertAtEnd (SLL *_sll, int _data);
void InsertAtPos (SLL *_sll, int _data, int _pos);

void DeleteAtBeg (SLL *_sll);
void DeleteAtEnd (SLL *_sll);
void DeleteAtPos (SLL *_sll, int _pos);

int getDataAtPos (SLL *_sll, int _pos);
int size (SLL *_sll);
void Display (SLL *_sll);

#endif
//------------------------------------------------------