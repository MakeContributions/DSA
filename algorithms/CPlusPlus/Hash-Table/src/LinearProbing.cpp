#include "entity.h"
#include "LinearProbing.h"
#include <iostream>
#include <string>

LinearProbing::LinearProbing(int length_) {
	actual_length = 0 ;
	length = length_ ;
	contacts.resize(length_) ;
	deletedEntity = new entity("",-1) ;
}

void LinearProbing::add(entity contact){
    int ind = contact.hash_upper_lower_digit(contact.getName(),65407)%length ;
    for(int i=0; i<(int)contacts.size(); i++){
    	if(contacts[ind] == deletedEntity || !contacts[ind]){
    		contacts[ind] = new entity(contact.getName(),contact.getNumber()) ;
    		return;
    	}
    	else if(contact.getName() == contacts[ind]->getName()){
    		contacts[ind]->setNameNumber(contact.getName(),contact.getNumber()) ;
    		actual_length++ ;
    		return;
    	}
    	ind = (ind+1)%length ;
    }
    cout << "Can't add it, cause there is no an empty cell. \n" ;

}

void LinearProbing::remove(entity contact){
    int ind = contact.hash_upper_lower_digit(contact.getName(),65407)%length ;
    for(int i=0; i<(int)contacts.size(); i++){
    	if(!contacts[ind]){
    		cout << "There is no item called (" << contact.getName() << ")" << '\n';
    		return;
    	}
    	else if(contacts[ind]->getName() == contact.getName()){
    		delete contacts[ind] ;
    		contacts[ind] = deletedEntity ;
    		actual_length-- ;
    		return;
    	}
    	ind = (ind+1)%length ;
    }
	cout << "There is no item called " << contact.getName() << ")";

}

void LinearProbing::printall(){
	cout << "Hash Table :- "  << endl ;
	for(int i=0; i<length; i++){
		cout << i << " " ;
		if(!contacts[i])
			cout << "(Empty)" ;
		else if(contacts[i] == deletedEntity)
			cout << "(Deleted)" ;
		else
			contacts[i]->print() ;
		cout << '\n' ;
	}
}

void LinearProbing::getContact(entity &contact){
    int ind = contact.hash_upper_lower_digit(contact.getName(),65407)%length ;
	for(int i=0; i<(int)contacts.size(); i++){
		if(!contacts[ind]){
			cout << "There is no item called (" << contact.getName() << ")" << '\n';
			return;
		}
		else if(contacts[ind]->getName() == contact.getName()){
			contact = *contacts[ind] ;
			return;
		}
		ind = (ind+1)%length ;
	}
}




