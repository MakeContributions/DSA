
#ifndef LINEARPROBING_H_
#define LINEARPROBING_H_

#include <vector>
#include "entity.h"
#include <iostream>

class LinearProbing {
private:
	vector<entity*> contacts ;
	int length ;
	int actual_length ;
	entity* deletedEntity ;

public:
	LinearProbing(int length);
	void add(entity contact) ;
	void remove(entity contact) ;
	void printall() ;
	void getContact(entity &contact) ;

};

#endif /* LINEARPROBING_H_ */
