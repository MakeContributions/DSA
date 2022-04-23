#include <iostream>
#include "LinearProbing.h"
#include "entity.h"
#include "hashTable.h"

using namespace std;

int main() {

	cout << "\nNormal Hash Table start :-\n" ;
	hashTable HT(8,0.5);
	HT.add(entity("FirstOne",1)) ;
	HT.add(entity("FirstOen",11)) ;
	HT.add(entity("SecondOne",2)) ;
	HT.add(entity("ThirdOne",3)) ;
	HT.add(entity("FourthOne",4)) ;
	HT.add(entity("FifthOne",5)) ;
	HT.printall() ;
	cout << '\n' ;

	HT.remove(entity("FirstOn",1)) ; // There is no item called (FirstOn)
	cout << '\n' ;

	HT.remove(entity("FirstOne",1)) ;
	HT.printall() ; // FirstOne entity will be deleted
	cout << '\n' ;

	entity element("FirstOen",-1) ;
	HT.getentity(element) ; // There is no item called (FirstOne)
	element.print() ;  // (Name: FirstOne ,Phone Number:-1)
	cout << '\n' ;

	entity element2("FirstOn",-1) ;
	HT.getentity(element2) ;  //  // There is no item called (FirstOn)
	element2.print() ;
	cout << '\n' ;

	cout << "\nEnd Normal Hash Table\n" ;

	cout << "\nStart Hash Table using Linear Probing :- \n" ;
	LinearProbing HTLinearProbing(8);
	HTLinearProbing.add(entity("FirstOne",1)) ;
	HTLinearProbing.add(entity("FirstOen",11)) ;
	HTLinearProbing.add(entity("SecondOne",2)) ;
	HTLinearProbing.add(entity("ThirdOne",3)) ;
	HTLinearProbing.add(entity("FourthOne",4)) ;
	HTLinearProbing.add(entity("FifthOne",5)) ;
	HTLinearProbing.printall() ;
	cout << '\n' ;

	HTLinearProbing.remove(entity("FirstOn",1)) ; // There is no item called (FirstOn)
	cout << '\n' ;

	HTLinearProbing.remove(entity("FirstOne",1)) ;
	HTLinearProbing.printall() ; // FirstOne entity will be deleted
	cout << '\n' ;

	entity elementLinearProbing("FirstOne",-1) ;
	HTLinearProbing.getContact(elementLinearProbing) ; // There is no item called (FirstOne)
	element.print() ;  // (Name: FirstOne ,Phone Number:-1)
	cout << '\n' ;

	entity elementLinearProbing2("FirstOn",-1) ;
	HTLinearProbing.getContact(elementLinearProbing2) ;  //  // There is no item called (FirstOn)
	element2.print() ;
	cout << '\n' ;

	cout << "\nEnd Hash Table using Linear Probing \n" ;


	cout << "\nStart using LinkedList :- \n" ;
	hashTable HTLinkedlist(8,0.75);
	HTLinkedlist.addLinkedlist(entity("LLFirstOne",1)) ;
	HTLinkedlist.addLinkedlist(entity("LLSecondOne",2)) ;
	HTLinkedlist.addLinkedlist(entity("LLThirdOne",3)) ;
	HTLinkedlist.addLinkedlist(entity("LLFourthOne",4)) ;
	HTLinkedlist.addLinkedlist(entity("LLFifthOne",5)) ;
	HTLinkedlist.printallLinkedlist() ;
	cout << "End using LinkedList \n\n" ;  // It's to print the same as the above test



	return 0;
}
