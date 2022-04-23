#include "entity.h"

#include <iostream>

using namespace std ;

entity::entity(){
	name = "" ;
	phoneNumber = -1 ;
}

entity::entity(string name_, int phoneNumber_){
     name = name_ ;
     phoneNumber = phoneNumber_ ;
}

int entity::hash_lower(){
     long long nn = INTERNAL_LIMIT ;
     long long sum = 0 ;
     for(int i=0; i < (int)name.size(); i++){
          sum = (sum*26 + name[i]-'a') % nn ;
     }
     return sum % nn ;
}

int entity::hash_upper_lower_digit(string str, int num){
	long long nn = INTERNAL_LIMIT ;
	long long sum = 0, temp = 0 ;
	int base = 26 + 26 + 10 ; // The first 26 for upperLetter, the second 26 for lowerLetter, the last 10 for digits(0:9)

	for(int i=0; i<(int)name.size(); i++){
		if(name[i] >= 'a' && name[i] <= 'z'){
			temp = name[i]-'a' ;
		}
		else if(name[i] >= 'A' && name[i] <= 'Z'){
			temp = 26 + name[i]-'A' ;
		}
		else if(name[i] >= '0' && name[i] <= '9'){
			temp = 26+26 + name[i]-'0' ;
		}
		sum = (base*sum+temp) % nn ;
	}

	return sum ;

}

int entity::folding_hash(string str){
	long long sum = 0, n_ = INTERNAL_LIMIT ;
	for(int i=0; i<(int)name.size(); i+=4){
		string ans = " " ;
		for(int j=0; j<4; j++){
			ans += name[j] ;
		}

		sum += hash_upper_lower_digit(ans,phoneNumber) ;
		sum %= n_ ;
	}
	return sum ;
}

int entity::hash_num(int num){
	long long n_ = INTERNAL_LIMIT ;
	return (num % n_ + n_) % n_ ;
}

int entity::hash_multiple(string str, int num){
	long long n_ = INTERNAL_LIMIT, sum = 0 ;
	sum += hash_upper_lower_digit(str,num) ;
	sum += hash_num(num) ;
	sum %= n_ ;

	return sum ;
}


void entity::print(){
     cout << "(Name: " << name << " " << ",Phone Number:" << phoneNumber << ")  " ;
}

string entity::getName(){
     return name ;
}

int entity::getNumber(){
     return phoneNumber ;
}


void entity::setNameNumber(string name_, int number_){
	name = name_ ;
	phoneNumber = number_ ;
}
