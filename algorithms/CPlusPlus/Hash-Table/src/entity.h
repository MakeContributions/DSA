#ifndef PHONEENTRY_H
#define PHONEENTRY_H
#include <string>

using namespace std ;

class entity
{
private:
     const static int INTERNAL_LIMIT = 2147483647;
     string name ; // we'll be hash according to name
     int phoneNumber ;
public:
     entity() ;
     entity(string name_, int phoneNumber_) ;
     string getName() ;
     int getNumber() ;
     void setNameNumber(string name_, int number) ;
     int hash_lower() ; // use only lower case letter for hashing
     int hash_upper_lower_digit(string str, int num) ; // Hash according to name only
     void print() ;
     int folding_hash(string str) ;
     int hash_num(int num) ;
     int hash_multiple(string str, int num) ; // To hash according to name & phoneNumber
};

#endif // PHONEENTRY_H
