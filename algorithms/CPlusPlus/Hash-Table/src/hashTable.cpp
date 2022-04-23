#include "hashTable.h"

#include "Node.h"
#include <iostream>

using namespace std ;

hashTable::hashTable(int length_, double limitLoadFactor){
     length = length_ ;
     loadFactor = limitLoadFactor ;
     contacts.resize(length_) ;
     contactsOfLinkedlist.resize(length_) ;
     actual_len = 0 ;
}

void hashTable::add(entity contact){
     int ind = contact.hash_upper_lower_digit(contact.getName(),65407)%length ;

     for(int i=0 ; i<(int)contacts[ind].size() ; i++){
          if(contacts[ind][i].getName() == contact.getName()){
               contacts[ind][i] = contact ;
               return;
          }
     }
     actual_len++ ;
     double ratio = (double)actual_len/length ;
     cout << "Current load factor : " << ratio << '\n' ;
     if(ratio >= loadFactor){
    	 rehash() ;
     }
     contacts[ind].push_back(contact) ;
}

void hashTable::addLinkedlist(entity contact){
    int ind = contact.hash_upper_lower_digit(contact.getName(),65407)%length ;
    Node* curr = contactsOfLinkedlist[ind] ;
    Node* prev = 0 ;

    if(!curr){
    	contactsOfLinkedlist[ind] = new Node(contact) ;
    	return;
    }
   	while(curr){
   		if(curr->data.getName() == contact.getName()){
   			curr->data = contact ;
   			return;
   		}
   		prev = curr ;
    	curr = curr->next ;
   	}
   	Node *contactNode = new Node(contact) ;
   	prev->next = contactNode ;
   	contactNode->next = 0 ;
}

void hashTable::printallLinkedlist(){
	cout << "Hash Table :- " << '\n' ;
	for(int i=0; i<(int)contactsOfLinkedlist.size(); i++){
		if(!contactsOfLinkedlist[i])
			continue ;
		cout << "Hash index : " << i << ":  "  ;
		Node* curr = contactsOfLinkedlist[i] ;
		while(curr){
			curr->data.print() ;
			curr = curr->next ;
		}
		cout << '\n' ;
	}
}


bool hashTable::Is_removed(entity contact){
     int ind = contact.hash_upper_lower_digit(contact.getName(),65407)%length ;
     for(int j=0; (int)j<(int)contacts[ind].size(); j++){
          if(contact.getName() == contacts[ind][j].getName()){
               swap(contacts[ind][j], contacts[ind].back()) ;
               contacts[ind].pop_back() ;
               return true ;
          }
     }
     return false ;
}

void hashTable::remove(entity contact){
     if(!Is_removed(contact))
          cout << "There is no contact called " << contact.getName() << ", Please Choose Add" << endl ;
     else actual_len-- ;
}


void hashTable::printall(){
     cout << "Hash Table :-" << '\n' ;
     for(int i=0 ; i<length; i++){
          if(!(int)contacts[i].size())
               continue ;

          cout << "Hash index : " << i << "   :" ;
          for(int j=0 ; j<(int)contacts[i].size(); j++){
               contacts[i][j].print() ;
          }
          cout << '\n' ;
     }
}

void hashTable::getentity(entity &contact){
     int ind = contact.hash_upper_lower_digit(contact.getName(),65407)%length ;
     for(int i=0; i<(int)contacts[ind].size(); i++){
          if(contact.getName() == contacts[ind][i].getName()){
        	  contact.setNameNumber(contacts[ind][i].getName(), contacts[ind][i].getNumber()) ;
        	  return ;
          }
     }
     cout << "There is no entity with given name " << contact.getName() ;
}


void hashTable::rehash(){

	cout << "\nRehashing stratring now....\n" ;

	vector< vector<entity> > temp ;
	temp.assign(contacts.begin(), contacts.end()) ;
	contacts.clear() ;
	contacts.resize(2*length);
	this->length *= 2 ;
	this->actual_len = 0 ;


	for(int i=0; i<(int)temp.size(); i++){
		for(int j=0; j<(int)temp[i].size(); j++){
			entity item(temp[i][j].getName(), temp[i][j].getNumber()) ;
			add(item) ;
		}
	}

	printall() ;
}


