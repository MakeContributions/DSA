#include "entity.h"

#ifndef NODE_H_
#define NODE_H_

class Node {


public:

	entity data ;
	Node* next ;
	Node(entity data_) ;
};

#endif /* NODE_H_ */
