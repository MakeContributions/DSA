#include <iostream>
#include "ArrayLinkedList.h"

using namespace std;

int main(){

    ArrayLinkedList arr(10) ; // zero index

    arr.set_value(2,20) ;
    arr.set_value(5,50) ;
    arr.set_value(9,90) ;
    arr.printNonZero() ; // 2 50 90
    arr.set_value(9,91) ;
    arr.printNonZero() ; // 2 50 91

    cout << arr.get_index(0) << endl ; // 0
    cout << arr.get_index(5) << endl ; // 50

    arr.printAll() ; // 0 0 20 0 0 50 0 0 0 91

    ArrayLinkedList arr2(10) ;
    arr2.set_value(2,20) ;
    arr2.set_value(5,50) ;
    arr2.set_value(8,90) ;

    arr.add(arr2) ; // 0 0 40 0 0 100 0 0 90 91

}



