#include "SLL.h"
#include <stdio.h>
#include <limits.h>

#define FREE(x) do { \
  if ((x) != NULL) { \
    free(x); \
    (x) = NULL; \
  } \
} while (0)

#define SLL_POINTER_IS_NULL puts("\nError: SLL is NULL!\n") 
#define SLL_IS_EMPTY        puts("\nError/Condition: SLL is empty!\n")
#define INVALID_POSITION    puts("\nError: Position is invalid!\n")

Node *newNode (int _data) {
  Node *_newNode = (Node*) malloc(sizeof(Node));
  _newNode->data = _data;
  _newNode->next = NULL;
  return _newNode;
}

void SLL_INIT(SLL *_sll) {
  if(_sll == NULL) {
    SLL_POINTER_IS_NULL;
    return;
  }
  _sll->head = NULL;
  _sll->size = 0; 
}

void SLL_DEST(SLL *_sll) {
  if(_sll == NULL) {
    SLL_POINTER_IS_NULL;
    return;
  }

  if(_sll->size == 0) {
    SLL_IS_EMPTY;
    return;
  } // linked list is not empty

  Node *curr = _sll->head;
  _sll->head = NULL;
  Node *temp = NULL;
  while(curr != NULL) {
    temp = curr;
    curr = curr->next;
    temp->next = NULL;
    FREE(temp);
  } // all nodes deleted
}

// SLL functions 
void InsertAtBeg (SLL *_sll, int _data) {
  if(_sll == NULL) {
    SLL_POINTER_IS_NULL;
    return;
  }

  if(_sll->size == 0) {
    _sll->head = newNode(_data);
    _sll->size++;
    return;
  }

  Node *temp = newNode(_data);
  temp->next = _sll->head;
  _sll->head = temp;
  _sll->size++;
}

void InsertAtEnd (SLL *_sll, int _data) {
  if(_sll == NULL) {
    SLL_POINTER_IS_NULL;
    return;
  }

  if(_sll->size == 0) {
    InsertAtBeg(_sll, _data);
    return;
  }

  Node *curr = _sll->head;
  while(curr->next != NULL) {
    curr = curr->next;
  } curr->next = newNode(_data);
  _sll->size++;
}

void InsertAtPos (SLL *_sll, int _data, int _pos) {
  if(_sll == NULL) {
    SLL_POINTER_IS_NULL;
    return;
  }

  if(_pos < 1 || _pos > _sll->size+1) {
    INVALID_POSITION;
    return;
  }

  if(_pos == 1) {
    InsertAtBeg(_sll, _data);
    return;
  }

  if (_pos == _sll->size + 1) {
    InsertAtEnd(_sll, _data);
    return;
  }   

  // 1 < position <= size
  Node *_newNode = newNode(_data);
  Node *curr = _sll->head;
  int k = 1;
  while(k != _pos-1) {
    curr = curr->next;
    k++;
  } _newNode->next = curr->next;
  curr->next = _newNode;
  _sll->size++;
}

void DeleteAtBeg (SLL *_sll) {
  if(_sll == NULL) {
    SLL_POINTER_IS_NULL;
    return;
  }

  if(_sll->size == 0) {
    SLL_IS_EMPTY;
    return;
  }

  Node *temp = _sll->head;
  _sll->head = _sll->head->next;
  temp->next = NULL;
  FREE(temp);
  _sll->size--;
}

void DeleteAtEnd (SLL *_sll) {
  if(_sll == NULL) {
    SLL_POINTER_IS_NULL;
    return;
  }

  if(_sll->size == 0) {
    SLL_IS_EMPTY;
    return;
  }

  if(_sll->size == 1) {
    DeleteAtBeg(_sll);
    return;
  }

  Node *curr = _sll->head;
  while(curr->next->next != NULL) {
    curr = curr->next;
  } FREE(curr->next);
  _sll->size--;
}

void DeleteAtPos (SLL *_sll, int _pos) {
  if(_sll == NULL) {
    SLL_POINTER_IS_NULL;
    return;
  }

  if(_pos < 1 || _pos > _sll->size) {
    INVALID_POSITION;
    return;
  }

  if(_sll->size == 0) {
    SLL_IS_EMPTY;
    return;
  }

  if(_sll->size == 1) {
    DeleteAtBeg(_sll);
    return;
  }

  if(_pos == _sll->size) {
    DeleteAtEnd(_sll);
    return;
  }

  // 1 < position < size
  Node *curr = _sll->head;
  int k = 1;
  while(k != _pos-1) {
    curr = curr->next;
    k++;
  } Node *temp = curr->next;
  curr->next = curr->next->next;
  temp->next = NULL;
  FREE(temp);
  _sll->size--;
}

int getDataAtPos (SLL *_sll, int _pos) {
  if(_sll == NULL) {
    SLL_POINTER_IS_NULL;
    return -1;
  }

  if(_pos > _sll->size || _pos < 1) {
    INVALID_POSITION;
    return INT_MIN;
  }

  Node *curr = _sll->head;
  int k = 1;
  while(k != _pos) {
    curr = curr->next;
    k++;
  } return curr->data;
}

int size (SLL *_sll) {
  if(_sll == NULL) {
    SLL_POINTER_IS_NULL;
    return -1;
  }

  return _sll->size;
}

void Display (SLL *_sll) {
  if(_sll == NULL) {
    SLL_POINTER_IS_NULL;
    return;
  }

  if(_sll->size == 0) {
    SLL_IS_EMPTY;
    return;
  }

  Node *curr = _sll->head;
  while(curr->next != NULL) {
    printf("%d -> ", curr->data);
    curr = curr->next;
  } printf("%d -> NULL\n\n", curr->data);
}