// Content: Basic use of Tuple
// Author: Pankaj Patil
// Date: Sat, 8th July 2023

/*  INCLUES    */
#include <iostream>
#include <tuple>
using namespace std;

/*  FUNCTION DECLARATION    */
tuple <int, char, float> SetTuple(int a_iInt, char a_cChar, float a_fFloat);
void PrintTuple(tuple <int,char, float> a_tInputTuple);

/*  MAIN FUNCTION    */
int main() 
{
    cout << "Hello World" << endl;

    // Set tuple
    auto l_tReceivedValue = SetTuple(234, 'A', 1.23);

    // Print tuple
    PrintTuple(l_tReceivedValue);

    return 1;
}

/*  FUNCTION DEFINATION    */
tuple <int, char, float> SetTuple(int a_iInt, char a_cChar, float a_fFloat)
{
    auto g_tMyTuple = make_tuple(a_iInt,a_cChar,a_fFloat);
    return g_tMyTuple;
}

void PrintTuple(tuple <int,char, float> a_tInputTuple)
{
    cout << get<0>(a_tInputTuple) << endl;
    cout << get<1>(a_tInputTuple) << endl;
    cout << get<2>(a_tInputTuple) << endl;
}

// Compile this code using : g++ -o tuple.exe testTuple.cpp
// Execute this code using : tuple.exe
