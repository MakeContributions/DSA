// Content: Use of Range algorithms
// Author: Pankaj Patil
// Date: Sat, 10th July 2023

/*  INCLUES    */
#include <iostream>
#include <algorithm>
#include <vector>
#include <ranges>
using namespace std;

/*  MAIN FUNCTION    */
int main() 
{
    cout << "Hello World" << endl;

    vector<int> v = {1, 2, 3, 3, 5, 6};
    auto it = ranges::adjacent_find(v);
    if (it != v.end()) {
        std::cout << *it << std::endl;
    }

    // std::vector<int> v = {1, 2, 3, 4, 5};
    // int value = 3;
    // auto it = std::ranges::binary_search(v, value);
    // if (it != v.end()) {
    //     std::cout << "Found " << value << " at index " << it - v.begin() << std::endl;
    // }



    return 1;
}

// Compile this code using : g++ -o tuple.exe testTuple.cpp
// Execute this code using : tuple.exe
