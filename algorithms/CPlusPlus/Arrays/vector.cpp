#include <iostream>
#include <cmath>
#include <cassert>
using namespace std ;

class Vector{

private:

	int *arr = nullptr ;
	int size , capacity ;

	void expand_capaxity(){

	     capacity *=5 ;
	     int *arr_expand = nullptr ;
	     arr_expand = new int [ capacity ]{} ;

	     for( int i = 0 ; i < size ; i++)
               arr_expand[i] = arr[i] ;

	     swap( arr , arr_expand ) ;

	     delete[] arr_expand ;
	}

public:

	Vector( int s):size(s){

		if( s < 0 )
			s = 1 ;

          capacity = 3000 ;

		arr = new int [ capacity ] {};
	}

	~Vector(){

		delete[] arr ;
		arr = nullptr ;

	}

	void set( int ind , int value ){
          // ind is a zero bassed
		assert(0 <= ind && ind < size);
		arr[ ind ] = value ;
	}

	int get_index( int ind ){

		assert( ind >= 0 && ind < size ) ;
		return arr[ ind ] ;
	}

	int get_back(){
		return arr[size - 1] ;
	}

	int get_front(){
		return arr[0] ;
	}

	void insertion_version_1( int ind , int value ){

	     int *arrins = new int[ size+1] ;
	     int *j = new int ;
	     int i = 0 ;
	     j = new int {i} ;

	     for( i =0 ; i < size+1 ; i++ ){


               if( i == ind ){
                    arrins[ ind ] = value ;

                    continue ;
               }

               arrins[i] = arr[(*j)++ ] ;

	     }
	     size++ ;

	     swap( arr , arrins) ;

	     delete[] arrins ;
	     delete j ;
	     j = nullptr ;
	     arrins = nullptr ;

	}

     void insertion_version_2( int ind , int value ){

          assert( ind >= 0 && ind < size ) ;

          if( size == capacity )
               expand_capaxity() ;

          for( int i = size - 1 ; i >= ind ; i--)
               arr[ i+1 ] = arr[ i ] ;

          arr[ ind ] = value ;
          size++ ;
     }

	int find(int value) {
		for (int i = 0; i < size; ++i)
			if (arr[i] == value)
				return i;
		return -1;	// -1 for NOT found
	}

	void push_Back( int value ){

		if( size == capacity )
               expand_capaxity() ;
          arr[ size++ ] = value ;

	}

     void print(){

          for( int i = 0 ; i < size ; i++)
               cout << arr[i] << " " ;
          cout << endl ;
     }

     void right_rotation(){

          int val = arr[ size - 1 ] ;

          for( int i = size -1 ; i > 0 ; i--)
               arr[ i ] = arr[ i-1 ] ;
          arr[ 0 ] = val ;

     }

     void left_rotation(){

          int val = arr[0] ;

          for( int i = 0 ; i < size-1 ; i++)
               arr[i] = arr[i+1] ;

          arr[size - 1] = val ;

     }

     void right_rotation_times( int times ){

          times %= size ;

          while( times-- ){

               right_rotation() ;
          }
     }

     void left_rotation_times( int times ){

          times %= size ;

          while( times-- ){

               left_rotation() ;
          }
     }

     int pop( int ind ){

          assert( ind >=0 && ind < size ) ;

          int value = arr[ ind ] ;

          for( int i = ind ; i < size - 1 ; i++)
               arr[ i ] = arr[ i+1 ] ;

          arr[ --size ] = 0 ;

          return value ;

     }


};


int main(){

	Vector v(1) ;

	v.set( 0 , 4) ;

	v.push_Back(6) ;

	v.insertion_version_1( 1 , 2 );
	v.insertion_version_2( 2 , 9 ) ;

	v.print() ; // 4 2 9 6

	v.right_rotation() ; // 6 4 2 9
	v.left_rotation() ; // 4 2 9 6
	v.right_rotation_times(2) ; // 9 6 4 2

	v.print() ;

	cout << "A deleted value is " << v.pop( 1 ) << endl ; // 6

	v.print() ; // 9 4 2

}

