#include "ArrayLinkedList.h"
#include <iostream>

using namespace std ;

ArrayLinkedList::ArrayLinkedList(int length_) {
	length = length_ ;
	head = new Node(0,-1) ;

}

Node* ArrayLinkedList::get_node(int index_, bool wantCreate){

	Node* prev = head ;
	while(prev->next && prev->next->index < index_){
          prev = prev->next ;
	}
	bool exist = prev->next && prev->next->index == index_ ;

	if(exist)
          return prev->next ;
     if(!wantCreate)
          return 0 ;

     Node* item = new Node(0,index_) ;
     item->next = prev->next ;
     prev->next = item ;

     return item ;
}

void ArrayLinkedList::set_value(int index_, int data_){

     get_node(index_, true)->data = data_ ;
}

void ArrayLinkedList::printNonZero(){

     Node* curr = head->next ;
     while(curr){
          cout << curr->data << " " ;
          curr = curr->next ;
     }
     cout << endl ;
}

int ArrayLinkedList::get_index(int index_){
     Node* res = get_node(index_,false) ;

     if(!res)
          return 0 ;
     return res->data ;
}


void ArrayLinkedList::printAll(){

     Node* curr = head->next ;

     for(int i=0; i<length; i++){ // zero index
          if(curr && i == curr->index){
               cout << curr->data << " " ;
               curr = curr->next ;
          }
          else{
               cout << 0 << " " ;
          }
     }
     cout << endl ;

}


void ArrayLinkedList::add(ArrayLinkedList &another){

     try{
          if(this->length != another.length){
               throw invalid_argument("The length of 2-arrays not EQUAL!! ") ;
          }
     }catch(exception &e){
          cout << endl << e.what() ;
          throw e ;
     }

     Node* curr_another = another.head->next ;
     Node* curr = head->next ;

     for(int i=0; i<length; i++){
          if(curr && curr->index == i){
               if(curr_another && curr_another->index == i){
                    cout << curr_another->data + curr->data << " " ;
                    curr_another = curr_another->next ;
               }
               else{
                    cout << curr->data << " " ;
               }
               curr = curr->next ;
          }
          else if(curr_another && curr_another->index == i){
               cout << curr_another->data << " " ;
               curr_another = curr_another->next ;
          }
          else{
               cout << 0 << " " ;
          }
     }

     cout << endl ;
}


