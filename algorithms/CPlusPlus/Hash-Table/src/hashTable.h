#ifndef PHONEHASHTABLE_H
#define PHONEHASHTABLE_H
#include <string>
#include <vector>
#include "entity.h"
#include "Node.h"

class hashTable
{
private:
     int length ;
     int actual_len ;
     double loadFactor ;
     vector< vector<entity> > contacts ;
     bool Is_removed(entity contact) ;
     vector<Node*> contactsOfLinkedlist ;

public:
     hashTable(int length_, double LIMIT_LOAD_FACTOR) ;
     void addLinkedlist(entity contact) ;
     void printallLinkedlist() ;
     void add(entity contact) ;
     void remove(entity contact) ;
     void getentity(entity &contact) ;
     void printall() ;
     void rehash() ;

};

#endif // PHONEHASHTABLE_H
